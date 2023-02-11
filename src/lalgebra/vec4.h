#pragma once

#include <iostream>

namespace lalgebra {
class vec4 {
public:
    int x, y, z, w;

public:
    vec4(int x_, int y_, int z_, int w_);  
    vec4();

    vec4& mult(const vec4& b);
    static vec4 mult(const vec4& a, const vec4& b);

    int dot(const vec4& b) const;
    static int dot(const vec4& a, const vec4& b);
    
    vec4 operator+(const vec4& b) const;
    vec4& operator+=(const vec4& b);
    vec4 operator-(const vec4& b) const;
    vec4& operator-=(const vec4& b);
    bool operator==(const vec4& rhs) const;
    bool operator!=(const vec4& rhs) const;
};

std::ostream& operator<<(std::ostream& stream, const vec4& a);

}
