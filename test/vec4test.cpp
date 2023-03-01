#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include <iostream>
#include "fixtures/vec4Test.h"

TEST_F(vec4Test, operatorEqualsTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, v0_0_0_0));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, v0_0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0_1, v0_0_0_0));
}

TEST_F(vec4Test, operatorNotEqualsTest) {
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v0_0_0_0_1, v2_3_4_6));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v2_3_4_6, v3_5_1_2));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v3_5_1_2, v2_3_4_6));
    ASSERT_NO_FATAL_FAILURE(AssertNotEqual(v4_0_1_7, v3_5_1_2));
}

TEST_F(vec4Test, operatorPlusTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0 + v0_0_0_0, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0 + v0_0_0_0_1, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 + v0_0_0_0_1, v2_3_4_6));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7 + v0_0_0_0_1, v4_0_1_7));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7 + v2_3_4_6, vec4(6, 3, 5, 13)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 + v4_0_1_7, vec4(6, 3, 5, 13)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 + v3_5_1_2, vec4(5, 8, 5, 8)));
}

TEST_F(vec4Test, operatorMinusTest) {
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0 - v0_0_0_0, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0 - v0_0_0_0_1, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 - v0_0_0_0_1, v2_3_4_6));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7 - v0_0_0_0_1, v4_0_1_7));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7 - v2_3_4_6, vec4(2, -3, -3, 1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 - v4_0_1_7, vec4(-2, 3, 3, -1)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6 - v3_5_1_2, vec4(-1, -2, 3, 4)));
}

TEST_F(vec4Test, operatorPlusEqualTest) {
    vec4 v1 = v0_0_0_0;
    v1 += v0_0_0_0;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, v1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0_1, v1));

    vec4 v2 = v2_3_4_6;
    v2 += v4_0_1_7;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6, vec4(2, 3, 4, 6)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec4(6, 3, 5, 13)));

    vec4 v3 = v0_0_0_0;
    v3 += v4_0_1_7;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7, vec4(4, 0, 1, 7)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec4(4, 0, 1, 7)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, vec4(0, 0, 0, 0)));
}

TEST_F(vec4Test, operatorMinusEqualTest) {
    vec4 v1 = v0_0_0_0;
    v1 -= v0_0_0_0;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, v1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0_1, v1));

    vec4 v2 = v2_3_4_6;
    v2 -= v4_0_1_7;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6, vec4(2, 3, 4, 6)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec4(-2, 3, 3, -1)));

    vec4 v3 = v0_0_0_0;
    v3 -= v4_0_1_7;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v4_0_1_7, vec4(4, 0, 1, 7)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec4(-4, 0, -1, -7)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, vec4(0, 0, 0, 0)));
}

TEST_F(vec4Test, operatorMultiplyTest) {
    vec4 v1 = v0_0_0_0;
    v1 = v1 * 3;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v0_0_0_0, vec4(0, 0, 0, 0)));

    vec4 v2 = v2_3_4_6;
    v2 = v2 * 2;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2, vec4(4, 6, 8, 12)));

    vec4 v3 = v3_5_1_2;
    v3 = v3 * -2;
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v3, vec4(-6, -10, -2, -4)));
}

TEST_F(vec4Test, dotTest) {
    vec4 a = v0_0_0_0;
    vec4 b = v2_3_4_6;
    int res = a.dot(b);
    ASSERT_NEAR(res, 0, eps);

    a = v2_3_4_6;
    b = v0_0_0_0;
    res = a.dot(b);
    ASSERT_NEAR(res, 0, eps);

    a = v2_3_4_6;
    b = v4_0_1_7;
    res = a.dot(b);
    ASSERT_NEAR(res, 54, eps);

    a = v2_3_4_6;
    b = v3_5_1_2;
    res = a.dot(b);
    ASSERT_NEAR(res, 37, eps);
}

TEST_F(vec4Test, multTest) {
    vec4 a = v0_0_0_0;
    vec4 b = v2_3_4_6;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, v0_0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v2_3_4_6));

    a = v2_3_4_6;
    b = v0_0_0_0;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec4(0, 0, 0, 0)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, v0_0_0_0_1));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v0_0_0_0));

    a = v2_3_4_6;
    b = v4_0_1_7;
    a.mult(b);
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(a, vec4(8, 0, 4, 42)));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(b, v4_0_1_7));
    ASSERT_NO_FATAL_FAILURE(AssertEqualVectors(v2_3_4_6, vec4(2, 3, 4, 6)));
}