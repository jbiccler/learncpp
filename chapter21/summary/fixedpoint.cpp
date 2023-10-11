#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <istream>

class FixedPoint2 {
private:
  int16_t m_nf{};
  int8_t m_f{};

public:
  FixedPoint2(int16_t nf, int8_t f) : m_nf{nf}, m_f{f} {
    assert(m_f > -100 && m_f < 100);
    if (nf < 0 || f < 0) {
      if (nf > 0) {
        m_nf *= -1;
      }
      if (f > 0) {
        m_f *= -1;
      }
    }
  };
  FixedPoint2(double d) {
    m_nf = static_cast<int16_t>(d);
    m_f = static_cast<int8_t>(std::round(d * 100) - m_nf * 100);
  };
  friend std::ostream &operator<<(std::ostream &os, FixedPoint2 &fp);
  operator double() const { return m_nf + static_cast<double>(m_f) / 100; };
  friend bool operator==(const FixedPoint2 &a, const FixedPoint2 &b);
  FixedPoint2 operator-() const { return FixedPoint2(-m_nf, -m_f); }
  friend FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b) {
    int8_t frac = a.m_f + b.m_f;
    int16_t base = a.m_nf + b.m_nf;

    if (frac <= -100) {
      base -= 1;
      frac += 100;
    } else if (frac >= 100) {
      base += 1;
      frac -= 100;
    }
    return {base, frac};
  }
  friend std::istream &operator>>(std::istream &is, double val);
};
std::istream &operator>>(std::istream &is, FixedPoint2 &fp) {
  double d{};
  is >> d;
  fp = FixedPoint2{d};
  return is;
}

bool operator==(const FixedPoint2 &a, const FixedPoint2 &b) {
  return (a.m_f == b.m_f && a.m_nf == b.m_nf);
}
std::ostream &operator<<(std::ostream &os, FixedPoint2 &fp) {
  os << static_cast<double>(fp);
  return os;
};

void testAddition() {
  // h/t to reader Sharjeel Safdar for this function
  std::cout << std::boolalpha;
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98})
            << '\n'; // both positive, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25})
            << '\n'; // both positive, with decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98})
            << '\n'; // both negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25})
            << '\n'; // both negative, with decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48})
            << '\n'; // second negative, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75})
            << '\n'; // second negative, possible decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48})
            << '\n'; // first negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75})
            << '\n'; // first negative, possible decimal overflow
}

int main() {
  testAddition();

  FixedPoint2 a{-0.48};
  std::cout << a << '\n';

  std::cout << -a << '\n';

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;

  std::cout << "You entered: " << a << '\n';

  return 0;
}
