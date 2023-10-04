#include "fraction.h"
#include "point.h"
#include <iostream>

int main() {
  Point2d first{};
  Point2d second{3.0, 4.0};

  first.print();
  second.print();

  std::cout << "distance between two points: " << first.distanceTo(second)
            << std::endl;

  Fraction f1{getFraction()};
  Fraction f2{getFraction()};

  std::cout << "Your fractions multiplied together: ";

  f1.multiply(f2).printFraction();

  return 0;
}
