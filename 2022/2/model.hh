#pragma once

enum Move { ROCK, PAPER, SCISSORS };

enum GameResult { WIN, LOSE, TIE };

Move move_from_char(char c);

GameResult simulate_game(Move their_move, Move my_move);

int points(Move their_move, Move my_move);
