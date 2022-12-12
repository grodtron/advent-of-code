#include "gtest/gtest.h"

#include "lib/ranges/to_tuple.hh"
#include <array>
#include <vector>

TEST(to_tuple, from_vector_with_call_operator) {
  const std::vector<int> input = {1, 2, 3};

  const auto result = gb::to_tuple<3>(input);

  ASSERT_EQ(std::make_tuple(1, 2, 3), result);
}

TEST(to_tuple, from_vector_with_pipe_operator) {
  const std::vector<int> input = {1, 2, 3};

  const auto result = input | gb::to_tuple<3>;

  ASSERT_EQ(std::make_tuple(1, 2, 3), result);
}
