#include <iostream>
#include <unistd.h>
#include "render.h"
#include "lalgebra.h"

using namespace std;

int main(int, char**) {
    render::Screen s = render::Screen(3);
    for(int i = 0; i < 10000; i++) {
        system("clear");
        s.fill(i % 10);
        s.displayScreen();
        usleep(1000000 / 4);
    }
    return 0;
}
