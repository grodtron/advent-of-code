#include "gtest/gtest.h"

#include "model.hh"

TEST(simulate_game, all_scenarios) {
  EXPECT_EQ(simulate_game(ROCK, PAPER), WIN);
  EXPECT_EQ(simulate_game(PAPER, SCISSORS), WIN);
  EXPECT_EQ(simulate_game(SCISSORS, ROCK), WIN);

  EXPECT_EQ(simulate_game(ROCK, ROCK), TIE);
  EXPECT_EQ(simulate_game(PAPER, PAPER), TIE);
  EXPECT_EQ(simulate_game(SCISSORS, SCISSORS), TIE);

  EXPECT_EQ(simulate_game(PAPER, ROCK), LOSE);
  EXPECT_EQ(simulate_game(SCISSORS, PAPER), LOSE);
  EXPECT_EQ(simulate_game(ROCK, SCISSORS), LOSE);
}
