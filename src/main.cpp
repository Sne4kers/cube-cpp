#include <iostream>
#include <unistd.h>
#include "lalgebra.h"
#include "screen.h"

using namespace std;

int main(int, char**) {
    Screen s = Screen(3);
    for(int i = 0; i < 10000; i++) {
        system("clear");
        s.fill(i % 10);
        s.displayScreen();
        usleep(1000000 / 4);
    }
    return 0;
}
