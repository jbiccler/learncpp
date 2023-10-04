#include "point3d.h"
#include "vector3d.h"

void Point3d::moveByVector(const Vector3d &v) {
  m_x = v.m_x + m_x;
  m_y = v.m_y + m_y;
  m_z = v.m_z + m_z;
}
