#include "model.hh"

#include "fmt/core.h"

#include <exception>
#include <iostream>

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
    throw std::runtime_error{fmt::format("Got an unexpected char '{}'", c)};
  }
}

GameResult simulate_game(Move their_move, Move my_move) {
  switch (their_move) {
  case ROCK:
    switch (my_move) {
    case ROCK:
      return TIE;
    case PAPER:
      return WIN;
    case SCISSORS:
      return LOSE;
    }
  case PAPER:
    switch (my_move) {
    case ROCK:
      return LOSE;
    case PAPER:
      return TIE;
    case SCISSORS:
      return WIN;
    }
  case SCISSORS:
    switch (my_move) {
    case ROCK:
      return WIN;
    case PAPER:
      return LOSE;
    case SCISSORS:
      return TIE;
    }
  }
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
