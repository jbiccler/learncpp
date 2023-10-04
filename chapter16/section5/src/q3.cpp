#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

int getInput() {
  int i{};
  do {
    std::cout << "Input an integer value between 1 and 9 (inclusive)\n";
    std::cin >> i;

    if (!std::cin) {
      std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (i < 1 || i > 9);
  return i;
}

template <typename T> void printArray(const T &v) {
  for (auto x : v) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

template <typename T, typename U> int findIndex(const T &v, U val) {
  for (std::size_t i = 0; i < std::size(v); ++i) {
    if (v[i] == val) {
      std::cout << "The number " << val << " has index " << i << '\n';
      return static_cast<int>(i);
    }
  }
  std::cout << "The number " << val << " was not found.\n";
  return -1;
}

int main() {
  std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
  int input{getInput()};
  printArray(arr);
  findIndex(arr, input);

  return 0;
}
