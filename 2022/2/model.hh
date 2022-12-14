#pragma once

enum Move { ROCK, PAPER, SCISSORS };

enum GameResult { WIN, LOSE, TIE };

Move move_from_char(char c);
GameResult result_from_char(char c);

Move my_move_for_desired_result(Move their_move, GameResult desired_result);

GameResult simulate_game(Move their_move, Move my_move);

int points(Move their_move, Move my_move);
