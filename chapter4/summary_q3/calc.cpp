#include "calc.h"
#include <iostream>

double getUserDouble() {
  std::cout << "Enter a double value:\n";
  double x{};
  std::cin >> x;
  return x;
}
char getUserOp() {
  std::cout << "Enter one of the following: +, -, * or /: \n";
  char x{};
  std::cin >> x;
  return x;
}
void calcOp(double x, double y, char op) {
  switch (op) {
  case '*':
    std::cout << x << " " << op << " " << y << " is " << x * y;
    break;
  case '+':
    std::cout << x << " " << op << " " << y << " is " << x + y;
    break;
  case '-':
    std::cout << x << " " << op << " " << y << " is " << x * y;
    break;
  case '/':
    std::cout << x << " " << op << " " << y << " is " << x / y;
    break;
  default:
    std::cout << "invalid input\n";
    break;
  };
}
