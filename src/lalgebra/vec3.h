#pragma once

#include <iostream>

namespace lalgebra {
class vec3 {
public:
    float x, y, z;

public:
    vec3(float x_, float y_, float z_);  
    vec3();

    vec3& mult(const vec3& b);
    static vec3 mult(const vec3& a, const vec3& b);

    float dot(const vec3& b) const;
    static float dot(const vec3& a, const vec3& b);

    vec3 operator+(const vec3& b) const;
    vec3& operator+=(const vec3& b);
    vec3 operator-(const vec3& b) const;
    vec3& operator-=(const vec3& b);

    vec3 operator*(float b) const;
    vec3& operator*=(float b);
};

vec3 operator*(float lhs, const vec3& rhs);

std::ostream& operator<<(std::ostream& stream, const vec3& a);

}

