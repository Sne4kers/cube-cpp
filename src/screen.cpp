#include "screen.h"
#include <stdio.h>

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