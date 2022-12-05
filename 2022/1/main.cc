#include <charconv>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

#include "range/v3/algorithm/max.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/split.hpp"
#include "range/v3/view/transform.hpp"

#include "lib/io/read_file.hh"
#include "lib/ranges/max_n.hh"

int to_int(std::string_view v) {
  int out;
  std::from_chars(v.data(), v.data() + v.size(), out);
  return out;
}

int main(int argc, char *argv[]) {
  const std::string contents = gb::read_file(argv[1]);
  std::cout << "Total size is " << contents.size() << std::endl;

  const auto lines =
      contents | ranges::views::split('\n') |
      ranges::views::transform([](auto &&rng) {
        return std::string_view(&*rng.begin(), ranges::distance(rng));
      });

  const auto sums =
      lines | ranges::views::split("") |
      ranges::views::transform([](auto &&rng) {
        return ranges::accumulate(rng | ranges::views::transform(to_int), 0);
      });

  std::cout << "The elf with the most calories has " << ranges::max(sums)
            << std::endl;

  const auto max_3 = ranges::accumulate(sums | gb::max_n<3>, 0);

  std::cout << "The three elves with the most calories have " << max_3
            << " in total" << std::endl;

  return 0;
}
