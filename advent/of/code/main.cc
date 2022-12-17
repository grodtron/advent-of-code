
#include "fmt/core.h"
#include "lib/io/read_file.hh"
#include <string>

int part_1(std::string);
int part_2(std::string);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fmt::print("Usage: {} <path-to-input>\n", argv[0]);
    return 1;
  }

  const std::string contents = gb::read_file(argv[1]);
  fmt::print("Read input file {}, total size is {} bytes\n", argv[1], contents.size());

  fmt::print("The solution to part 1 is: {}\n", part_1(contents));
  fmt::print("The solution to part 2 is: {}\n", part_2(contents));
}
