#pragma once
#include <array>
#include <string_view>
namespace Potion {
enum Type {
  healing,
  mana,
  speed,
  invis,
  max_potions,
};
using namespace std::string_view_literals;
constexpr std::array potion_names{
    "healing"sv,
    "mana"sv,
    "speed"sv,
    "invisibility"sv,
};
constexpr std::array potion_cost{20, 30, 12, 50};
static_assert(std::size(potion_names) == max_potions);
static_assert(std::size(potion_cost) == max_potions);

template <typename T> std::string_view getPotionName(T i) {
  return Potion::potion_names[i];
}

template <typename T> int getPotionCost(T i) { return Potion::potion_cost[i]; }

} // namespace Potion
