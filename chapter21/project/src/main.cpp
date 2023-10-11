#include "board.h"
#include "direction.h"
#include "point.h"
#include "tile.h"
#include <iostream>

namespace UserInput {

char getInput() {
  std::cout << "Please choose between: w,a,s,d,q: ";
  char out{};
  std::cin >> out;
  while (!std::cin ||
         (out != 'w' && out != 'a' && out != 's' && out != 'd' && out != 'q')) {
    std::cout << "Please enter valid input: ";
    std::cin >> out;
  };
  std::cout << "Valid command: " << out << '\n';
  return out;
}
Direction charToDirection(char ch) {

  switch (ch) {
  case 'w':
    return {Direction::up};
  case 's':
    return {Direction::down};
  case 'd':
    return {Direction::right};
  case 'a':
    return {Direction::left};
  default:
    assert(0 && "Unsupported direction");
  }
}
} // namespace UserInput

int main() {
  Board board{};
  std::cout << board;

  for (int i{0}; i < 1000; ++i) {
    Direction rand{Direction::getRandomDirection()};
    /* std::cout << "Generating random direction... " << rand << '\n'; */
    board.moveTile(rand);
  }
  std::cout << board;

  std::cout << "Enter a command: ";
  while (true) {
    char ch{UserInput::getInput()};
    // Handle non-direction commands
    if (ch == 'q') {
      std::cout << "\n\nBye!\n\n";
      return 0;
    }

    // Handle direction commands
    Direction dir{UserInput::charToDirection(ch)};

    std::cout << "You entered direction: " << dir << '\n';

    if (board.moveTile(dir)) {
      std::cout << board;
    }
    if (board.winCondition()) {
      std::cout << board;
      std::cout << "Congrats You finished the game\n";
      break;
    }
  }

  return 0;
}
