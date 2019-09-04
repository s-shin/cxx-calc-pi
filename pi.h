#ifndef PI_H_
#define PI_H_

#include <cstdint>

// Unbounded Spigot Algorithms for the Digits of Pi
// http://www.cs.ox.ac.uk/jeremy.gibbons/publications/spigot.pdf

namespace pi {

template <class T> struct State {
  using BigInt = T;
  BigInt q = 1, r = 180, t = 60, i = 2;
};

template <class T, class V = T> struct Result {
  using BigInt = T;
  using Value = V;
  Value value;
  State<BigInt> state;
};

template <class T, class V = T> inline Result<T> GetNext(const State<T> &s) {
  Result<T, V> r;
  auto tmp = s.i * 3;
  auto u = (tmp + 1) * 3 * (tmp + 2);
  r.value = ((((s.i * 27) - 12) * s.q) + (s.r * 5)) / (s.t * 5);
  r.state.q = s.q * 10 * s.i * (s.i * 2 - 1);
  r.state.r = u * 10 * (s.q * (s.i * 5 - 2) + s.r - s.t * r.value);
  r.state.t = u * s.t;
  r.state.i = s.i + 1;
  return r;
}

} // namespace pi

#endif // PI_H_
