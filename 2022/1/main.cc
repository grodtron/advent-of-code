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

std::string read_file(std::string path) {
  std::ifstream input(path);

  if (input.fail()) {
    std::cerr << "Failed to open file " << path << std::endl;
    return {};
  }

  std::stringstream ss;

  input >> ss.rdbuf();

  if (input.fail() && !input.eof()) {
    std::cerr << "Error reading file " << path << std::endl;
    return {};
  }

  return ss.str();
}

int to_int(std::string_view v) {
  int out;
  std::from_chars(v.data(), v.data() + v.size(), out);
  return out;
}

int main(int argc, char *argv[]) {
  const std::string contents = read_file(argv[1]);
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

  std::cout << ranges::max(sums) << std::endl;

  return 0;
}
