#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <sstream>

void fizzbuzz(int n) {
  constexpr std::array divs{3, 5, 7, 11, 13, 17, 19};
  constexpr std::array words{"fizz", "buzz", "pop", "bang",
                             "jazz", "pow",  "boom"};

  static_assert(std::size(divs) == std::size(words) &&
                " length of divs and words doesn't match");

  const std::size_t length{std::size(divs)};
  std::stringstream ss{};

  for (auto j = 0; j < n; ++j) {
    bool empty = true;
    for (std::size_t i = 0; i < length; ++i) {
      if (j % divs[i] == 0) {
        ss << words[i];
        empty = false;
      }
    }
    if (empty) {
      ss << j;
    }
    ss << '\n';
  }
  std::cout << ss.str();
}

int main() {
  fizzbuzz(150);
  return 0;
}
