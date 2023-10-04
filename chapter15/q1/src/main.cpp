#include "monster.h"
#include <iostream>

int main() {

  Monster m{MonsterGenerator::generate()};
  m.print();
  return 0;
}
