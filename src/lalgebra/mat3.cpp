#include "vec3.h"
#include "mat3.h"
#include <iostream>

namespace lalgebra {

mat3::mat3() {
    matrix = std::array<vec3, 3>({vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)});
}

mat3::mat3(const vec3& a, const vec3& b, const vec3& c) {
    matrix = std::array<vec3, 3>({a, b, c});
}

mat3 mat3::identity() {
    return mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
}

vec3& mat3::operator[](int index) {
    return matrix[index];
}

vec3 mat3::operator[](int index) const {
    return matrix[index];
}

mat3 mat3::operator+(const mat3& b) const {
    return mat3(matrix[0] + b[0], matrix[1] + b[1], matrix[2] + b[2]);
}

mat3& mat3::operator+=(const mat3& b) {
    matrix[0] += b[0];
    matrix[1] += b[1];
    matrix[2] += b[2];
    return *(this);
}

mat3 mat3::operator-(const mat3& b) const {
    return mat3(matrix[0] - b[0], matrix[1] - b[1], matrix[2] - b[2]);
}

mat3& mat3::operator-=(const mat3& b) {
    matrix[0] -= b[0];
    matrix[1] -= b[1];
    matrix[2] -= b[2];
    return *(this);
}

vec3 mat3::operator*(const vec3& b) const {
    return matrix[0] * b.x + matrix[1] * b.y + matrix[2] * b.z;
}

mat3 mat3::operator*(float b) const {
    return mat3(b * matrix[0], b * matrix[1], b * matrix[2]);
}

mat3 mat3::operator*(const mat3& b) const {
    return mat3(*this * b[0], *this * b[1], *this * b[2]);
}

std::ostream& operator<<(std::ostream& stream, const mat3& a) {
    stream << "|" << a[0].x << " " << a[1].x << " " << a[2].x << "|" << std::endl;
    stream << "|" << a[0].y << " " << a[1].y << " " << a[2].y << "|" << std::endl;
    stream << "|" << a[0].z << " " << a[1].z << " " << a[2].z << "|" << std::endl;
    return stream;
}

}