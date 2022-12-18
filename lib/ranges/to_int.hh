#pragma once
#include <utility>

namespace gb {

// A little helper to convert a range of chars to an int,
// since there's no straightforward way to do it from a string
// view, and it seems pretty awkward to convert ot string just
// to get the types right to call stoi or atoi
template <std::size_t Base> struct to_int_t {
  template <typename Rng> auto operator()(Rng &&r) const {

    // TODO - support bases other than 10
    static_assert(Base == 10, "Not supporting non-10 bases for now");

    std::size_t out = 0;
    for (const char c : r) {
      // TODO assert char in [0, 9]
      out = (out * Base) + (c - '0');
    }
    return out;
  }
};

to_int_t<10> to_int;

template <typename Rng, std::size_t N> auto operator|(Rng &&rng, to_int_t<N> ti) {
  return ti(std::forward<Rng>(rng));
}

} // namespace gb
