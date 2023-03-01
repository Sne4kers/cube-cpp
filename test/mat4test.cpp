#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include "fixtures/mat4Test.h"

TEST_F(mat4Test, identityTest) {
    mat4 m1 = mat4::identity();
    AssertEqualVectors(m1[0], vec4(1, 0, 0, 0));
    AssertEqualVectors(m1[1], vec4(0, 1, 0, 0));
    AssertEqualVectors(m1[2], vec4(0, 0, 1, 0));
    AssertEqualVectors(m1[3], vec4(0, 0, 0, 1));
}

TEST_F(mat4Test, arbitraryAccessOperatorTest) {
    mat4 m1 = mat4(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    AssertEqualVectors(m1[0], vec4(1, 2, 3, 4));
    AssertEqualVectors(m1[1], vec4(5, 6, 7, 8));
    AssertEqualVectors(m1[2], vec4(9, 10, 11, 12));
    AssertEqualVectors(m1[3], vec4(13, 14, 15, 16));
    m1[0] = vec4(9, 10, 11, 12);
    m1[1] = vec4(1, 2, 3, 4);
    m1[2] = vec4(5, 6, 7, 8);
    m1[3] = vec4(13, 14, 15, 16);
    AssertEqualVectors(m1[0], vec4(9, 10, 11, 12));
    AssertEqualVectors(m1[1], vec4(1, 2, 3, 4));
    AssertEqualVectors(m1[2], vec4(5, 6, 7, 8));
    AssertEqualVectors(m1[3], vec4(13, 14, 15, 16));
}

TEST_F(mat4Test, identityMultiplicationTest) {
    mat4 m1 = mat4::identity();
    mat4 m2 = mat4::identity();
    AssertEqual(m1 * m2, m1);
}

TEST_F(mat4Test, arbitraryMatrixWithIdentityMatrixMultiplicationTest) {
    mat4 m1 = mat4::identity();
    mat4 m2 = mat4(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    AssertEqual(m1 * m2, m2);
    AssertEqual(m2 * m1, m2);

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[1].y = 0;
    AssertEqual(m1 * m2, m2);

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[2].z = 0;
    AssertEqual(m2 * m1, m2);
}


TEST_F(mat4Test, arbitraryMatrixMultiplicationTest) {
    /**
     * m1:
     * 2.97454, -1.74289, -2.69386, 9.58109
     * -2.69919, -4.11655, -7.11382, -7.89131
     * 5.79252, 1.47907, 2.44971, 0.68853
     * 1.84397, 2.12680, -0.44402, 6.05276

     * 
     * m2:
     * -7.99430, 1.28164, 1.33088, -6.81126
     * 3.87757, -8.79781, 1.83503, 0.32153
     * 9.14860, 0.05920, 2.00345, 5.34815
     * 7.58397, -4.92573, -8.31475, 2.96333
     * 
     * m3(result) :
     *  (-32.0894 | 46.5033 | 48.5199 | -6.84476
-3.86047 | 32.8564 | -1.85102 | 1.0633
18.7028 | 56.4929 | -22.533 | -7.0739
-127.018 | 109.787 | 120.937 | 123.745)
    */
   
    mat4 m1 = mat4(
        vec4(2.97454, -1.74289, -2.69386, 9.58109),
        vec4(-2.69919, -4.11655, -7.11382, -7.89131),
        vec4(5.79252, 1.47907, 2.44971, 0.68853),
        vec4(1.84397, 2.12680, -0.44402, 6.05276)
    );

    mat4 m2 = mat4(
        vec4(-7.99430, 1.28164, 1.33088, -6.81126),
        vec4(3.87757, -8.79781, 1.83503, 0.32153),
        vec4(9.14860, 0.05920, 2.00345, 5.34815),
        vec4(7.58397, -4.92573, -8.31475, 2.96333)
    );

    mat4 m3 = mat4(
        vec4(-32.0894, -3.86047, 18.7028, -127.018),
        vec4(46.5033, 32.8564, 56.4929, 109.787),
        vec4(48.5199, -1.85102, -22.533, 120.937),
        vec4(-6.84476, 1.0633, -7.0739, 123.745)
    );
    AssertEqual(m1 * m2, m3);
}

TEST_F(mat4Test, arbitraryMatrixAdditionTest) {
    mat4 m1 = mat4::identity();
    mat4 m2 = mat4::identity();
    AssertEqual(m1 + m2, mat4(vec4(2, 0, 0, 0), vec4(0, 2, 0, 0), vec4(0, 0, 2, 0), vec4(0, 0, 0, 2)));
    AssertEqual(m2 + m1, mat4(vec4(2, 0, 0, 0), vec4(0, 2, 0, 0), vec4(0, 0, 2, 0), vec4(0, 0, 0, 2)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[1].y = 0;
    AssertEqual(m1 + m2, mat4(vec4(2, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 2, 0), vec4(0, 0, 0, 2)));
    AssertEqual(m2 + m1, mat4(vec4(2, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 2, 0), vec4(0, 0, 0, 2)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    m2[3].w = -1;
    AssertEqual(m1 + m2, mat4(vec4(2, 0, -1, 0), vec4(-1, -1, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 0)));
    AssertEqual(m2 + m1, mat4(vec4(2, 0, -1, 0), vec4(-1, -1, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 0)));
}

TEST_F(mat4Test, arbitraryMatrixSubtractionTest) {
    mat4 m1 = mat4::identity();
    mat4 m2 = mat4::identity();
    AssertEqual(m1 - m2, mat4(vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));
    AssertEqual(m2 - m1, mat4(vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[1].y = 0;
    AssertEqual(m2 - m1, mat4(vec4(0, 0, 0, 0), vec4(0, -1, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));
    AssertEqual(m1 - m2, mat4(vec4(0, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    m2[3].w = -1;
    AssertEqual(m2 - m1, mat4(vec4(0, 0, -1, 0), vec4(-1, -3, 0, 0), vec4(0, 0, -1, 0), vec4(0, 0, 0, -2)));
    AssertEqual(m1 - m2, mat4(vec4(0, 0, 1, 0), vec4(1, 3, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 2)));
}

TEST_F(mat4Test, arbitraryMatrixSubtractionAndCopyTest) {
    mat4 m1 = mat4::identity();
    mat4 m2 = mat4::identity();

    m1 -= m2;
    AssertEqual(m1, mat4(vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[1].y = 0;
    m1 -= m2;
    AssertEqual(m1, mat4(vec4(0, 0, 0, 0), vec4(0, 1, 0, 0), vec4(0, 0, 0, 0), vec4(0, 0, 0, 0)));

    m1 = mat4::identity();
    m2 = mat4::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    m2[3].w = -1;
    m1 -= m2;
    AssertEqual(m1, mat4(vec4(0, 0, 1, 0), vec4(1, 3, 0, 0), vec4(0, 0, 1, 0), vec4(0, 0, 0, 2)));
}

TEST_F(mat4Test, multiplyByFloatTest) {
    mat4 m1 = mat4(vec4(1, 2, 3, 4), vec4(5, 6, 7, 8), vec4(9, 10, 11, 12), vec4(13, 14, 15, 16));
    float a = 7.314;
    m1 = m1 * a;
    AssertEqualVectors(m1[0], vec4(1, 2, 3, 4) * a);
    AssertEqualVectors(m1[1], vec4(5, 6, 7, 8) * a);
    AssertEqualVectors(m1[2], vec4(9, 10, 11, 12) * a);
    AssertEqualVectors(m1[3], vec4(13, 14, 15, 16) * a);
}
