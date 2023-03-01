#include "screen.h"
#include <stdio.h>

namespace render{

Screen::Screen() {
	screen_matrix = {0};
}

Screen::Screen(int a) {
	screen_matrix[0].fill(a);
	screen_matrix.fill(screen_matrix[0]);
}

void Screen::fill(int a) {
	screen_matrix[0].fill(a);
	screen_matrix.fill(screen_matrix[0]);
}

void Screen::displayScreen() {
	for(auto& row : screen_matrix) {
		for(auto& v : row) {
			printf("%d", v);
		}
		printf("\n");
	}
}

void Screen::displayMesh(Mesh m, const lalgebra::mat4& transform) {

}

void Screen::displayMesh(Mesh m) {
	displayMesh(m, lalgebra::mat4::identity());
}

}