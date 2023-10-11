#include "player.h"
#include "potion.h"
#include <array>
#include <bits/utility.h>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

void shop() {

  std::cout << "Here is our selection for today: \n";
  for (std::size_t i = 0; i < Potion::max_potions; ++i) {
    std::cout << i << ") " << Potion::getPotionName(i) << " costs "
              << Potion::getPotionCost(i) << ".\n";
  }
}

std::string getPlayerName() {

  std::cout << "Enter your named: ";
  std::string name{};
  std::cin >> name;

  return name;
}

char getPlayerChoice() {
  std::cout << "Enter the number of potion you'd like to buy, or 'q' to quit: ";
  char choice{};
  std::cin >> choice;
  while (!std::cin ||
         (!(choice >= '0' &&
            choice < (static_cast<char>(Potion::max_potions) + '0')) &&
          choice != 'q')) {
    std::cin.clear();
    std::cout
        << "Enter the number of potion you'd like to buy, or 'q' to quit: ";
    std::cin >> choice;
  }
  return choice;
}

bool playRound(Player &player) {
  shop();
  // get choice of the player
  auto choice{getPlayerChoice()};
  if (choice == 'q') {
    return false;
  }
  if (std::isdigit(choice)) {
    if (player.purchase(
            static_cast<Potion::Type>(static_cast<int>(choice - '0')))) {
      std::cout << "Your purchased a potion of speed. You have "
                << player.getGold() << " gold left.\n";
    } else {
      std::cout << "You can not afford that.\n";
    }
    std ::cout << "\n";
    return true;
  }
  return false;
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\n";

  Player player{getPlayerName()};
  while (playRound(player)) {
  };

  std ::cout << "\n";
  player.printInventory();
  std::cout << "You escaped with " << player.getGold()
            << " gold remaining.\n\n";
  std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
  return 0;
}
