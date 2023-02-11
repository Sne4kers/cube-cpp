#include "lalgebra.h"
using namespace lalgebra;

class vec3Test : public ::testing::Test {
	protected:
		vec3 v0_0_0;
		vec3 v0_0_0_1;
		vec3 v2_3_4;
		vec3 v3_5_1;
		vec3 v4_0_1;
		float eps = 0.0001;

		void SetUp() override {
			v0_0_0 = vec3();
			v0_0_0_1 = vec3(0, 0, 0);
			v2_3_4 = vec3(2, 3, 4);
			v3_5_1 = vec3(3, 5, 1);
			v4_0_1 = vec3(4, 0, 1);
		}
};