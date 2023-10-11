#pragma once
#include "random.h"
#include <cassert>
#include <iostream>

class Direction {
public:
  enum Type {
    up,
    down,
    left,
    right,
    max_directions,
  };

private:
  Type m_type{};

public:
  Direction(Type type) : m_type(type){};
  Type getType() { return m_type; };
  Direction operator-() const {
    switch (m_type) {
    case up:
      return down;
    case down:
      return up;
    case left:
      return right;
    case right:
      return left;
    default:
      assert(0 && "Invalid direction passed");
    }
  }
  static Direction getRandomDirection() {
    Type random{static_cast<Type>(Random::get(0, max_directions - 1))};
    return {random};
  }
  friend std::ostream &operator<<(std::ostream &os, Direction dir) {
    switch (dir.m_type) {
    case up:
      os << "up";
      break;
    case down:
      os << "down";
      break;
    case right:
      os << "right";
      break;
    case left:
      os << "left";
      break;
    default:
      assert(0 && "Unsupported direction");
    }
    return os;
  }
};
