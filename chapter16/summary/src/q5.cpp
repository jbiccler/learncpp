#include "random.h"
#include <array>
#include <cctype>
#include <cstddef>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

using namespace std::literals::string_view_literals;
namespace WordList {
std::vector words{
    "mystery"sv, "broccoli"sv,  "account"sv,  "almost"sv,  "spaghetti"sv,
    "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv,
};
std::string_view getRandomWord(const std::vector<std::string_view> &v) {
  std::size_t r{Random::get(static_cast<std::size_t>(0), std::size(v))};
  return v[r];
}
}; // namespace WordList

char getLetter() {
  std::cout << "Enter your next letter: \n";
  char answer{};
  std::cin >> answer;
  while (!std::cin || !std::isalpha(answer)) {
    std::cout << "That wasn't a valid input. Try again.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> answer;
  }
  return answer;
}

class Session {
private:
  std::string_view m_word{};
  std::string m_hidden{};
  std::vector<char> m_guessed{};
  std::size_t m_n{};

public:
  Session(std::string_view word, std::size_t n) : m_word{word}, m_n{n} {
    m_hidden.append(word.size(), '_');
  }
  void printState() {
    std::cout << "The word: " << m_hidden << "\tWrong guesses: ";
    for (std::size_t i = 0; i < m_n; i++) {
      std::cout << '+';
    }
    for (const auto &e : m_guessed) {
      std::cout << e;
    }
    std::cout << '\n';
  }
  bool checkLetterGuessed(char c) {
    // check if guessed already
    for (const auto e : m_guessed) {
      if (c == e) {
        return false;
      }
    }
    return true;
  }
  void addLetterGuessed(char c) { m_guessed.emplace_back(c); }
  bool checkLetterWord(char c) {
    bool res{false};
    for (std::size_t i = 0; i < m_word.size(); ++i) {
      if (c == m_word[i]) {
        res = true;
        m_hidden[i] = c;
      }
    }
    return res;
  }
  bool checkWord() {
    std::size_t sum{};
    for (auto e : m_hidden) {
      if (e != '_') {
        sum += 1;
      }
    }
    return sum == std::size(m_word);
  }
  int playRound() {
    // returns -1 if player ran out of guesses
    // 0 if next round is possible
    // 1 if player won
    if (m_n == 0) {
      return -1;
    }
    printState();
    char letter{};
    do {
      letter = getLetter();
    } while (!checkLetterGuessed(letter));
    if (!checkLetterWord(letter)) {
      m_n -= 1;
      addLetterGuessed(letter);
    }
    if (checkWord()) {
      return 1;
    } else if (m_n == 0) {
      return -1;
    } else {
      return 0;
    }
  };
  std::string_view getWord() { return m_word; }
};

int main() {
  std::cout << "Welcome to C++man (a variant of Hangman) \nTo win: guess the "
               "word.\tTo lose: run out of plusses.\n";

  auto word = WordList::getRandomWord(WordList::words);
  // debugging
  std::cout << "The word is: " << word << '\n';
  Session session{word, 6};
  auto played = session.playRound();
  while (played == 0) {
    // play a round
    played = session.playRound();
  }
  if (played == 1) {
    std::cout << "You won!\tThe word was: " << word << '\n';
  } else if (played == -1) {
    std::cout << "You lost!\tThe word was: " << word << '\n';
  }
  return 0;
}
