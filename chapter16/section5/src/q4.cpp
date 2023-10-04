#include <iostream>
#include <vector>

template <typename T> auto findMax(const T &v) {
  auto res{v[0]};
  for (std::size_t i = 1; i < std::size(v); ++i) {
    if (v[i] > res) {
      res = v[i];
    }
  }
  return res;
}

int main() {
  std::vector testScore{84, 92, 76, 81, 56};
  std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92
  return 0;
}
