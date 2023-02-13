#include "lalgebra.h"
#include "cmath"
#include "vec3Test.h"
using namespace lalgebra;

class mat3Test : public vec3Test {    
protected:
    void AssertEqual(const mat3& a, const mat3& b) {
        AssertEqualVectors(a[0], b[0]);
		AssertEqualVectors(a[1], b[1]);
		AssertEqualVectors(a[2], b[2]);
    }
};