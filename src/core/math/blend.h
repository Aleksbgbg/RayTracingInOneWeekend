#ifndef SRC_CORE_MATH_BLEND_H_
#define SRC_CORE_MATH_BLEND_H_

#include "core/types.h"

template <typename TBlend, typename TFrac = real>
constexpr TBlend lerp(TBlend start, TBlend end, TFrac frac) {
  return ((static_cast<TFrac>(1) - frac) * start) + (frac * end);
}

#endif  // SRC_CORE_MATH_BLEND_H_
