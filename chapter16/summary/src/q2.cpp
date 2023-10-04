#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

namespace Items {

enum Type : std::size_t {
  potion,
  torch,
  arrow,
  max_number_items,
};
}

template <typename T> int sum(const T &v) {
  int sum{};
  for (const auto &e : v) {
    sum += e;
  }
  return sum;
}

std::string_view itemTypeString(std::size_t i, int n) {
  using namespace std::literals::string_view_literals;
  if (n <= 1) {
    switch (i) {
    case Items::potion:
      return "health potion"sv;
    case Items::torch:
      return "torch"sv;
    case Items::arrow:
      return "arrow"sv;
    }
  } else {
    switch (i) {
    case Items::potion:
      return "health potions"sv;
    case Items::torch:
      return "torches"sv;
    case Items::arrow:
      return "arrows"sv;
    }
  }
  return ""sv;
}

template <typename T> void printItems(const std::vector<T> &v) {
  if (v.size() != Items::max_number_items) {
    return;
  }
  for (std::size_t i = 0; i < std::size(v); ++i) {
    std::cout << "You have " << v[i] << " " << itemTypeString(i, v[i]) << ".\n";
  }
}

int main() {
  std::vector items{1, 5, 10};
  assert(items.size() == Items::max_number_items);

  printItems(items);
  std::cout << "You have " << sum(items) << " total items.\n";

  return 0;
};
