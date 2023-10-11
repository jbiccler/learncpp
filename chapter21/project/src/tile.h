#pragma once
#include <iostream>
#include <ostream>

class Tile {
private:
  int m_val{0};

public:
  Tile(int val) : m_val{val} {};
  Tile() = default;
  bool isEmpty() const { return m_val == 0; }
  friend std::ostream &operator<<(std::ostream &os, Tile &t);
  int getNum() const { return m_val; }
};
