#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>

class IntArray {
private:
  int *m_arr{};
  std::size_t m_n{};

public:
  IntArray(std::size_t n) : m_n{n} { m_arr = new int[n]; };
  ~IntArray() {
    delete[] m_arr;
    m_arr = nullptr;
  }
  int &operator[](const std::size_t i) {
    assert(i < m_n);
    return m_arr[i];
  }
  friend std::ostream &operator<<(std::ostream &os, IntArray &arr);

  IntArray(const IntArray &arr) : m_n{arr.m_n} {
    m_arr = new int[m_n];
    for (std::size_t i{0}; i < m_n; ++i) {
      m_arr[i] = arr.m_arr[i];
    }
  }
  IntArray &operator=(const IntArray &arr) {
    if (this == &arr) {
      return *this;
    }
    if (m_n != arr.m_n) {
      delete[] m_arr;
      m_n = arr.m_n;
      m_arr = new int[m_n];
    }
    for (std::size_t i{0}; i < m_n; ++i) {
      m_arr[i] = arr.m_arr[i];
    }
    return *this;
  }
};

std::ostream &operator<<(std::ostream &os, IntArray &arr) {
  if (arr.m_n == 0) {
    return os;
  }
  bool first{true};
  for (std::size_t i = 0; i < arr.m_n; ++i) {
    if (first) {
      os << arr.m_arr[i];
      first = false;
    } else {
      os << ' ' << arr.m_arr[i];
    }
  }
  return os;
}

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto &ref{
      a}; // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}
