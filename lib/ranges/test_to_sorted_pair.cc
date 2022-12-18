#include "gtest/gtest.h"

#include "lib/ranges/to_sorted_pair.hh"

#include <tuple>
#include <utility>
#include <vector>

TEST(to_sorted_pair, sorted_input) {
  const auto input = std::vector<int>{1, 2};

  ASSERT_EQ(input | gb::to_sorted_pair(), std::make_pair(1, 2));
}

TEST(to_sorted_pair, unsorted_input) {
  const auto input = std::vector<int>{4, 0};

  ASSERT_EQ(input | gb::to_sorted_pair(), std::make_pair(0, 4));
}

TEST(to_sorted_pair, tuples_with_custom_keyfn) {
  const auto input =
      std::vector<std::tuple<int, int>>{std::make_tuple(1, 2), std::make_tuple(0, 10)};

  const auto result =
      input | gb::to_sorted_pair([](auto &&t) { return std::get<1>(t) - std::get<0>(t); });

  const auto expected = std::make_pair(std::make_tuple(1, 2), std::make_tuple(0, 10));

  ASSERT_EQ(result, expected);
}
