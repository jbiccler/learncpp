#include <array>
#include <codecvt>
#include <iostream>
#include <string>
#include <vector>

struct Card {

public:
  enum Rank {
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,

    max_ranks
  };

  // We'll also prefix these for consistency
  enum Suit {
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,

    max_suits
  };

  static constexpr std::array allRanks{
      rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
      rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};
  static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart,
                                       suit_spade};

  Rank rank{};
  Suit suit{};

  friend std::ostream &operator<<(std::ostream &out, const Card &card) {
    out << "Card w/ rank: " << card.rank << ", and suit: " << card.suit << "\n";
    return out;
  }
};
