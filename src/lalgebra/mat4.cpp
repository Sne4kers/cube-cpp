#include "mat4.h"
#include <iostream>

namespace lalgebra {

mat4::mat4() {
    matrix = std::array<vec4, 4>({vec4(1, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 1)});
}

mat4::mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) {
    matrix = std::array<vec4, 4>({a, b, c, d});
}

mat4 mat4::identity() {
    return mat4(vec4(1, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 1));
}

vec4& mat4::operator[](int index) {
    return matrix[index];
}

vec4 mat4::operator[](int index) const {
    return matrix[index];
}

mat4 mat4::operator+(const mat4& b) const {
    return mat4(matrix[0] + b[0], matrix[1] + b[1], matrix[2] + b[2], matrix[3] + b[3]);
}

mat4& mat4::operator+=(const mat4& b) {
    matrix[0] += b[0];
    matrix[1] += b[1];
    matrix[2] += b[2];
    matrix[3] += b[3];
    return *(this);
}

mat4 mat4::operator-(const mat4& b) const {
    return mat4(matrix[0] - b[0], matrix[1] - b[1], matrix[2] - b[2], matrix[3] - b[3]);
}

mat4& mat4::operator-=(const mat4& b) {
    matrix[0] -= b[0];
    matrix[1] -= b[1];
    matrix[2] -= b[2];
    matrix[3] -= b[3];
    return *(this);
}

vec4 mat4::operator*(const vec4& b) const {
    return matrix[0] * b.x + matrix[1] * b.y + matrix[2] * b.z + matrix[3] * b.w;
}

mat4 mat4::operator*(float b) const {
    return mat4(b * matrix[0], b * matrix[1], b * matrix[2], b * matrix[3]);
}

mat4 mat4::operator*(const mat4& b) const {
    return mat4(*this * b[0], *this * b[1], *this * b[2], *this * b[3]);
}

std::ostream& operator<<(std::ostream& stream, const mat4& a) {
    stream << "|" << a[0].x << " " << a[1].x << " " << a[2].x << " " << a[3].x << "|" << std::endl;
    stream << "|" << a[0].y << " " << a[1].y << " " << a[2].y << " " << a[3].y << "|" << std::endl;
    stream << "|" << a[0].z << " " << a[1].z << " " << a[2].z << " " << a[3].z << "|" << std::endl;
    stream << "|" << a[0].w << " " << a[1].w << " " << a[2].w << " " << a[3].w << "|" << std::endl;
    return stream;
}

}