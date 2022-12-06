#include <iostream>

#include "core/math/blend.h"
#include "core/math/color.h"
#include "core/math/ray.h"
#include "core/math/transform.h"
#include "core/types.h"

color ray_color(const ray& ray) {
  vec3 unit_direction = unit_vector(ray.direction());
  real time =
      Transform(unit_direction.y(), Range(-1.0_r, 1.0_r), Range(0.0_r, 1.0_r));

  return lerp(colors::kWhite, colors::kLightBlue, time);
}

int main() {
  // Image

  real aspect_ratio = 16.0_r / 9.0_r;
  int image_width = 400;
  int image_height = as<int>(as<real>(image_width) / aspect_ratio);

  int max_pixel_x = image_width - 1;
  int max_pixel_y = image_height - 1;

  // Camera

  real viewport_height = 2.0_r;
  real viewport_width = aspect_ratio * viewport_height;
  real focal_length = 1.0_r;

  point3 origin = vectors::kZero;
  vec3 horizontal(viewport_width, 0.0_r, 0.0_r);
  vec3 vertical(0.0_r, viewport_height, 0.0_r);
  vec3 lower_left_corner = origin - vec3(viewport_width / 2.0_r,
                                         viewport_height / 2.0_r, focal_length);

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int row = max_pixel_y; row >= 0; --row) {
    std::cerr << "\rScanlines remaining: " << row << ' ' << std::flush;

    for (int col = 0; col < image_width; ++col) {
      real u = as<real>(col) / as<real>(max_pixel_x);
      real v = as<real>(row) / as<real>(max_pixel_y);

      ray ray(origin,
              lower_left_corner + (u * horizontal) + (v * vertical) - origin);

      write_color(std::cout, ray_color(ray));
    }
  }

  std::cerr << "\nDone.\n";

  return 0;
}
