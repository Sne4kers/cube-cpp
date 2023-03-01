#include "vec4.h"
#include <iostream>


namespace lalgebra {

// Regular constructor
vec4::vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

// Empty constructor for 0-vector
vec4::vec4() : x(0), y(0), z(0), w(0) {}

// Implement a dot-like multiplication of vectors method
vec4& vec4::mult(const vec4& b) {
    x *= b.x;
    y *= b.y;
    z *= b.z;
    w *= b.w;
    return *this;  
}

// Implement a dot-like multiplication of 2 vectors
vec4 vec4::mult(const vec4& a, const vec4& b) {
    return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);  
}

// Implement a dot product method
float vec4::dot(const vec4& b) const {
    return x * b.x + y * b.y + z * b.z + w * b.w;
}

// Implement a dot product method
float vec4::dot(const vec4& a, const vec4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

// Overload + operator for perform vector addition
vec4 vec4::operator+(const vec4& b) const {
    return vec4(x + b.x, y + b.y, z + b.z, w + b.w);
}

// Overload += operator for perform vector addition
vec4& vec4::operator+=(const vec4& b) {
    x += b.x;
    y += b.y;
    z += b.z;
    w += b.w;
    return *this;
}

// Overload - operator for perform vector subtraction
vec4 vec4::operator-(const vec4& b) const {
    return vec4(x - b.x, y - b.y, z - b.z, w - b.w);
}

// Overload -= operator for perform vector subtraction
vec4& vec4::operator-=(const vec4& b) {
    x -= b.x;
    y -= b.y;
    z -= b.z;
    w -= b.w;
    return *this;
}

vec4 vec4::operator*(float b) const {
    return vec4(x * b, y * b, z * b, w * b);
}

vec4& vec4::operator*=(float b) {
    x *= b;
    y *= b;
    z *= b;
    w *= b;
    return *this;
}

vec4 operator*(float lhs, const vec4& rhs) {
    return vec4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs);
}

std::ostream& operator<<(std::ostream& stream, const vec4& a){
    stream << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << ")";
    return stream;
}

}
