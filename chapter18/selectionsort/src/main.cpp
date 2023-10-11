#include <cstddef>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T> void selectionSort(T &v) {

  for (std::size_t i = 0; i < std::size(v) - 1; ++i) {
    std::size_t smallest_idx{i};
    auto smallest_val{v[i]};
    for (std::size_t j = i + 1; j < std::size(v); ++j) {
      if (v[j] < smallest_val) {
        smallest_idx = j;
        smallest_val = v[j];
      }
    }
    if (smallest_val < v[i]) {
      std::swap(v[smallest_idx], v[i]);
    }
  }
}

template <typename T> void bubbleSort(T &v) {
  if (std::size(v) <= 1) {
    return;
  }
  for (std::size_t i = std::size(v); i > 2; --i) {
    bool swapped{false};
    for (std::size_t j = 1; j < i; ++j) {
      if (v[j - 1] > v[j]) {
        swapped = true;
        std::swap(v[j - 1], v[j]);
      }
    }
    if (!swapped) {
      return;
    }
  }
}

template <typename T> void print(const T &v) {
  std::cout << "(";
  for (const auto &e : v) {
    std::cout << e << ", ";
  };
  std::cout << ")\n";
};

int main() {
  std::vector v1{
      30, 50, 20, 10, 40,
  };

  print(v1);
  selectionSort(v1);
  print(v1);

  std::vector v2{
      30, 50, 20, 10, 40,
  };

  print(v2);
  bubbleSort(v2);
  print(v2);

  return 0;
}
