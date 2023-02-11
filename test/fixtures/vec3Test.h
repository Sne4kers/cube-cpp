#include "lalgebra.h"
#include "cmath"
using namespace lalgebra;

class vec3Test : public ::testing::Test {
protected:
	vec3 v0_0_0;
	vec3 v0_0_0_1;
	vec3 v2_3_4;
	vec3 v3_5_1;
	vec3 v4_0_1;
	float eps = 0.0001;
	
protected:
	void SetUp() override {
		v0_0_0 = vec3();
		v0_0_0_1 = vec3(0, 0, 0);
		v2_3_4 = vec3(2, 3, 4);
		v3_5_1 = vec3(3, 5, 1);
		v4_0_1 = vec3(4, 0, 1);
	}

	void AssertEqual(const vec3& a, const vec3& b) {
        ASSERT_NEAR(a.x, b.x, eps);
        ASSERT_NEAR(a.y, b.y, eps);
        ASSERT_NEAR(a.z, b.z, eps);
    }

	testing::AssertionResult DoubleNotNearPredFormat(const char* expr1, const char* expr2,
                                     const char* abs_error_expr, const vec3&a,
                                     const vec3& b, float abs_error) {
		const float diffx = std::fabs(a.x - b.x);
		const float diffy = std::fabs(a.y - b.y);
		const float diffz = std::fabs(a.z - b.z);
		if ((diffx > abs_error) || (diffy > abs_error) || (diffz > abs_error)) return testing::AssertionSuccess();

		return testing::AssertionFailure() << "The difference between " << expr1 << " and " << expr2 << " is too small.";
	}

	void AssertNotEqual(const vec3&a, const vec3& b){
		ASSERT_PRED_FORMAT3(DoubleNotNearPredFormat, a, b, eps);
	}
};