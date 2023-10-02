#include "monster.h"
#include "triad.h"
#include <iostream>

std::string_view getMonsterTypeString(const Monster &monster) {
  using enum MonsterType;
  switch (monster.type) {
  case ogre:
    return "Ogre";
  case dragon:
    return "Dragon";
  case orc:
    return "Orc";
  case spider:
    return "Spider";
  case slime:
    return "Slime";
  default:
    return "???";
  }
}

std::ostream &operator<<(std::ostream &os, const Monster &monster) {
  os << "This " << getMonsterTypeString(monster) << " is named " << monster.name
     << " and has " << monster.health << " health.\n";
  return os;
}

void printMonster(const Monster &monster) { std::cout << monster; }

int main() {
  Monster ogre{MonsterType::ogre, "Torg", 145};
  Monster slime{MonsterType::slime, "Blurp", 23};

  printMonster(ogre);
  printMonster(slime);

  Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
  print(t1);

  Triad t2{1.2, 3.4, 5.6}; // note: uses CTAD to deduce template arguments
  print(t2);

  return 0;
}
