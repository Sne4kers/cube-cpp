#pragma once

#include "../lalgebra.h"
#include <vector>

namespace render{
struct Vertex {
	lalgebra::vec3 cords;
	lalgebra::vec3 color;
};

struct Triangle {
	Vertex v1, v2, v3;
	lalgebra::vec3 normal;
};

struct Mesh {
	std::vector<Triangle> triangles;
};
}