#include "gtest/gtest.h"

#include "lib/ranges/max_n.hh"
#include <array>
#include <vector>

// TODO test input size less than 3 (and what should the result be?)
// TODO test all permutations of input ordering

TEST(max_n, vector_of_3) {
  std::vector<int> input = {1, 2, 3};

  const auto max_3 = input | gb::max_n<3>;

  EXPECT_EQ((std::array<int, 3>{3, 2, 1}), max_3);
}

TEST(max_n, vector_of_10) {
  std::vector<int> input = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  const auto max_3 = input | gb::max_n<3>;

  EXPECT_EQ((std::array<int, 3>{100, 90, 80}), max_3);
}
