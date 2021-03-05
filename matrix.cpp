#include <iostream>
using namespace std;

class Matrix {
public:
  Matrix() = delete;  // запретить конструктор по умолчанию
  Matrix(int rows, int columns);  // матрица нулей таких размеров
  Matrix(const Matrix& other);

  ~Matrix();
    
  Matrix& operator=(const Matrix& other);
  
  friend Matrix operator-(const Matrix& other);  // унарный оператор
    
  Matrix& operator+=(const Matrix& other);  // может выбросить исключение
  Matrix& operator-=(const Matrix& other);  // может выбросить исключение
  Matrix& operator*=(const Matrix& other);  // может выбросить исключение
  Matrix& operator*=(const double& number);
    
  friend bool operator==(const Matrix& left, const Matrix& right);
  friend bool operator!=(const Matrix& left, const Matrix& right);

  friend Matrix operator*(const double& number, const Matrix& matrix);
  friend Matrix operator*(const Matrix& matrix, const double& number);
    
  friend Matrix operator+(const Matrix& left, const Matrix& right);  // могут выбросить исключение 
  friend Matrix operator-(const Matrix& left, const Matrix& right);  // могут выбросить исключение 
  friend Matrix operator*(const Matrix& left, const Matrix& right);  // могут выбросить исключение 

  friend ostream& operator<<(ostream& out, const Matrix& matrix);

  double* operator[](int index);  // может выбросить исключение
  const double* operator[](int index) const;  // может выбросить исключение

  int Rows() const;
  int Columns() const;
  Matrix Transpose() const;
  friend Matrix Identity(int size);
};

int main() {
  
}