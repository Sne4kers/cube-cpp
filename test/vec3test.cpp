#include <gtest/gtest.h>
#include "fixtures/vec3Test.h"

TEST_F(vec3Test, operatorEqualsTest) {
  EXPECT_TRUE(v0_0_0 == v0_0_0);
  EXPECT_TRUE(v0_0_0 == v0_0_0_1);
  EXPECT_TRUE(v0_0_0_1 == v0_0_0);
  EXPECT_FALSE(v0_0_0 == v2_3_4);
  EXPECT_FALSE(v2_3_4 == v3_5_1);
  EXPECT_FALSE(v3_5_1 == v2_3_4);
  EXPECT_FALSE(v4_0_1 == v3_5_1);
}

TEST_F(vec3Test, operatorNotEqualsTest) {
  EXPECT_FALSE(v0_0_0 != v0_0_0);
  EXPECT_FALSE(v0_0_0 != v0_0_0_1);
  EXPECT_FALSE(v0_0_0_1 != v0_0_0);
  EXPECT_TRUE(v0_0_0 != v2_3_4);
  EXPECT_TRUE(v2_3_4 != v3_5_1);
  EXPECT_TRUE(v3_5_1 != v2_3_4);
  EXPECT_TRUE(v4_0_1 != v3_5_1);
}

TEST_F(vec3Test, operatorPlusTest) {
  EXPECT_EQ(v0_0_0 + v0_0_0, v0_0_0);
  EXPECT_EQ(v0_0_0 + v0_0_0_1, v0_0_0);
  EXPECT_EQ(v2_3_4 + v0_0_0_1, v2_3_4);
  EXPECT_EQ(v4_0_1 + v0_0_0_1, v4_0_1);
  EXPECT_EQ(v4_0_1 + v2_3_4, vec3(6, 3, 5));
  EXPECT_EQ(v2_3_4 + v4_0_1, vec3(6, 3, 5));
  EXPECT_EQ(v2_3_4 + v3_5_1, vec3(5, 8, 5));
}