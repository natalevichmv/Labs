#include <iostream>
using namespace std;

class Matrix {
public:
  Matrix() = delete;  // запретить конструктор по умолчанию
  Matrix(int rows, int columns);  // матрица нулей таких размеров
  Matrix(const Matrix& other);

  ~Matrix();
    
  Matrix& operator=(const Matrix& other);
  
  // operator[] или operator() - можно сделать или тот, или другой, на выбор, но
  // и тот, и другой оператор в двух вариантах: константный и неконстантный
  // Эти операторы делаются, чтобы обращаться к элементу матрицы по индексу столбца и строки, типа
  // matrix[0][0] = 1;  или
  // std::cout << matrix(0, 0) << std::endl;

  double* operator[](int index);  // может выбросить исключение
  const double* operator[](int index) const;  // может выбросить исключение

  double& operator()(int index1, int index2);  // может выбросить исключение
  const double& operator()(int index1, int index2) const;  // может выбросить исключение

  friend Matrix operator-(const Matrix& other);  // унарный оператор
    
  Matrix& operator+=(const Matrix& other);  // может выбросить исключение
  Matrix& operator-=(const Matrix& other);  // может выбросить исключение
  Matrix& operator*=(const Matrix& other);  // может выбросить исключение
  Matrix& operator*=(const double& number);
    
  friend bool operator==(const Matrix& left, const Matrix& right);
  friend bool operator!=(const Matrix& left, const Matrix& right);

  friend Matrix operator*(const double& number, const Matrix& matrix);
  friend Matrix operator*(const Matrix& matrix, const double& number);
    
  friend Matrix operator+(const Matrix& left, const Matrix& right);  // может выбросить исключение
  friend Matrix operator-(const Matrix& left, const Matrix& right);  // может выбросить исключение
  friend Matrix operator*(const Matrix& left, const Matrix& right);  // может выбросить исключение

  friend ostream& operator<<(ostream& out, const Matrix& matrix);

  int Rows() const;  // количество строк
  int Columns() const;  // количество столбцов
  Matrix Transpose() const;  // транспонированная матрица
  friend Matrix Identity(int size);  // единичная матрица
  // эту функцию можно вынести наружу и убрать слово friend
};

int main() {
  
}