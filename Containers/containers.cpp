//////////////////////////////////////////////////////////////
// Замечания:
// Интерфейсы и данные-члены можно изменить.
///////////////////////////////////////////////////////////////
#include <iostream>
//////////////////// Абстрактные классы ///////////////////////

// абстрактный базовый класс Итератор
class AbstractIterator
{
public:
    virtual ~AbstractIterator() {};
    virtual bool InRange() const = 0;       // индекс в допустимых пределах? 
    virtual void Reset() = 0;           // сбросить индекс в начало
    virtual int& operator *() const = 0;        // разыменование (чтение элемента)
    virtual void operator ++() = 0;         // сдвиг на элемент
};

// абстрактный базовый класс Контейнер
class AbstractContainer
{
public:
    virtual ~AbstractContainer() {};
    virtual bool IsEmpty() const = 0;       // контейнер пуст
    virtual bool IsFull() const = 0;       // контейнер полный
};

// абстрактный базовый класс Стек
class AbstractStack: public AbstractContainer
{
public:
    virtual void Push(const int& n) = 0;        // втолкнуть в стек
    virtual void Pop() = 0;          // вытолкнуть из стека
};

// абстрактный базовый класс Очередь
class AbstractQueue: public AbstractContainer
{
public:
    virtual void Push(const int& value) = 0;    // втолкнуть в очередь 
    virtual void Pop() = 0;           // удалить из очереди
};

//////////////////// Конкретные классы ///////////////////////////////
class StackIterator;        // предваряющее объявление
class QueueIterator;        // предваряющее объявление

// класс Стек на базе массива
class ArrayStack : public AbstractStack {
  protected:
    int* values_;      // указатель на массив
    int capacity_;   // размер массива
    int size_;    // сколько в стеке элементов

  public:
    ArrayStack() {
      values_ = NULL;
      capacity_ = 0;
      size_ = 0;
    }
    
    ArrayStack(ArrayStack &s) : capacity_(s.capacity_), size_(s.size_) {
      values_ = new int[capacity_];
      for (int i = 0; i < size_; ++i) {
         values_[i] = s.values_;
      }
    }
     
    ~ArrayStack() { 
      delete []values_; 
    }
    
    void Resize(int new_capacity) {
      if (capacity_ > new_capacity) { 
        throw std::logic_error("New capacity is smaller than actual capacity");
      }
      capacity_ = new_capacity;
      int* new_values = new int[capacity_];
      for (int i = 0; i < size_; ++i) {
        new_values_[i] = values_[i];
      }
      swap(new_values, values_);
      delete []new_values;
    }
    
    void Push(const int& value) {
      if (size_ >= capacity_) {
        if (capacity_ == 0) {
          Resize(1);
        } else {
          Resize(2 * capacity_);
        }     
      }
      ++size_;
      values_[size_ - 1] = value;
    }
    
    void Pop() {
      if (size_ == 0) {
        return;
      }
      --size_;
    }
    
    int Top() {
      if (size_ == 0) {
        throw std::logic_error("Stack is empty");
      }
      return values_[size_ - 1];
    }
    
    bool IsEmpty() const override {
      if (size_) {
        return false;
      }
      return true;
    } 
    
    bool IsFull() const override {
      return false;
    }
    
    int GetSize() {
      return size_;
    }
    
    friend class ArrayStackIterator;
};

// класс Итератор стека
class ArrayStackIterator: public AbstractIterator {
    ArrayStack  &a;         // ссылка на стек
    int pos;            // текущая позиция итератора
    ArrayStackIterator();
  public:
    ArrayStackIterator(const ArrayStack& _a);
    bool InRange() const;           // индекс в допустимых пределах
    void Reset();                   // сбросить индекс в начало
    int& operator *() const;        // разыменование (чтение элемента)
    void operator ++();             // сдвиг на элемент
};

// класс Кольцевая очередь
class ArrayQueue : public AbstractQueue {
protected:
	int capacity_;           // размерность массива
	int* values_;            // указатель на массив
	int head_;               // индекс первого свободного элемента
	int size_;               // количество элементов в очереди

public:
	ArrayQueue(int capacity = 16) : capacity_(capacity) {
		values_ = new int[capacity_];
		size_ = 0;
		head_ = 0;
	}

	ArrayQueue(ArrayQueue &other) : capacity_(other.capacity_), size_(other.size_), head_(other.head_) {
		values_ = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			values_[i] = other.values_[i];
		}
	}

	~ArrayQueue() {
		delete[] values_;
		size_ = 0;
		head_ = 0;
	}

	ArrayQueue& operator=(const ArrayQueue& right) {
		delete[] values_;
		capacity_ = right.capacity_;
		size_ = right.size_;
		head_ = right.head_;
		values_ = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			values_[i] = right.values_[i];
		}
		return *this;
	}

	void Push(const int& value) {
		if (IsFull()) {
			return;
		}
		else {
			values_[head_] = value;
			head_++;
			if (head_ >= capacity_) {
				head_ = 0;
			}
			size_++;
		}
	}

	int Front() const {
		if (IsEmpty()) {
			throw std::logic_error("Queue is empty");
		}
		int temp = head_ + capacity_ - size_;
		if (temp >= capacity_) {
			temp -= capacity_;
		}
		return values_[temp];
	}

	void Pop() {
		size_--;
	}

	bool IsEmpty() const {
		return !size_;
	}

	bool IsFull() const {
		if (capacity_ == size_) {
			return true;
		}
		else {
			return false;
		}
	}
	friend class QueueIterator;
};

// класс Итератор кольцевой очереди
class QueueIterator : public AbstractIterator {
    ArrayQueue &queue_;         // ссылка на очередь
    int pos_;            // текущая позиция итератора
  
  public:
    QueueIterator() = delete;
    explicit QueueIterator(ArrayQueue& queue) {
    }
  
    bool InRange() override;             // индекс в допустимых пределах
    void Reset() override;               // сбросить индекс в начало
    int& operator*() const override;        // разыменование (чтение элемента)
    void operator++() override;         // сдвиг на элемент
};

// класс стек на базе списка - определить самостоятельно
// итератор по этому стеку

