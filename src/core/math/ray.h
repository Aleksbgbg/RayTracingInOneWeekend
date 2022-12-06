#ifndef SRC_CORE_MATH_RAY_H_
#define SRC_CORE_MATH_RAY_H_

#include "core/types.h"
#include "vec3.h"

class ray {
 public:
  ray() = default;
  ray(point3 origin, vec3 direction) : origin_(origin), direction_(direction) {}

  point3 origin() const {
    return origin_;
  }
  vec3 direction() const {
    return direction_;
  }

  point3 at(real time) const {
    return origin_ + (time * direction_);
  }

 private:
  point3 origin_;
  vec3 direction_;
};

#endif  // SRC_CORE_MATH_RAY_H_
