#include "model.hh"

#include "fmt/core.h"

#include <exception>
#include <iostream>
#include <tuple>
#include <unordered_map>

Move move_from_char(char c) {
  switch (c) {
  case 'A':
  case 'X':
    return ROCK;
  case 'B':
  case 'Y':
    return PAPER;
  case 'C':
  case 'Z':
    return SCISSORS;
  default:
    throw std::runtime_error{fmt::format("Got an unexpected char for move '{}'", c)};
  }
}

GameResult result_from_char(char c) {
  switch (c) {
  case 'X':
    return LOSE;
  case 'Y':
    return TIE;
  case 'Z':
    return WIN;
  default:
    throw std::runtime_error{fmt::format("Got an unexpected char for desired outcome '{}'", c)};
  }
}

namespace {

// For whatever reason, std::hash is not implemented for std::tuple...
template <typename T, typename V> struct TupleHash {
  size_t operator()(std::tuple<T, V> val) const {
    return static_cast<size_t>(std::get<0>(val)) * 10 + static_cast<size_t>(std::get<1>(val));
  }
};

class move_index_t {
public:
  move_index_t() {
    for (auto &&win : {std::make_tuple(ROCK, SCISSORS), std::make_tuple(SCISSORS, PAPER),
                       std::make_tuple(PAPER, ROCK)}) {
      auto [winning_move, losing_move] = win;

      // If they played the winning move, and you played the losing move, you lose
      result_by_moves_[std::make_tuple(winning_move, losing_move)] = LOSE;
      // If they played the losing move, and you played the winning move, you win
      result_by_moves_[std::make_tuple(losing_move, winning_move)] = WIN;
      result_by_moves_[std::make_tuple(winning_move, winning_move)] = TIE;

      move_by_desired_result_[std::make_tuple(winning_move, TIE)] = winning_move;
      // If they played the losing move, and you want to win, play the winning move
      move_by_desired_result_[std::make_tuple(losing_move, WIN)] = winning_move;
      // If they played the winning move, and you want to lose, play the losing move
      move_by_desired_result_[std::make_tuple(winning_move, LOSE)] = losing_move;
    }
  }

  GameResult result_by_moves(Move their_move, Move my_move) const {
    return result_by_moves_.at(std::make_tuple(their_move, my_move));
  }

  Move move_by_result(Move their_move, GameResult desired_outcome) const {
    return move_by_desired_result_.at(std::make_tuple(their_move, desired_outcome));
  }

private:
  std::unordered_map<std::tuple<Move, Move>, GameResult, TupleHash<Move, Move>> result_by_moves_;
  std::unordered_map<std::tuple<Move, GameResult>, Move, TupleHash<Move, GameResult>>
      move_by_desired_result_;
};

const move_index_t move_index;

} // namespace

Move my_move_for_desired_result(Move their_move, GameResult desired_result) {
  return move_index.move_by_result(their_move, desired_result);
}

GameResult simulate_game(Move their_move, Move my_move) {
  return move_index.result_by_moves(their_move, my_move);
}

int points(Move their_move, Move my_move) {
  const auto result_points = [their_move, my_move]() {
    switch (simulate_game(their_move, my_move)) {
    case WIN:
      return 6;
    case LOSE:
      return 0;
    case TIE:
      return 3;
    }
  }();

  const auto move_points = [my_move]() {
    switch (my_move) {
    case ROCK:
      return 1;
    case PAPER:
      return 2;
    case SCISSORS:
      return 3;
    }
  }();

  return result_points + move_points;
}
