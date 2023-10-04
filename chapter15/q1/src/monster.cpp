#include "monster.h"
#include "random.h"
#include <iostream>

Monster MonsterGenerator::generate() {
  return {static_cast<Monster::MonsterType>(
              Random::get(0, Monster::max_monster_type - 1)),
          getName(Random::get(0, 5)), getRoar(Random::get(0, 5)),
          Random::get(0, 100)};
}

std::string_view MonsterGenerator::getName(int x) {
  switch (x) {
  case 0:
    return "Blarg";
  case 1:
    return "Blarp";
  case 2:
    return "Slurp";
  case 3:
    return "Sneed";
  case 4:
    return "Feed";
  case 5:
    return "Dalle";
  default:
    return "";
  }
}
std::string_view MonsterGenerator::getRoar(int x) {
  switch (x) {
  case 0:
    return "RRRRR";
  case 1:
    return "SSSSSss";
  case 2:
    return "yeet";
  case 3:
    return "sneed";
  case 4:
    return "feed";
  case 5:
    return "jwz";
  default:
    return "";
  }
}

std::ostream &operator<<(std::ostream &os, const Monster::MonsterType mt) {
  switch (mt) {
  case Monster::dragon:
    return os << "dragon";
  case Monster::goblin:
    return os << "goblin";
  case Monster::ogre:
    return os << "ogre";
  case Monster::orc:
    return os << "orc";
  case Monster::skeleton:
    return os << "skeleton";
  case Monster::troll:
    return os << "troll";
  case Monster::vampire:
    return os << "vampire";
  case Monster::zombie:
    return os << "zombie";
  default:
    return os;
  }
}

void Monster::print() const {
  std::cout << m_name << " the " << m_type << " has " << m_hp
            << " hit points and says " << m_roar << "\n";
}
