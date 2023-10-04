
#pragma once
#include "point3d.h"
#include <iostream>

class Vector3d {
private:
  double m_x{};
  double m_y{};
  double m_z{};

public:
  /* friend class Point3d; */
  Vector3d(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

  void print() const {
    std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
  }
  friend void Point3d::moveByVector(const Vector3d &v);
};
