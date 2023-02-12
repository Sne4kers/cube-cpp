#pragma once

#include "vec3.h"
#include <iostream>

namespace lalgebra {
class mat3 {
public:
	vec3 matrix[3];

public:
	mat3();
	mat3(const vec3& a, const vec3& b, const vec3& c);

	static mat3 identity();

	vec3 operator[](int index) const;
};

std::ostream& operator<<(std::ostream& stream, const mat3& a);

}