#include "lib/io/read_file.hh"
#include "lib/ranges/to_tuple.hh"

#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/range/conversion.hpp"
#include "range/v3/view/split.hpp"
#include "range/v3/view/take.hpp"
#include "range/v3/view/transform.hpp"

#include "fmt/core.h"

#include "model.hh"

#include <iostream>
#include <string>
#include <string_view>
#include <tuple>

const auto only_element = [](auto &&r) {
  const auto length = ranges::distance(r);

  if (length != 1) {
    throw std::runtime_error(fmt::format("Length should be 1 but is {}", length));
  }

  return *r.begin();
};

int main(int argc, char *argv[]) {
  const std::string contents = gb::read_file(argv[1]);
  std::cout << "Total size is " << contents.size() << std::endl;

  {
    const auto scores = contents | ranges::views::split('\n') |             //
                        ranges::views::transform([](auto &&r) {             //
                          return r | ranges::views::split(' ') |            //
                                 ranges::views::transform(only_element) |   //
                                 ranges::views::transform(move_from_char) | //
                                 gb::to_tuple<2>;
                        }) |                                        //
                        ranges::views::transform([](auto &&moves) { //
                          return std::apply(points, moves);
                        });

    const auto result = ranges::accumulate(scores, 0);

    fmt::print("The total score when following the strategy is {}\n", result);
  }

  return 0;
}
