#pragma once
#include <utility>

namespace gb {

template <typename KeyFn> struct to_sorted_pair_t {
private:
  KeyFn keyfn_;

public:
  to_sorted_pair_t(KeyFn &&keyfn) : keyfn_(keyfn) {}

  template <typename Rng> auto operator()(Rng &&r) const {
    auto it = r.begin();
    const auto a = *it;
    const auto b = *++it;

    // TODO assert it == end

    if (keyfn_(a) < keyfn_(b)) {
      return std::make_pair(a, b);
    } else {
      return std::make_pair(b, a);
    }
  }
};

template <typename KeyFn> auto to_sorted_pair(KeyFn &&keyfn) {
  return to_sorted_pair_t<KeyFn>(std::forward<KeyFn>(keyfn));
}

auto to_sorted_pair() {
  return to_sorted_pair([](auto &&x) { return x; });
}

template <typename Rng, typename KeyFn> auto operator|(Rng &&rng, to_sorted_pair_t<KeyFn> tsp) {
  return tsp(std::forward<Rng>(rng));
}

} // namespace gb
