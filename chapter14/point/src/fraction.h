#pragma once
#include <iostream>

class Fraction {
private:
  int m_numerator{};
  int m_denominator{};

public:
  Fraction() = default;
  explicit Fraction(int num = 0, int denom = 1)
      : m_numerator{num}, m_denominator{denom} {};

  // copy
  Fraction(const Fraction &other) = default;

  void printFraction() const {
    std::cout << m_numerator << "/" << m_denominator << "\n";
  };
  Fraction multiply(const Fraction &other) const {
    return Fraction{
        m_numerator * other.m_numerator,
        m_denominator * other.m_denominator,
    };
  };
};

Fraction getFraction();
