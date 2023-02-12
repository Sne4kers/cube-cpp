#include <iostream>
#include "lalgebra.h"
using namespace std;

int main(int, char**) {
    using namespace lalgebra;
    auto a = vec3(1, 1, 1);
    auto b = vec3(1, 1, 1);
    a += b;
    cout << a << endl;

    a -= b;
    cout << a << endl;

    a += b;
    b += vec3(3, 7, 2);
    a = a.mult(b);
    cout << a << endl;
    auto mat = mat3();
    cout << "Zero matrix:" << endl;
    cout << mat;
    cout << "Identity matrix:" << endl;
    cout << mat3::identity();
    return 0;
}
