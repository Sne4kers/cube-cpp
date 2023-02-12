#pragma once

#include <iostream>

namespace lalgebra {
class vec4 {
public:
    float x, y, z, w;

public:
    vec4(float x_, float y_, float z_, float w_);  
    vec4();

    vec4& mult(const vec4& b);
    static vec4 mult(const vec4& a, const vec4& b);

    float dot(const vec4& b) const;
    static float dot(const vec4& a, const vec4& b);
    
    vec4 operator+(const vec4& b) const;
    vec4& operator+=(const vec4& b);
    vec4 operator-(const vec4& b) const;
    vec4& operator-=(const vec4& b);
};

std::ostream& operator<<(std::ostream& stream, const vec4& a);

}
