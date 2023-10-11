#include <array>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <sys/types.h>

namespace Animal {
enum Type {
  chicken,
  dog,
  cat,
  elephant,
  duck,
  snake,
  max_number_animals,
};

struct Data {
  std::string_view name{};
  int legs{};
  std::string_view sound{};
};
constexpr std::array<Animal::Data, Animal::max_number_animals> data{{
    {"chicken", 2, "cluck"},
    {"dog", 4, "woof"},
    {"cat", 4, "meow"},
    {"elephant", 4, "pawoo"},
    {"duck", 2, "quack"},
    {"snake", 0, "hissss"},
}};

constexpr std::array<Type, max_number_animals> types{
    chicken, dog, cat, elephant, duck, snake,
};
static_assert(std::size(types) == max_number_animals);
constexpr std::array<std::string_view, max_number_animals> animal_names{
    "chicken", "dog", "cat", "elephant", "duck", "snake"};

static_assert(std::size(animal_names) == max_number_animals);
}; // namespace Animal

constexpr std::string_view getAnimalName(const Animal::Type t) {
  return Animal::animal_names[t];
}

std::ostream &operator<<(std::ostream &os, Animal::Type t) {
  return os << getAnimalName(t);
}

std::istream &operator>>(std::istream &is, Animal::Type &t) {
  std::string input{};
  std::getline(is >> std::ws, input);

  for (std::size_t i = 0; i < Animal::max_number_animals; ++i) {
    if (Animal::animal_names[i] == input) {
      t = static_cast<Animal::Type>(i);
      return is;
    }
  }

  is.setstate(std::ios_base::failbit);
  return is;
};

void printAnimalData(Animal::Type type) {
  const Animal::Data &animal{Animal::data[type]};
  std::cout << "A " << animal.name << " has " << animal.legs
            << " legs and says " << animal.sound << ".\n";
}

int main() {
  std::cout << "Enter an animal: ";
  Animal::Type type{};
  std::cin >> type;

  // If users input didn't match
  if (!std::cin) {
    std::cin.clear();
    std::cout << "That animal couldn't be found.\n";
    type = Animal::max_number_animals; // set to invalid option so we don't
                                       // match below
  } else
    printAnimalData(type);

  std::cout << "\nHere is the data for the rest of the animals:\n";
  for (auto a : Animal::types) {
    if (a != type)
      printAnimalData(a);
  }
  return 0;
}
