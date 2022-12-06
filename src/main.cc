#include <iostream>

#include "core/types.h"

int main() {
  int image_width = 256;
  int image_height = 256;

  int max_pixel_x = image_width - 1;
  int max_pixel_y = image_height - 1;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int row = max_pixel_y; row >= 0; --row) {
    std::cerr << "\rScanlines remaining: " << row << ' ' << std::flush;

    for (int col = 0; col < image_width; ++col) {
      real r = as<real>(col) / as<real>(max_pixel_x);
      real g = as<real>(row) / as<real>(max_pixel_y);
      real b = 0.25_r;

      int outR = as<int>(255_r * r);
      int outG = as<int>(255_r * g);
      int outB = as<int>(255_r * b);

      std::cout << outR << ' ' << outG << ' ' << outB << '\n';
    }
  }

  std::cerr << "\nDone.\n";

  return 0;
}
