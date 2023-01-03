#include <functional>
#include <string>
#include <string_view>

#include "fmt/core.h"
#include "lib/ranges/to_int.hh"
#include "lib/ranges/to_sorted_pair.hh"
#include "lib/ranges/to_tuple.hh"
#include "range/v3/all.hpp"

struct comma_or_dash {
  template <typename I, typename S> std::pair<bool, I> operator()(I b, S) const {
    return {*b == '-' || *b == ',', ++b};
  }
};

auto parse_input(std::string input) {
  // Split the individual lines of the input
  return input | ranges::views::split('\n') |
         // Then transform them to get the shared char between the two halves
         ranges::views::transform([](auto &&line) {
           // For each input line
           return line |
                  // Assume valid input, and split it into 4 segments, using commas and dashes
                  ranges::views::split_when(comma_or_dash{}) |
                  // Convert all of those 4 segments to positive integers
                  ranges::views::transform(gb::to_int) |
                  // Chunk into two ranges of two. Semantically it might make more sense to do
                  // two nested splits, first on `,` then on `-`, but this felt simpler to me
                  // in the case that we assume well formed input
                  ranges::views::chunk(2) |
                  // Transform the range of ranges to a range of tuples
                  ranges::views::transform(gb::to_tuple<2>) |
                  // Convert the range of 2 tuples to a pair of two tuples, sorted by their "size"
                  // i.e. the size of the range of elements that the tuple describes
                  gb::to_sorted_pair([](auto &&t) { return std::get<1>(t) - std::get<0>(t); });
         });
}

int part_1_impl(std::string input) {

  const auto c = parse_input(input);

  return ranges::count_if(c, [](auto &&p) {
    const auto [smaller_range, larger_range] = p;
    return std::get<0>(larger_range) <= std::get<0>(smaller_range) &&
           std::get<1>(larger_range) >= std::get<1>(smaller_range);
  });
}

int part_2_impl(std::string input) {
  const auto c = parse_input(input);

  return ranges::count_if(c, [](auto &&p) {
    const auto [a, b] = p;

    const auto abeg = std::get<0>(a);
    const auto aend = std::get<1>(a);

    const auto bbeg = std::get<0>(b);
    const auto bend = std::get<1>(b);

    return
        // Partial overlap 1
        (abeg <= bbeg && bbeg <= aend) ||
        // Partial overlap 2
        (abeg <= bend && bend <= aend) ||
        // Completely contained (a in b). We know a is smaller
        (bbeg <= abeg && aend <= bend);
  });
}

std::string part_1(std::string input) { return fmt::format("{}", part_1_impl(input)); }
std::string part_2(std::string input) { return fmt::format("{}", part_2_impl(input)); }
