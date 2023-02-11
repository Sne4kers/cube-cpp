#include "vec4.h"
#include <iostream>


namespace lalgebra {

// Regular constructor
vec4::vec4(int x_, int y_, int z_, int w_) : x(x_), y(y_), z(z_), w(w_) {}

// Empty constructor for 0-vector
vec4::vec4() : x(0), y(0), z(0), w(0) {}

// Implement a dot-like multiplication of vectors method
vec4& vec4::mult(const vec4& b) {
    x *= b.x;
    y *= b.y;
    w *= b.z;
    z *= b.w;
    return *this;  
}

// Implement a dot-like multiplication of 2 vectors
vec4 vec4::mult(const vec4& a, const vec4& b) {
    return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);  
}

// Implement a dot product method
int vec4::dot(const vec4& b) const {
    return x * b.x + y * b.y + z * b.z + w * b.w;
}

// Implement a dot product method
int vec4::dot(const vec4& a, const vec4& b) {
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

bool vec4::operator==(const vec4& rhs) const {
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
}

bool vec4::operator!=(const vec4& rhs) const {
    return !(*this == rhs);
}


std::ostream& operator<<(std::ostream& stream, const vec4& a){
    stream << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << ")";
    return stream;
}

}
