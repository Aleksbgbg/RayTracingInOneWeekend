#ifndef COLOR_H
#define COLOR_H

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

#endif  // COLOR_H
