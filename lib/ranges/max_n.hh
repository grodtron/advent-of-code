#include <algorithm>
#include <array>
#include <functional>

namespace gb {

template <size_t N> class max_n_range {
public:
  // TODO - Support arbitrary value type (don't harcode `int`)
  template <typename T> std::array<int, N> invoke(T &&t) const {
    // We start with an uninitialized array of size one greater than the output
    // size we are targetting
    std::array<int, N + 1> wip;

    // Index within the output array
    size_t i = 0;
    for (int v : t) {
      // Overwrite the current output position with the next value. When we are
      // still filling up the output, this is basically appending. Once the
      // output is "full" then this is replacing the N+1th element, which we
      // know is not one of the N greatest
      wip[i] = v;

      // We sort the previous N greatest elements (already sorted) with the
      // newly added element
      std::sort(wip.begin(), wip.begin() + i + 1, std::greater<int>());

      i = std::min(i + 1, N);
    }

    std::array<int, N> output;

    // TODO - avoid this copy and return a span (need to figure out how the
    // lifetime would work)
    std::copy(wip.begin(), wip.begin() + N, output.begin());

    return output;
  }
};

template <size_t N> max_n_range<N> max_n = max_n_range<N>{};

template <typename T, size_t N>
constexpr std::array<int, N> operator|(T &&t, max_n_range<N> r) {
  return r.invoke(std::forward<T>(t));
}

} // namespace gb
