#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

class Fruit {
private:
  std::string m_name{};
  std::string m_color{};

public:
  Fruit(std::string_view name, std::string_view color)
      : m_name{name}, m_color{color} {};
  std::string_view getName() const { return m_name; }
  std::string_view getColor() const { return m_color; }
};

class Apple : public Fruit {
private:
  double m_fiber{};

public:
  Apple(std::string_view name, std::string_view color, double fiber)
      : Fruit(name, color), m_fiber{fiber} {};
  friend std::ostream &operator<<(std::ostream &os, const Apple &f);
};

std::ostream &operator<<(std::ostream &os, const Apple &f) {
  os << "Apple(" << f.getName() << ", " << f.getColor() << ", " << f.m_fiber
     << ")";
  return os;
}

class Banana : public Fruit {
private:
public:
  Banana(std::string_view name, std::string_view color) : Fruit(name, color){};
  friend std::ostream &operator<<(std::ostream &os, const Banana &f) {
    os << "Banana(" << f.getName() << ", " << f.getColor() << ")";
    return os;
  }
};

int main() {
  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}
