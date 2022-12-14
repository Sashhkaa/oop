#include <cmath>
#include <iostream>


struct Vector3f {

  Vector3f(float x, float y, float z) : x(x), y(y), z(z) {
  }

  Vector3f operator+() const {
    return *this;
  }

  Vector3f operator-() const {
    return {-this->x, -this->y, -this->z};
  }

  Vector3f operator+(const Vector3f &other_vec) const {
    return {this->x + other_vec.x, this->y + other_vec.y, this->z + other_vec.z};
  }

  Vector3f operator-(const Vector3f &other_vec) const {
    return *this + (-other_vec);
  }

  Vector3f operator*(float scalar) const {
    return {this->x * scalar, this->y * scalar, this->z * scalar};
  }
  Vector3f operator/(float scalar) const {
    return *this * (1 / scalar);
  }

  float operator*(const Vector3f& other_vec) const {
    return this->x * other_vec.x + this->y * other_vec.y + this->z * other_vec.z;
  }

  bool operator==(const Vector3f &other_vec) const {
    return this->x == other_vec.x && this->y == other_vec.y && this->z == other_vec.z;
  }

  bool operator!=(const Vector3f &other_vec) const {
    return !(*this == other_vec);
  }

  void operator+=(const Vector3f &other_vec) {
    *this = *this + other_vec;
  }

  void operator-=(const Vector3f &other_vec) {
    *this += (-other_vec);
  }

  void operator*=(float scalar) {
    *this = *this * scalar;
  }

  void operator/=(float scalar) {
    *this = *this / scalar;
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector3f &vec);
  friend std::istream &operator>>(std::istream &in, Vector3f &vec);

  float x;
  float y;
  float z;
};

Vector3f operator*(float scalar, const Vector3f &vec) {
  return vec * scalar;
}

std::ostream &operator<<(std::ostream &out, const Vector3f &vec) {
  out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")\n";
  return out;
}

std::istream &operator>>(std::istream &in, Vector3f &vec) {
  in >> vec.x >> vec.y >> vec.z;
  return in;
}

float squaredNorm(const Vector3f& a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;

}

float norm(const Vector3f& a) {
  return std::sqrt(squaredNorm(a));
}

void normalize(Vector3f& a) {
  a = a / norm(a);
}
