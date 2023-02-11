#include <gtest/gtest.h>
#include "fixtures/vec3Test.h"

TEST_F(vec3Test, operatorEqualsTest) {
	EXPECT_TRUE(v0_0_0.eqWithEps(v0_0_0, eps));
	EXPECT_TRUE(v0_0_0.eqWithEps(v0_0_0_1, eps));
	EXPECT_TRUE(v0_0_0_1.eqWithEps(v0_0_0, eps));
	EXPECT_FALSE(v0_0_0.eqWithEps(v2_3_4, eps));
	EXPECT_FALSE(v2_3_4.eqWithEps(v3_5_1, eps));
	EXPECT_FALSE(v3_5_1.eqWithEps(v2_3_4, eps));
	EXPECT_FALSE(v4_0_1.eqWithEps(v3_5_1, eps));
}

TEST_F(vec3Test, operatorPlusTest) {
	EXPECT_TRUE((v0_0_0 + v0_0_0).eqWithEps(v0_0_0, eps));
	EXPECT_TRUE((v0_0_0 + v0_0_0_1).eqWithEps(v0_0_0, eps));
	EXPECT_TRUE((v2_3_4 + v0_0_0_1).eqWithEps(v2_3_4, eps));
	EXPECT_TRUE((v4_0_1 + v0_0_0_1).eqWithEps(v4_0_1, eps));
	EXPECT_TRUE((v4_0_1 + v2_3_4).eqWithEps(vec3(6, 3, 5), eps));
	EXPECT_TRUE((v2_3_4 + v4_0_1).eqWithEps(vec3(6, 3, 5), eps));
	EXPECT_TRUE((v2_3_4 + v3_5_1).eqWithEps(vec3(5, 8, 5), eps));
}

TEST_F(vec3Test, operatorMinusTest) {
	EXPECT_TRUE((v0_0_0 - v0_0_0).eqWithEps(v0_0_0, eps));
	EXPECT_TRUE((v0_0_0 - v0_0_0_1).eqWithEps(v0_0_0, eps));
	EXPECT_TRUE((v2_3_4 - v0_0_0_1).eqWithEps(v2_3_4, eps));
	EXPECT_TRUE((v4_0_1 - v0_0_0_1).eqWithEps(v4_0_1, eps));
	EXPECT_TRUE((v4_0_1 - v2_3_4).eqWithEps(vec3(2, -3, -3), eps));
	EXPECT_TRUE((v2_3_4 - v4_0_1).eqWithEps(vec3(-2, 3, 3), eps));
	EXPECT_TRUE((v2_3_4 - v3_5_1).eqWithEps(vec3(-1, -2, 3), eps));
}

TEST_F(vec3Test, operatorPlusEqualTest) {
	vec3 v1 = v0_0_0;
	v1 += v0_0_0;
	EXPECT_TRUE(v0_0_0.eqWithEps(vec3(), eps));
	EXPECT_TRUE(v0_0_0.eqWithEps(v1, eps));
	EXPECT_TRUE(v0_0_0_1.eqWithEps(v1, eps));

	vec3 v2 = v2_3_4;
	v2 += v4_0_1;
	EXPECT_TRUE(v2_3_4.eqWithEps(vec3(2, 3, 4), eps));
	EXPECT_TRUE(v2.eqWithEps(vec3(6, 3, 5), eps));

	vec3 v3 = v0_0_0;
	v3 += v4_0_1;
	EXPECT_TRUE(v4_0_1.eqWithEps(vec3(4, 0, 1), eps));
	EXPECT_TRUE(v3.eqWithEps(vec3(4, 0, 1), eps));
	EXPECT_TRUE(v0_0_0.eqWithEps(vec3(0, 0, 0), eps));
}

TEST_F(vec3Test, operatorMinusEqualTest) {
	vec3 v1 = v0_0_0;
	v1 -= v0_0_0;
	EXPECT_TRUE(v0_0_0.eqWithEps(vec3(), eps));
	EXPECT_TRUE(v0_0_0.eqWithEps(v1, eps));
	EXPECT_TRUE(v0_0_0_1.eqWithEps(v1, eps));

	vec3 v2 = v2_3_4;
	v2 -= v4_0_1;
	EXPECT_TRUE(v2_3_4.eqWithEps(vec3(2, 3, 4), eps));
	EXPECT_TRUE(v2.eqWithEps(vec3(-2, 3, 3), eps));

	vec3 v3 = v0_0_0;
	v3 -= v4_0_1;
	EXPECT_TRUE(v4_0_1.eqWithEps(vec3(4, 0, 1), eps));
	EXPECT_TRUE(v3.eqWithEps(vec3(-4, 0, -1), eps));
	EXPECT_TRUE(v0_0_0.eqWithEps(vec3(0, 0, 0), eps));
}

TEST_F(vec3Test, multTest) {
	vec3 a = v0_0_0;
	vec3 b = v2_3_4;
	a.mult(b);
	EXPECT_TRUE(a.eqWithEps(v0_0_0, eps));
	EXPECT_TRUE(a.eqWithEps(v0_0_0_1, eps));
	EXPECT_TRUE(b.eqWithEps(v2_3_4, eps));

	a = v2_3_4;
	b = v0_0_0;
	a.mult(b);
	EXPECT_TRUE(a.eqWithEps(v0_0_0, eps));
	EXPECT_TRUE(a.eqWithEps(v0_0_0_1, eps));
	EXPECT_TRUE(b.eqWithEps(v0_0_0, eps));

	a = v2_3_4;
	b = v4_0_1;
	a.mult(b);
	EXPECT_TRUE(a.eqWithEps(vec3(8, 0, 4), eps));
	EXPECT_TRUE(b.eqWithEps(v4_0_1, eps));
	EXPECT_TRUE(v2_3_4.eqWithEps(vec3(v2_3_4), eps));
}