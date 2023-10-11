#include <functional>
#include <iostream>
#include <utility>

std::pair<int, int> getInts() {
  std::cout << "Please enter two space separated integers: ";
  int x{};
  int y{};
  std::cin >> x >> y;
  return {x, y};
}

char getOperation() {
  std::cout << "Choose a mathematical operation from: +,-,*,/ ";
  char op{};
  std::cin >> op;
  while (op == '+' && op == '-' && op == '*' && op == '/') {
    std::cout << "Invalid choice, please choose from: +,-,*,/ ";
    std::cin >> op;
  }
  return op;
}

int add(int x, int y) { return x + y; }
int substract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

/* using ArithmeticFunction = int (*)(int, int); */
using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op) {
  switch (op) {
  case '+':
    return &add;
  case '-':
    return &substract;
  case '*':
    return &multiply;
  case '/':
    return &divide;
  }
  return nullptr;
}

int main() {
  auto xy{getInts()};
  auto op{getOperation()};
  auto func{getArithmeticFunction(op)};
  if (func) {
    std::cout << func(std::get<0>(xy), std::get<1>(xy)) << '\n';
  }

  return 0;
}
