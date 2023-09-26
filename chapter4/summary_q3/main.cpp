#include "calc.h"
#include <iostream>
#include <string>
#include <string_view>

int main() {
  double x{getUserDouble()};
  double y{getUserDouble()};
  char op{getUserOp()};
  calcOp(x, y, op);
  return 0;
}
