#include "lalgebra.h"
#include "cmath"
using namespace lalgebra;

class vec4Test : public ::testing::Test {
protected:
    vec4 v0_0_0_0;
    vec4 v0_0_0_0_1;
    vec4 v2_3_4_6;
    vec4 v3_5_1_2;
    vec4 v4_0_1_7;
    static constexpr float eps = 0.0001f;

protected:
    void SetUp() override {
        v0_0_0_0 = vec4();
        v0_0_0_0_1 = vec4(0, 0, 0, 0);
        v2_3_4_6 = vec4(2, 3, 4, 6);
        v3_5_1_2 = vec4(3, 5, 1, 2);
        v4_0_1_7 = vec4(4, 0, 1, 7);
    }
public:
    static void AssertEqualVectors(const vec4& a, const vec4& b) {
        ASSERT_NEAR(a.x, b.x, eps);
        ASSERT_NEAR(a.y, b.y, eps);
        ASSERT_NEAR(a.z, b.z, eps);
		ASSERT_NEAR(a.w, b.w, eps);
    }

    static void AssertEqualVectors(const vec4& a, const vec4& b, float new_eps) {
        ASSERT_NEAR(a.x, b.x, new_eps);
        ASSERT_NEAR(a.y, b.y, new_eps);
        ASSERT_NEAR(a.z, b.z, new_eps);
		ASSERT_NEAR(a.w, b.w, new_eps);
    }

    testing::AssertionResult DoubleNotNearPredFormat(const char* expr1, const char* expr2,
                                     const char* abs_error_expr, const vec4&a,
                                     const vec4& b, float abs_error) {
        const float diffx = std::fabs(a.x - b.x);
        const float diffy = std::fabs(a.y - b.y);
        const float diffz = std::fabs(a.z - b.z);
		const float diffw = std::fabs(a.w - b.w);
        if ((diffx > abs_error) || (diffy > abs_error) || (diffz > abs_error) || (diffw > abs_error)) return testing::AssertionSuccess();

        return testing::AssertionFailure() << "The difference between " << expr1 << " and " << expr2 << " is too small.";
    }

    void AssertNotEqual(const vec4&a, const vec4& b){
        ASSERT_PRED_FORMAT3(DoubleNotNearPredFormat, a, b, eps);
    }
};