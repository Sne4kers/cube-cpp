#include "lalgebra.h"
#include "cmath"
#include "vec4Test.h"
using namespace lalgebra;

class mat4Test : public vec4Test {    
protected:
    static constexpr float eps = 0.001f;
protected:
    void AssertEqual(const mat4& a, const mat4& b) {
        AssertEqualVectors(a[0], b[0], eps);
        AssertEqualVectors(a[1], b[1], eps);
        AssertEqualVectors(a[2], b[2], eps);
        AssertEqualVectors(a[3], b[3], eps);
    }
};