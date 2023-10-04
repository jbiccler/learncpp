#include "fraction.h"
#include <iostream>

Fraction getFraction() {
  int num{};
  int denom{};
  std::cout << "Enter a value for numerator: ";
  std::cin >> num;
  std::cout << "Enter a value for denominator: ";
  std::cin >> denom;
  std::cout << '\n';

  return Fraction{num, denom};
}
