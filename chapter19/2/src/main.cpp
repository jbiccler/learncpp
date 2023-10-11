#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>

void handleInput(std::string *ptr, std::size_t n) {
  for (std::size_t i{0}; i < n; ++i) {
    std::cout << "Enter name #" << i + 1 << ":";
    std::getline(std::cin >> std::ws, ptr[i]);
  }
}

int main() {

  std::cout << "How many names would you like to enter? ";
  std::size_t n{};
  std::cin >> n;

  std::string *ptr{new std::string[n]};
  handleInput(ptr, n);

  std::sort(ptr, ptr + n);
  std::cout << "Here is your sorted list: \n";

  for (std::size_t i{0}; i < n; ++i) {
    std::cout << "Name #" << i + 1 << ":";
    std::cout << *(ptr + i) << "\n";
  }
  std::cout << std::endl;

  delete[] ptr;
  ptr = nullptr;
  return 0;
}
