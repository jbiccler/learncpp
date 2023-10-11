#include <iostream>

template <typename T> void print(T *begin, T *end) {
  for (; begin < end; ++begin) {
    std::cout << *begin;
  }
  std::cout << '\n';
}

void printCharArray(char arr[]) {
  while (*arr != '\0') {
    std::cout << *arr;
    ++arr;
  }
  std::cout << '\n';
}

void printCharArrayBackwards(char arr[]) {
  auto *ptr{arr};
  while (*ptr != '\0') {
    ++ptr;
  }
  while (ptr != arr) {
    std::cout << *ptr;
    --ptr;
  }
  std::cout << '\n';
}

int main() {

  char str[]{"Hello world!"};
  print(str, str + std::size(str) - 1);

  printCharArray(str);
  printCharArrayBackwards(str);

  return 0;
}
