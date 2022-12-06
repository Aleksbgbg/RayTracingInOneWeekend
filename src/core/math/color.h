#ifndef SRC_CORE_MATH_COLOR_H_
#define SRC_CORE_MATH_COLOR_H_

#include <iostream>

#include "core/types.h"
#include "vec3.h"

using color = vec3;

void write_color(std::ostream& out, color color) {
  int outR = as<int>(255_r * color.x());
  int outG = as<int>(255_r * color.y());
  int outB = as<int>(255_r * color.z());

  out << outR << ' ' << outG << ' ' << outB << '\n';
}

namespace colors {

inline constexpr color kWhite(1.0_r, 1.0_r, 1.0_r);
inline constexpr color kLightBlue(0.5_r, 0.7_r, 1.0_r);

}

#endif  // SRC_CORE_MATH_COLOR_H_
