#pragma once

#include <cmath>
#include <iostream>

class Point2d {
private:
  double m_x{};
  double m_y{};

public:
  Point2d() = default;
  Point2d(double x, double y) : m_x{x}, m_y{y} {};
  void print() { std::cout << "Point2d(" << m_x << ", " << m_y << ")\n"; };
  double distanceTo(const Point2d &other) {
    return std::sqrt(std::pow(m_x - other.m_x, 2) +
                     std::pow(m_y - other.m_y, 2));
  }
};
