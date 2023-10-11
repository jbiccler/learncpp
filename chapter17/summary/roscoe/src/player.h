#pragma once
#include "potion.h"
#include "random.h"
#include <array>
#include <cstddef>
#include <iostream>
#include <string_view>
#include <vector>

class Player {
private:
  std::string_view m_name{};
  std::array<std::size_t, Potion::max_potions> m_inventory{};
  int m_gold{};

public:
  Player(std::string_view name, int gold) : m_name{name}, m_gold{gold} {
    std::cout << "Hello, " << name << ", you have " << gold << " gold.\n";
  }
  Player(std::string_view name) : m_name{name}, m_gold{Random::get(0, 100)} {
    std::cout << "Hello, " << name << ", you have " << m_gold << " gold.\n";
  }
  int getGold() { return m_gold; }

  bool purchase(Potion::Type item) {
    if (m_gold >= Potion::potion_cost[item]) {
      m_gold -= Potion::potion_cost[item];
      m_inventory[item] += 1;
      return true;
    }
    return false;
  }

  void printInventory() {
    bool first{false};
    for (std::size_t i{0}; i < Potion::max_potions; ++i) {
      auto e{m_inventory[i]};
      if (e > 0) {
        if (!first) {
          std::cout << "Your inventory contains: \n";
          first = true;
        }
        std::cout << e << "x potion of " << Potion::getPotionName(i) << ".\n";
      }
    }
  }
};
