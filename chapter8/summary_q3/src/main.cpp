#include "random.h"
#include <iostream>

int getGuess() {
  int x{};
  std::cin >> x;
  return x;
}

bool playAgain() {
  std::cout << "Would you like to play again (y/n)?\n";
  char answer{};
  std::cin >> answer;
  if (answer == 'y') {
    return true;
  } else {
    return false;
  }
}

bool playRound() {
  std::cout << "Let's play a game. Guess a number between 1 and 100. You have "
               "7 tries.\n";
  int answer{Random::get(1, 100)};
  std::cout << "DEBUGGING answer: " << answer << "\n";
  for (int i = 0; i < 7; ++i) {
    std::cout << "Guess #" << i + 1 << ": ";
    int guess = getGuess();
    if (answer == guess) {
      std::cout << "Correct! You win!\n";
      return true;
    }
  }
  std::cout << "Sorry, you lose. The correct number was " << answer
            << std::endl;
  return false;
};

int main() {
  bool play{true};
  while (play) {
    playRound();
    play = playAgain();
  }
  return 0;
}
