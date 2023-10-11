#pragma once

#include "direction.h"
#include <iostream>

struct Point {
public:
  int x{};
  int y{};
  Point(int x, int y) : x{x}, y{y} {};
  Point() = default;
  friend bool operator==(const Point &a, const Point &b) {
    return (a.x == b.x && a.y == b.y);
  }
  friend bool operator!=(const Point &a, const Point &b) { return !(a == b); }
  Point getAdjacentPoint(Direction dir) const {
    switch (dir.getType()) {
    case Direction::up:
      return {x, y - 1};
    case Direction::down:
      return {x, y + 1};
    case Direction::left:
      return {x - 1, y};
    case Direction::right:
      return {x + 1, y};
    default:
      return *this;
    }
  }
};
