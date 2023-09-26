#include "io.h"
#include <iostream>

int readNumber() {
  std::cout << "Enter a number :\n";
  int x{};
  std::cin >> x;
  return x;
};
void writeAnswer(int x) { std::cout << "You entered: " << x << "\n"; }
