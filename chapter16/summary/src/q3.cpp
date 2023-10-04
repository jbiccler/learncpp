#include <cassert>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> minMax(const std::vector<T> &v) {
  T min{v[0]};
  std::size_t min_indx{};
  T max{v[0]};
  std::size_t max_indx{};

  for (std::size_t i = 0; i < std::size(v); ++i) {
    auto e = v[i];
    if (e < min) {
      min = e;
      min_indx = i;
    } else if (e > max) {
      max = e;
      max_indx = i;
    }
  }
  return {min_indx, max_indx};
}

template <typename T> void printArray(const T &v) {
  std::cout << "With array (";
  for (const auto &e : v) {
    std::cout << ' ' << e << ',';
  }
  std::cout << " ):\n";
}

std::vector<int> getInput() {
  std::vector<int> res{};
  std::cout << "Enter numbers to add (use -1 to stop): ";
  int i{};
  while (true) {
    std::cin >> i;
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (i == -1) {
      break;
    }
    res.emplace_back(i);
  }
  return res;
}

template <typename T>
void printMinMax(const std::pair<std::size_t, std::size_t> &p,
                 const std::vector<T> &v) {

  std::cout << "The min element has index " << p.first << " and value "
            << v[p.first] << '\n';
  std::cout << "The max element has index " << p.second << " and value "
            << v[p.second] << '\n';
}

int main() {
  std::vector v1{3, 8, 2, 5, 7, 8, 3};

  auto mm1{minMax(v1)};
  printArray(v1);
  printMinMax(mm1, v1);

  std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
  auto mm2{minMax(v2)};
  printArray(v2);
  printMinMax(mm2, v2);

  auto v3{getInput()};
  if (v3.size() > 0) {
    auto mm3{minMax(v3)};
    printArray(v3);
    printMinMax(mm3, v3);
  }

  return 0;
}
