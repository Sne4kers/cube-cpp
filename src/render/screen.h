#pragma once

#include "../lalgebra.h"
#include "common.h"
#include <array>
#include <string>
#include <vector>
using namespace std;

namespace render{

class Screen {
private:
	array<array<int, 128>, 32> screen_matrix;
	std::string grayscale_ascii = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`.";

public:
	Screen();
	Screen(int a);
	void fill(int a);
	void displayScreen();
	void displayMesh(Mesh m, const lalgebra::mat4& transform);
	void displayMesh(Mesh m);
};
}