#pragma once
#include <iostream>
#include <string>

namespace comp_pair {
class Pair {
 private:
 protected:
  double x;
  double y;

 public:
  Pair();
  Pair(const double&, const double&);
  Pair(const Pair&);

  // std::string to_string() const;

  friend std::ostream& operator<<(std::ostream&, const Pair&);
  Pair& operator=(const Pair&);
  Pair operator+(const Pair&);
  Pair operator-(const Pair&);
  Pair operator*(const double&);
  friend Pair operator*(const double&, const Pair&);
};

class Complex : public Pair {
 public:
  Complex() : Pair() {}
  Complex(const double&, const double&);
  // Complex(const Pair&); ???
  Complex(const Complex&);

  friend std::ostream& operator<<(std::ostream&, const Complex&);

  double norm_squared() const;

  Complex& operator=(const Complex&);

  Complex operator+(const Complex&);

  Complex operator-(const Complex&);

  Complex operator*(const Complex&);
  Complex operator*(const double& mult);
  friend Complex operator*(const double&, const Complex&);
  Complex operator/(const Complex&);
};
}  // namespace comp_pair