#include <cmath>

class Complex {
 private:
  double real_;
  double imag_;

 public:
  // 3 балла
  Complex();
  Complex(double real, double imag);
  Complex(const Complex& other);
  ~Complex();

  Complex operator=(const Complex& other);

  // 3 балла
  Complex& operator+=(const Complex& other);
  Complex& operator*=(const Complex& other);

  friend Complex operator+(const Complex& left, const Complex& right);
  friend Complex operator*(const Complex& left, const Complex& right);

  friend bool operator==(const Complex& left, const Complex& right);
  friend bool operator!=(const Complex& left, const Complex& right);

  friend ostream& operator<<(ostream& out, const Complex& complex);

  // 3 балла
  double Real() const;
  double Imaginary() const;
  double Abs() const;
};

Complex Polar(double radius, double angle);