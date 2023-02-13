#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include "fixtures/mat3Test.h"

TEST_F(mat3Test, identityTest) {
    mat3 m1 = mat3::identity();
    AssertEqualVectors(m1[0], vec3(1, 0, 0));
    AssertEqualVectors(m1[1], vec3(0, 1, 0));
    AssertEqualVectors(m1[2], vec3(0, 0, 1));
}

TEST_F(mat3Test, arbitraryAccessOperatorTest) {
    mat3 m1 = mat3(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    AssertEqualVectors(m1[0], vec3(1, 2, 3));
    AssertEqualVectors(m1[1], vec3(4, 5, 6));
    AssertEqualVectors(m1[2], vec3(7, 8, 9));
    m1[0] = vec3(7, 8, 9);
    m1[1] = vec3(1, 2, 3);
    m1[2] = vec3(4, 5, 6);
    AssertEqualVectors(m1[0], vec3(7, 8, 9));
    AssertEqualVectors(m1[1], vec3(1, 2, 3));
    AssertEqualVectors(m1[2], vec3(4, 5, 6));
}

TEST_F(mat3Test, identityMultiplicationTest) {
    mat3 m1 = mat3::identity();
    mat3 m2 = mat3::identity();
    AssertEqual(m1 * m2, m1);
}

TEST_F(mat3Test, arbitraryMatrixWithIdentityMatrixMultiplicationTest) {
    mat3 m1 = mat3::identity();
    mat3 m2 = mat3(vec3(1, 2, 3), vec3(-4, 36, 21), vec3(40, -2, 3));
    AssertEqual(m1 * m2, m2);
    AssertEqual(m2 * m1, m2);

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[1].y = 0;
    AssertEqual(m1 * m2, m2);

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[2].z = 0;
    AssertEqual(m2 * m1, m2);
}


TEST_F(mat3Test, arbitraryMatrixMultiplicationTest) {
    /**
     * m1:
     * -4.09755 -1.58540 -7.06654
     *  5.83669  9.89618 -4.98566 
     *  4.47466  0.34960  0.24267
     * 
     * m2:
     *  2.79266 -1.70527 -3.34876
     *  1.60378 -7.08394 -9.69886
     *  -4.45109  2.61593 -0.45078
     * 
     * m3(result) :
     *  17.46810 -0.2672664177 32.28373
     *  54.36280 -93.09921 -113.27990
     *  11.97673 -9.47224 -18.48467
    */
   
    mat3 m1 = mat3(vec3(-4.09755, 5.83669, 4.47466), vec3(-1.58540, 9.89618, 0.34960), vec3(-7.06654, -4.98566, 0.24267));
    mat3 m2 = mat3(vec3(2.79266, 1.60378, -4.45109), vec3(-1.70527, -7.08394, 2.61593), vec3(-3.34876, -9.69886, -0.45078));
    mat3 m3 = mat3(vec3(17.46810, 54.36280, 11.97673), vec3(-0.2672664177, -93.09921, -9.47224), vec3(32.28373, -113.27990, -18.48467));
    AssertEqual(m1 * m2, m3);
}

TEST_F(mat3Test, arbitraryMatrixAdditionTest) {
    mat3 m1 = mat3::identity();
    mat3 m2 = mat3::identity();
    AssertEqual(m1 + m2, mat3(vec3(2, 0, 0), vec3(0, 2, 0), vec3(0, 0, 2)));
    AssertEqual(m2 + m1, mat3(vec3(2, 0, 0), vec3(0, 2, 0), vec3(0, 0, 2)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[1].y = 0;
    AssertEqual(m1 + m2, mat3(vec3(2, 0, 0), vec3(0, 1, 0), vec3(0, 0, 2)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    AssertEqual(m1 + m2, mat3(vec3(2, 0, -1), vec3(-1, -1, 0), vec3(0, 0, 1)));
}

TEST_F(mat3Test, arbitraryMatrixSubtractionTest) {
    mat3 m1 = mat3::identity();
    mat3 m2 = mat3::identity();
    AssertEqual(m1 - m2, mat3(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0)));
    AssertEqual(m2 - m1, mat3(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[1].y = 0;
    AssertEqual(m1 - m2, mat3(vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 0, 0)));
    AssertEqual(m2 - m1, mat3(vec3(0, 0, 0), vec3(0, -1, 0), vec3(0, 0, 0)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    AssertEqual(m1 - m2, mat3(vec3(0, 0, 1), vec3(1, 3, 0), vec3(0, 0, 1)));
    AssertEqual(m2 - m1, mat3(vec3(0, 0, -1), vec3(-1, -3, 0), vec3(0, 0, -1)));
}

TEST_F(mat3Test, arbitraryMatrixSubtractionAndCopyTest) {
    mat3 m1 = mat3::identity();
    mat3 m2 = mat3::identity();
    m1 -= m2;
    AssertEqual(m1, mat3(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[1].y = 0;
    m1 -= m2;
    AssertEqual(m1, mat3(vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 0, 0)));

    m1 = mat3::identity();
    m2 = mat3::identity();
    m2[2].z = 0;
    m2[1].y = -2;
    m2[1].x = -1;
    m2[0].z = -1;
    m1 -= m2;
    AssertEqual(m1, mat3(vec3(0, 0, 1), vec3(1, 3, 0), vec3(0, 0, 1)));
}

TEST_F(mat3Test, multiplyByFloatTest) {
    mat3 m1 = mat3(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
    m1 = m1 * 3.5;
    AssertEqualVectors(m1[0], vec3(1, 2, 3) * 3.5);
    AssertEqualVectors(m1[1], vec3(4, 5, 6) * 3.5);
    AssertEqualVectors(m1[2], vec3(7, 8, 9) * 3.5);
}
