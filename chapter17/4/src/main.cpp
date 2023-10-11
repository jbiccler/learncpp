#include <array>
#include <cstddef>
#include <iostream>
#include <string_view>

struct Student {
  int id{};
  std::string_view name{};
};

template <typename T, std::size_t N>
const Student *findStudentById(const std::array<T, N> &arr, int id) {
  for (auto &e : arr) {
    if (e.id == id) {
      return &e;
    }
  }
  return nullptr;
}

int main() {
  constexpr std::array<Student, 3> students{{
      {0, "Alex"},
      {1, "Joe"},
      {2, "Bob"},
  }};
  constexpr std::string_view nobody{"nobody"};
  const auto s1{findStudentById(students, 1)};
  const auto s2{findStudentById(students, 3)};

  std::cout << "You found: " << (s1 ? s1->name : nobody) << '\n';
  std::cout << "You found: " << (s2 ? s2->name : nobody) << '\n';

  return 0;
}
