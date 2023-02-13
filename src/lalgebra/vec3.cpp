#include "vec3.h"
#include <iostream>
#include <cmath>

namespace lalgebra {

// Regular constructor
vec3::vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

// Empty constructor for 0-vector
vec3::vec3() : x(0), y(0), z(0) {}

// Implement a dot-like multiplication of vectors
vec3& vec3::mult(const vec3& b){
    x *= b.x;
    y *= b.y;
    z *= b.z;
    return *this;
}

// Implement a dot-like multiplication of vectors
vec3 vec3::mult(const vec3& a, const vec3& b){
    return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

// Implement a dot product method
float vec3::dot(const vec3& b) const {
    return x * b.x +  y * b.y + z * b.z;
}

// Implement a dot product method
float vec3::dot(const vec3& a, const vec3& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Overload + operator to perform vector addition
vec3 vec3::operator+(const vec3& b) const {
    return vec3(x + b.x, y + b.y, z + b.z);
}

// Overload += operator to perform vector addition assignment
vec3& vec3::operator+=(const vec3& b) {
    x += b.x;
    y += b.y;
    z += b.z;
    return *this;
}

// Overload - operator to perform vector subtraction
vec3 vec3::operator-(const vec3& b) const {
    return vec3(x - b.x, y - b.y, z - b.z);
}

// Overload -= operator to perform vector subtraction with assignment
vec3& vec3::operator-=(const vec3& b) {
    x -= b.x;
    y -= b.y;
    z -= b.z;
    return *this;
}

vec3 vec3::operator*(float b) const {
    return vec3(x * b, y * b, z * b);
}

vec3& vec3::operator*=(float b) {
    x *= b;
    y *= b;
    z *= b;
    return *this;
}

vec3 operator*(float lhs, const vec3& rhs) {
    return vec3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

std::ostream& operator<<(std::ostream& stream, const vec3& a){
    stream << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return stream;
}

}
