#include <array>
#include <bits/utility.h>
#include <cstddef>
#include <iostream>
#include <string_view>

struct Item {
  std::string_view name{};
  int gold{};
};

template <typename T, std::size_t N>
void printStore(const std::array<T, N> arr) {
  for (const auto &e : arr) {
    std::cout << "A " << e.name << " costs " << e.gold << " gold.\n";
  }
}

int main() {

  constexpr std::array<Item, 4> store{{
      {"sword", 5},
      {"dagger", 3},
      {"club", 2},
      {"spear", 7},
  }};

  printStore(store);

  return 0;
}
