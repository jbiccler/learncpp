#include "tile.h"
#include <iostream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, Tile &t) {
  os << '\t';
  if (t.isEmpty()) {
    os << "    ";

  } else if (t.getNum() > 9) {
    os << " " << t.getNum() << " ";
  } else {
    os << "  " << t.getNum() << " ";
  }
  return os;
}
