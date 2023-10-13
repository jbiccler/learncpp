#include "random.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>

class Potion {
public:
  enum class Type {
    health1,
    health2,
    health3,
    strength1,
    poison1,
    max_potion_types
  };
  Type m_type{};
  std::array<int32_t, 2> m_val{};

private:
  static const std::array<int32_t, 2> searchValue(Potion::Type type) {
    static const std::array<std::array<int32_t, 2>,
                            static_cast<std::size_t>(Type::max_potion_types)>
        potionData{{
            {2, 0},
            {2, 0},
            {5, 0},
            {0, 1},
            {-1, 0},
        }};
    return potionData.at(static_cast<std::size_t>(type));
  };

public:
  Potion(Type t) : m_type{t}, m_val{searchValue(t)} {};
  static Potion getRandomPotion() {
    int32_t t{Random::get(0, static_cast<int32_t>(Type::max_potion_types) - 1)};
    return {static_cast<Type>(t)};
  };
  auto getValue() { return m_val; };
};

class Creature {
protected:
  std::string name{};
  char symbol{};
  int32_t health{};
  int32_t damage{};
  int32_t gold{};

public:
  Creature() = default;
  Creature(std::string_view name, char symbol, int32_t health, int32_t damage,
           int32_t gold)
      : name{name}, symbol{symbol}, health{health}, damage{damage},
        gold{gold} {};
  void setName(std::string_view name) { this->name = name; };
  void setSymbol(char symbol) { this->symbol = symbol; };
  void setHealth(int health) { this->health = health; };
  void setDamage(int damage) { this->damage = damage; };
  void setGold(int gold) { this->gold = gold; };

  std::string_view getName() const { return name; };
  char getSymbol() const { return symbol; };
  int getHealth() const { return health; };
  int getDamage() const { return damage; };
  int getGold() const { return gold; };

  void reduceHealth(int d) { health -= d; };
  bool isDead() const { return health <= 0; };
  void addGold(int g) { gold += g; };
};

class Player : public Creature {
private:
  int32_t level{1};

public:
  Player(std::string_view name) : Creature(name, '@', 20, 1, 0){};
  void levelUp() {
    level += 1;
    damage += 1;
  }
  int32_t getLevel() { return level; };
  bool hasWon() { return level >= 20; };
  void printStatus() {
    std::cout << name << "(hp: " << health << ", damage: " << damage
              << ", gold: " << gold << ", level: " << level << ")\n";
  }
  void drinkPotion(Potion &p) {
    auto h{p.getValue().at(0)};
    auto d{p.getValue().at(1)};
    std::cout << "Potion(health: " << h << ", damage: " << d << ")\n";
    health += h;
    damage += d;
    std::cout << "After drinking the potion your player stats are: \n";
  }
};

class Monster : public Creature {
public:
  enum Type {
    DRAGON,
    ORC,
    SLIME,
    max_types,
  };

private:
  // As a private member of Monster
  static const Creature &getDefaultCreature(Type type) {
    static const std::array<Creature, static_cast<std::size_t>(Type::max_types)>
        monsterData{{{"dragon", 'D', 20, 4, 100},
                     {"orc", 'o', 4, 2, 25},
                     {"slime", 's', 1, 1, 10}}};

    return monsterData.at(static_cast<std::size_t>(type));
  }

public:
  Monster(Monster::Type t) : Creature{getDefaultCreature(t)} {};
  static Monster getRandomMonster() {
    return {static_cast<Monster::Type>(Random::get(0, max_types - 1))};
  }
  friend std::ostream &operator<<(std::ostream &os, Monster &m) {
    os << m.getName() << " (hp: " << m.getHealth()
       << ", damage: " << m.getDamage() << ")";
    return os;
  }
};

;

class Session {
private:
  Player &player;
  Monster monster;

  void attackMonster() {
    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for "
              << player.getDamage() << " damage.\n";
  };

  void attackPlayer() {
    player.reduceHealth(monster.getDamage());

    std::cout << "The " << monster.getName() << " hit you for "
              << monster.getDamage() << " damage.\n";
    std::cout << "You have " << std::max(player.getHealth(), 0)
              << " hp remaining.\n";
  };

  void checkPotion() {
    auto r{Random::get(1, 10)};
    if (r <= 3) {
      // potion found
      auto potion{Potion::getRandomPotion()};
      std::cout
          << "You found a mythical potion! Do you want to drink it? [y/n]:";
      char choice{};
      std::cin >> choice;
      while (!std::cin || (choice != 'y' && choice != 'n')) {
        std::cin >> choice;
      }
      if (choice == 'y') {
        player.drinkPotion(potion);
      }
    }
  }

public:
  Session(Player &player)
      : player{player}, monster{Monster::getRandomMonster()} {};
  bool winCondition() { return !player.isDead() && player.getLevel() >= 20; }
  bool fightMonster() {
    std::cout << "You have encountered: " << monster << ".\n";
    std::cout << "(R)un of (F)ight: ";
    char choice{};
    std::cin >> choice;
    while (!std::cin ||
           (choice != 'R' && choice != 'r' && choice != 'F' && choice != 'f')) {
      std::cout << "(R)un of (F)ight: ";
      std::cin >> choice;
    };
    if (choice == 'R' || choice == 'r') {
      // flee
      bool success{static_cast<bool>(Random::get(0, 1))};
      if (success) {
        std::cout << "You successfully fled.\n";
      }
      if (!success) {
        std::cout << "You failed to flee.\n";
        // monster attacks while fleeing
        attackPlayer();
      }
      // set new monster
      monster = Monster::getRandomMonster();
    } else {
      while (!player.isDead() && !monster.isDead()) {
        // fight
        attackMonster();
        if (!monster.isDead()) {
          std::cout << "The " << monster.getName() << " has "
                    << monster.getHealth() << " hp remaining.\n";
          attackPlayer();
        }
      }
      if (monster.isDead()) {
        std::cout << "You successfully killed the " << monster.getName()
                  << ".\n";
        player.addGold(monster.getGold());
        // monster died so set new next monster
        monster = Monster::getRandomMonster();
        // update player stats
        player.levelUp();

        checkPotion();
      }
    }
    return !player.isDead();
  }
};

int main() {
  std::cout << "Enter your name: ";
  std::string playerName;
  std::cin >> playerName;

  Player player{playerName};
  std::cout << "Welcome " << playerName << ", let's play a game!\n";
  player.printStatus();
  Session session{player};
  while (session.fightMonster() && !session.winCondition()) {
    player.printStatus();
  }

  if (player.isDead()) {
    std::cout << "You died at level " << player.getLevel() << " and with "
              << player.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  } else {
    std::cout << "Congratulations, you won the game! \n";
    std::cout << "Your final player stats are: \n";
    player.printStatus();
    std::cout << "You get to take " << player.getGold() << " gold home!\n";
  }

  return 0;
}
