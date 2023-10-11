
#include "board.h"
#include "tile.h"
#include <cstddef>
#include <ostream>
#include <type_traits>
std::ostream &operator<<(std::ostream &os, Board &b) {
  for (std::size_t i{0}; i < b.SIZE; ++i) {
    for (std::size_t j{0}; j < b.SIZE; ++j) {
      os << b.board[i][j];
    }
    os << '\n';
  }
  return os;
}
bool Board::moveTile(Direction dir) {
  auto adj = empty.getAdjacentPoint(dir);
  if (adj.x >= 0 && adj.x < static_cast<int>(SIZE) && adj.y >= 0 &&
      adj.y < static_cast<int>(SIZE)) {
    std::swap(board[adj.y][adj.x], board[empty.y][empty.x]);
    empty = {adj.x, adj.y};
    return true;
  }
  return false;
};
bool Board::winCondition() const {
  int s{static_cast<int>(SIZE)};

  for (int i{0}; i < s; ++i) {
    for (int j{0}; j < s; ++j) {
      int target{i * s + j + 1};
      if (target == 16) {
        target = 0;
      }
      if (board[i][j].getNum() != target) {
        return false;
      }
    }
  }
  return true;
}
