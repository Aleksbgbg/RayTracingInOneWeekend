#ifndef SRC_CORE_TYPES_H_
#define SRC_CORE_TYPES_H_

using real = float;

template <typename T>
constexpr T as(auto value) {
  return static_cast<T>(value);
}

constexpr real operator"" _r(long double value) {
  return as<real>(value);
}

constexpr real operator"" _r(unsigned long long value) {
  return as<real>(value);
}

#endif  // SRC_CORE_TYPES_H_
