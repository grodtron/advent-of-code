#include "lib/io/read_file.hh"

#include <fstream>
#include <iostream>
#include <sstream>

namespace gb {
// TODO - proper error handling... right now we just return an empty string and
// print a message
std::string read_file(std::string path) {
  std::ifstream input(path);

  if (input.fail()) {
    // TODO - provide more info on the error
    std::cerr << "Failed to open file " << path << std::endl;
    return {};
  }

  std::stringstream ss;

  input >> ss.rdbuf();

  if (input.fail() && !input.eof()) {
    // TODO - provide more info on the error
    std::cerr << "Error reading file " << path << std::endl;
    return {};
  }

  return ss.str();
}
} // namespace gb
