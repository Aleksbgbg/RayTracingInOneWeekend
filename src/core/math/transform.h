#ifndef SRC_CORE_MATH_TRANSFORM_H_
#define SRC_CORE_MATH_TRANSFORM_H_

#include "Range.h"

// Maps number x in the input range to a number in the output range
template <typename T>
constexpr T Transform(const T x, const Range<T> input, const Range<T> output) {
  return ((x - input.min) *
          ((output.max - output.min) / (input.max - input.min))) +
         output.min;
}

template <typename T>
constexpr void Transform(T* const x, const Range<T> input,
                         const Range<T> output) {
  *x = Transform(*x, input, output);
}

// Maps number x in the range [0, 1] to a number in the output range
template <typename T>
constexpr T Transform(const T x, const Range<T> output) {
  return Transform(x, Range(static_cast<T>(0), static_cast<T>(1)), output);
}

template <typename T>
constexpr void Transform(T* const x, const Range<T> output) {
  *x = Transform(*x, output);
}

#endif  // SRC_CORE_MATH_TRANSFORM_H_
