#pragma once
#include <iostream>
template <typename T> struct Triad {
  T a{};
  T b{};
  T c{};
};

template <typename T> void print(Triad<T> t) {
  std::cout << "[" << t.a << ", " << t.b << ", " << t.c << "]\n";
}

// deduction type, not strictly needed here bc c++20
template <typename T> Triad(T, T, T) -> Triad<T>;
