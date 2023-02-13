#pragma once

#include "vec3.h"
#include <iostream>
#include <array>

namespace lalgebra {
class mat3 {
public:
    std::array<vec3, 3> matrix;

public:
    mat3();
    mat3(const vec3& a, const vec3& b, const vec3& c);

    static mat3 identity();

    vec3& operator[](int index);
    vec3 operator[](int index) const;

    mat3 operator+(const mat3& b) const;
    mat3& operator+=(const mat3& b);
    mat3 operator-(const mat3& b) const;
    mat3& operator-=(const mat3& b);

    vec3 operator*(const vec3& b) const;

    mat3 operator*(float b) const;

    mat3 operator*(const mat3& b) const;
};

std::ostream& operator<<(std::ostream& stream, const mat3& a);

}