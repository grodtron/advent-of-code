#include <cctype>
#include <set>
#include <string>

#include "fmt/core.h"
#include "range/v3/all.hpp"

int points_for_char(char c) {
  // Lowercase item types a through z have priorities 1 through 26.
  // Uppercase item types A through Z have priorities 27 through 52.

  if (c >= 'a' && c <= 'z') {
    return 1 + (c - 'a');
  } else if (c >= 'A' && c <= 'Z') {
    return 27 + (c - 'A');
  } else {
    throw std::runtime_error(fmt::format("Unexpected char '{}'", c));
  }
}

int part_1_impl(std::string input) {

  const auto c =
      // Split the individual lines of the input
      input | ranges::views::split('\n') |
      // Then transform them to get the shared char between the two halves
      ranges::views::transform([](auto &&rng) {
        // Get the length and verify that it's even
        const auto len = ranges::distance(rng);
        if (len % 2 == 1) {
          throw std::runtime_error(
              fmt::format("Found a line with odd length: {}\n", rng | ranges::to<std::string>));
        }

        // chunk the input line in half and convert each half to a set of chars
        const auto sorted_chunks =
            rng | ranges::views::chunk(len / 2) | ranges::views::transform(ranges::to<std::set>());

        // Fold the range of two sets of chars (the two halves of the input line) via set
        // intersection to find the common character
        const auto intersection = *ranges::fold_left_first(sorted_chunks, [](auto &&x, auto &&y) {
          return ranges::views::set_intersection(x, y) | ranges::to<std::set>();
        });

        // Verify that there's only one shared char and return it
        if (intersection.size() != 1) {
          throw std::runtime_error(
              fmt::format("There were multiple shared items in the two sections\n"));
        }

        return *intersection.begin();
      }) |
      // map to it's points value
      ranges::views::transform(points_for_char);

  // return the sum over the whole input
  return ranges::accumulate(c, 0);
}

int part_2_impl(std::string input) {

  const auto c =
      // Split the individual lines of the input
      input | ranges::views::split('\n') |
      // Convert each line to a set of chars
      ranges::views::transform(ranges::to<std::set>()) |
      // get each set of 3 lines
      ranges::views::chunk(3) |
      // and fold them together via set intersection
      ranges::views::transform([](auto &&rng) {
        // Fold the range of two sets of chars (the two halves of the input line) via set
        // intersection to find the common character
        const auto intersection = *ranges::fold_left_first(rng, [](auto &&x, auto &&y) {
          return ranges::views::set_intersection(x, y) | ranges::to<std::set>();
        });

        // Verify that there's only one shared char and return it
        if (intersection.size() != 1) {
          throw std::runtime_error(
              fmt::format("There were multiple shared items in the two sections\n"));
        }

        return *intersection.begin();
      }) |
      // map to it's points value
      ranges::views::transform(points_for_char);

  // return the sum over the whole input
  return ranges::accumulate(c, 0);
}

std::string part_1(std::string input) { return fmt::format("{}", part_1_impl(input)); }
std::string part_2(std::string input) { return fmt::format("{}", part_2_impl(input)); }
