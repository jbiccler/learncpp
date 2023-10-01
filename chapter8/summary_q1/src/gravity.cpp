#include "constants.h"
#include <algorithm>
#include <cmath>
#include <iostream>

double getUserInput() {
  double x{};
  std::cout << "Enter the height of the tower in meters: ";
  std::cin >> x;
  return x;
};
double distanceFallen(double startHeight, double sec) {
  return std::max(startHeight - constants::gravity * std::pow(sec, 2) / 2, 0.0);
};

void loopUpTo(double startHeight, int n) {
  for (int i = 0; i <= n; i++) {
    const double height{distanceFallen(startHeight, i)};
    if (height > 0.0) {
      std::cout << "At " << i << " seconds, the ball is at height: " << height
                << " meters\n";
    } else {
      std::cout << "At " << i << " seconds, the ball is on the ground.\n";
    }
  }
}
