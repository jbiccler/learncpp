#include <cmath>
#include <iostream>

class Average {

private:
  int32_t m_sum;
  int8_t m_n;
  double m_avg;

public:
  Average &operator+=(int i) {
    m_sum = m_sum + i;
    ++m_n;
    m_avg = static_cast<double>(m_sum) / m_n;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &os, Average &avg);
};

std::ostream &operator<<(std::ostream &os, Average &avg) {
  os << avg.m_avg;
  return os;
}

int main() {
  Average avg{};

  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10;         // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy{avg};
  std::cout << copy << '\n';

  return 0;
}
