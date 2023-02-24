#pragma once

#include <array>
using namespace std;

class Screen {
public:
	array<array<int, 128>, 32> screen_matrix;
public:
	Screen();
	Screen(int a);
	void fill(int a);
	void displayScreen();
};