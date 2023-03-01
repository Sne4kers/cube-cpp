#pragma once

#include "vec4.h"
#include <iostream>
#include <array>

namespace lalgebra {
class mat4 {
public:
    std::array<vec4, 4> matrix;

public:
    mat4();
    mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d);

    static mat4 identity();

    vec4& operator[](int index);
    vec4 operator[](int index) const;

    mat4 operator+(const mat4& b) const;
    mat4& operator+=(const mat4& b);
    mat4 operator-(const mat4& b) const;
    mat4& operator-=(const mat4& b);

    vec4 operator*(const vec4& b) const;

    mat4 operator*(float b) const;

    mat4 operator*(const mat4& b) const;
};

std::ostream& operator<<(std::ostream& stream, const mat4& a);

}