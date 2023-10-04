#pragma once
#include <iostream>
#include <string>
#include <string_view>

class Monster {
public:
  enum MonsterType {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    max_monster_type,
  };

private:
  MonsterType m_type{};
  std::string m_name{};
  std::string m_roar{};
  int m_hp{};

public:
  Monster() = default;
  Monster(MonsterType t, std::string_view n, std::string_view r, int hp)
      : m_type{t}, m_name{n}, m_roar{r}, m_hp{hp} {};
  void print() const;
};

namespace MonsterGenerator {

Monster generate();
std::string_view getName(int x);
std::string_view getRoar(int x);

} // namespace MonsterGenerator
