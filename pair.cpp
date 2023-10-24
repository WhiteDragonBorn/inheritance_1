#include "pair.h"

using namespace comp_pair;

Pair::Pair() {
  x = 0;
  y = 0;
}

Pair::Pair(const double& x_, const double& y_) {
  x = x_;
  y = y_;
}

Pair::Pair(const Pair& obj) {
  x = obj.x;
  y = obj.y;
}

// std::string Pair::to_string() const {
//   std::string toReturn;
//   toReturn += "(" + std::to_string(x) + " , " + std::to_string(y) + ")";
//   return toReturn;
// }

std::ostream& comp_pair::operator<<(std::ostream& os, const Pair& obj) {
  std::string toReturn;
  toReturn += "(" + std::to_string(obj.x) + " , " + std::to_string(obj.y) + ")";
  os << toReturn;
  return os;
}

Pair& Pair::operator=(const Pair& obj) {
  if (this == &obj) return *this;
  x = obj.x;
  y = obj.y;
  return *this;
}

Pair Pair::operator+(const Pair& obj) { return Pair(x + obj.x, y + obj.y); }

Pair Pair::operator-(const Pair& obj) { return Pair(x - obj.x, y - obj.y); }

Pair Pair::operator*(const double& mult) { return Pair(x * mult, y * mult); }

Pair comp_pair::operator*(const double& mult, const Pair& obj) {
  return Pair(obj.x * mult, obj.y * mult);
}

// ------

Complex::Complex(const double& x_, const double& y_) : Pair(x_, y_) {}

Complex::Complex(const Complex& obj) : Pair(obj) {}

// Complex::Complex(const Pair& obj) : Pair(obj) {} ???

double Complex::norm_squared() const { return x * x + y * y; }

std::ostream& comp_pair::operator<<(std::ostream& os, const Complex& obj) {
  std::string toReturn;
  toReturn += '(' + std::to_string(obj.x) + ')' + "+" + '(' +
              std::to_string(obj.y) + ')' + 'i';
  os << toReturn;
  return os;
}

Complex& Complex::operator=(const Complex& obj) {
  if (this == &obj) {
    return *this;
  }

  Pair::operator=(obj);

  return *this;
}

Complex Complex::operator+(const Complex& obj) {
  Pair temp_1(*this);
  Pair temp_2(obj);

  temp_1 = temp_1 + temp_2;

  Complex* toReturn = (Complex*)&temp_1;

  return *toReturn;  // ≈сли бы были дополнительные пол€ у класса Complex?

  // Pair* ptr = this;
  // const Pair* temp = &obj;
  // return Complex(*(ptr) + *(temp));
}

Complex Complex::operator-(const Complex& obj) {
  Pair temp_1(*this);
  Pair temp_2(obj);

  temp_1 = temp_1 - temp_2;

  Complex* toReturn = (Complex*)&temp_1;

  return *toReturn;  // ≈сли бы были дополнительные пол€ у класса Complex?

  // Pair* ptr = this;
  // const Pair* temp = &obj;
  // return Complex(*(ptr) - *(temp));
}

Complex Complex::operator*(const Complex& obj) {
  return Complex(x * obj.x - y * obj.y, x * obj.y + y * obj.x);
}

Complex Complex::operator*(const double& mult) {
  Pair temp_1(*this);

  temp_1 = temp_1 * mult;

  Complex* toReturn = (Complex*)&temp_1;

  return *toReturn;  // ≈сли бы были дополнительные пол€ у класса Complex?
}

Complex comp_pair::operator*(const double& mult, const Complex& obj) {
  Pair temp_1(obj);

  temp_1 = temp_1 * mult;

  Complex* toReturn = (Complex*)&temp_1;

  return *toReturn;  // ≈сли бы были дополнительные пол€ у класса Complex?
}

Complex Complex::operator/(const Complex& obj) {
  return Complex((x * obj.x + y * obj.y) / obj.norm_squared(),
                 (y * obj.x - x * obj.y) / obj.norm_squared());
}
