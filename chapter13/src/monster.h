#pragma once

#include <string_view>

enum class MonsterType {
  ogre,
  dragon,
  orc,
  spider,
  slime,
};

struct Monster {
  MonsterType type;
  std::string_view name{};
  int health{};
};

std::string_view getMonsterTypeString(const Monster &monster);
void printMonster(const Monster &monster);
