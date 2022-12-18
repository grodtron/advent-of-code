#pragma once

#include <tuple>
#include <utility>

namespace gb {

// Convert a Range to a tuple of a fixed size, without any bounds checking.
// undefined behaviour if the range has fewer elements than requested, will
// just truncate the range if it has more elements than needed.
template <size_t N> struct to_tuple_t {

  template <typename Rng> auto operator()(Rng &&r) const {

    return [r]<size_t... I>(std::index_sequence<I...>) {
      auto it = r.begin();
      // TODO - add an (optional) range check in here. Could be something like:
      //   (static_cast<void>(I), ++it, range_check(it, end) ? *it : default)
      //      OR
      //   (static_cast<void>(I), ++it, range_check_else_throw(it, end))
      return std::make_tuple((static_cast<void>(I), *it++)...);
    }
    (std::make_index_sequence<N>{});
  }
};

template <int N> to_tuple_t<N> to_tuple;

template <typename Rng, size_t N> auto operator|(Rng &&rng, to_tuple_t<N> tt) {
  return tt(std::forward<Rng>(rng));
}

} // namespace gb
