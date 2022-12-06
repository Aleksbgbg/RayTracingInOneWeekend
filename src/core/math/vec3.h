#ifndef SRC_CORE_MATH_VEC3_H_
#define SRC_CORE_MATH_VEC3_H_

#include <cmath>
#include <iostream>

#include "core/types.h"
#include "square.h"

struct vec3 {
  real entries[3];

  constexpr vec3() : entries{0, 0, 0} {}
  constexpr vec3(real entry0, real entry1, real entry2)
      : entries{entry0, entry1, entry2} {}

  real x() const {
    return entries[0];
  }
  real y() const {
    return entries[1];
  }
  real z() const {
    return entries[2];
  }

  real operator[](int index) const {
    return entries[index];
  }
  real& operator[](int index) {
    return entries[index];
  }

  vec3 operator-() const {
    return vec3(-x(), -y(), -z());
  }
  vec3 operator+(const vec3& other) const {
    return vec3(x() + other.x(), y() + other.y(), z() + other.z());
  }
  vec3 operator-(const vec3& other) const {
    return (*this) + (-other);
  }
  vec3 operator*(const vec3& other) const {
    return vec3(x() * other.x(), y() * other.y(), z() * other.z());
  }

  vec3 operator*(real scalar) const {
    return vec3(scalar * x(), scalar * y(), scalar * z());
  }
  vec3 operator/(real scalar) const {
    return (*this) * (1_r / scalar);
  }

  vec3& operator+=(const vec3& other) {
    new (this) vec3((*this) + other);
    return *this;
  }
  vec3& operator*=(real scalar) {
    new (this) vec3((*this) * scalar);
    return *this;
  }
  vec3& operator/=(real scalar) {
    new (this) vec3((*this) / scalar);
    return *this;
  }

  real length() const {
    return std::sqrt(length_squared());
  }
  real length_squared() const {
    return square(x()) + square(y()) + square(z());
  }
};

inline std::ostream& operator<<(std::ostream& out, const vec3& vector) {
  return out << vector.x() << ' ' << vector.y() << ' ' << vector.z();
}

inline vec3 operator*(real scalar, const vec3& vector) {
  return vector * scalar;
}

inline real dot(const vec3& left, const vec3& right) {
  return (left.x() * right.x()) + (left.y() * right.y()) +
         (left.z() * right.z());
}

inline vec3 cross(const vec3& left, const vec3& right) {
  return vec3((left.y() * right.z()) - (left.z() * right.y()),
              (left.z() * right.x()) - (left.x() * right.z()),
              (left.x() * right.y()) - (left.y() * right.x()));
}

inline vec3 unit_vector(vec3 vector) {
  return vector / vector.length();
}

using point3 = vec3;

namespace vectors {

inline constexpr vec3 kZero(0.0_r, 0.0_r, 0.0_r);
inline constexpr vec3 kOne(1.0_r, 1.0_r, 1.0_r);

}

#endif  // SRC_CORE_MATH_VEC3_H_
