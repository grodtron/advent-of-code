#include "lib/ranges/to_int.hh"

#include "gtest/gtest.h"

TEST(to_int, basic) {
  // TODO support const char * directly
  const auto x = std::string{"123"} | gb::to_int;
  ASSERT_EQ(x, 123);
}
