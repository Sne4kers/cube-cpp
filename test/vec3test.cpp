#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include "fixtures/vec3Test.h"

TEST_F(vec3Test, operatorEqualsTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, v0_0_0));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, v0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_1, v0_0_0));
}

TEST_F(vec3Test, operatorNotEqualsTest) {
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v0_0_0_1, v2_3_4));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v2_3_4, v3_5_1));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v3_5_1, v2_3_4));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v4_0_1, v3_5_1));
}

TEST_F(vec3Test, operatorPlusTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0 + v0_0_0, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0 + v0_0_0_1, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 + v0_0_0_1, v2_3_4));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1 + v0_0_0_1, v4_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1 + v2_3_4, vec3(6, 3, 5)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 + v4_0_1, vec3(6, 3, 5)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 + v3_5_1, vec3(5, 8, 5)));
}

TEST_F(vec3Test, operatorMinusTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0 - v0_0_0, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0 - v0_0_0_1, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 - v0_0_0_1, v2_3_4));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1 - v0_0_0_1, v4_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1 - v2_3_4, vec3(2, -3, -3)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 - v4_0_1, vec3(-2, 3, 3)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4 - v3_5_1, vec3(-1, -2, 3)));
}

TEST_F(vec3Test, operatorPlusEqualTest) {
    vec3 v1 = v0_0_0;
    v1 += v0_0_0;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, v1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_1, v1));

    vec3 v2 = v2_3_4;
    v2 += v4_0_1;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4, vec3(2, 3, 4)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec3(6, 3, 5)));

    vec3 v3 = v0_0_0;
    v3 += v4_0_1;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1, vec3(4, 0, 1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec3(4, 0, 1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, vec3(0, 0, 0)));
}

TEST_F(vec3Test, operatorMinusEqualTest) {
    vec3 v1 = v0_0_0;
    v1 -= v0_0_0;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, v1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_1, v1));

    vec3 v2 = v2_3_4;
    v2 -= v4_0_1;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4, vec3(2, 3, 4)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec3(-2, 3, 3)));

    vec3 v3 = v0_0_0;
    v3 -= v4_0_1;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1, vec3(4, 0, 1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec3(-4, 0, -1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, vec3(0, 0, 0)));
}

TEST_F(vec3Test, operatorMultiplyTest) {
    vec3 v1 = v0_0_0;
    v1 = v1 * 3;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0, vec3(0, 0, 0)));

    vec3 v2 = v2_3_4;
    v2 = v2 * 2;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec3(4, 6, 8)));

    vec3 v3 = v3_5_1;
    v3 = v3 * -2;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec3(-6, -10, -2)));
}

TEST_F(vec3Test, dotTest) {
    vec3 a = v0_0_0;
    vec3 b = v2_3_4;
    int res = a.dot(b);
    ASSERT_NEAR(res, 0, eps);

    a = v2_3_4;
    b = v0_0_0;
    res = a.dot(b);
    ASSERT_NEAR(res, 0, eps);

    a = v2_3_4;
    b = v4_0_1;
    res = a.dot(b);
    ASSERT_NEAR(res, 12, eps);

    a = v2_3_4;
    b = v3_5_1;
    res = a.dot(b);
    ASSERT_NEAR(res, 25, eps);
}

TEST_F(vec3Test, multTest) {
    vec3 a = v0_0_0;
    vec3 b = v2_3_4;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, v0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v2_3_4));

    a = v2_3_4;
    b = v0_0_0;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec3(0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, v0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v0_0_0));

    a = v2_3_4;
    b = v4_0_1;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec3(8, 0, 4)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v4_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4, vec3(2, 3, 4)));
}