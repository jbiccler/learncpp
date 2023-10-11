#pragma once

#include "direction.h"
#include "point.h"
#include "tile.h"
#include <cstddef>
#include <ostream>
class Board {
private:
  static constexpr std::size_t SIZE{4};
  Tile board[SIZE][SIZE]{};
  Point empty{};

public:
  Board() {
    for (std::size_t i{0}; i < SIZE; ++i) {
      for (std::size_t j{0}; j < SIZE; ++j) {
        board[i][j] = static_cast<int>(i * SIZE + j + 1);
      }
    }
    board[SIZE - 1][SIZE - 1] = 0;
    empty = {static_cast<int>(SIZE - 1), static_cast<int>(SIZE - 1)};
  };
  friend std::ostream &operator<<(std::ostream &os, Board &b);
  bool moveTile(Direction dir);
  bool winCondition() const;
};
