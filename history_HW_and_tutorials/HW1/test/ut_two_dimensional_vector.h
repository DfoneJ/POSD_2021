#include <iostream>
#include "../src/two_dimensional_vector.h"
#include <math.h>

TEST(CaseTwoDimensionalVector, Create) {
    TwoDimensionalVector vect(3,4);
    ASSERT_NEAR(3.0, vect.x(), 0.001);
    ASSERT_NEAR(4.0, vect.y(), 0.001);
}

TEST(CaseTwoDimensionalVector, Length) {
    TwoDimensionalVector vect(3,4);
    ASSERT_NEAR(5.0, vect.length(), 0.001);
}

TEST(CaseTwoDimensionalVector, DotProduct) {
    TwoDimensionalVector vect1(3,4);
    TwoDimensionalVector vect2(1,1);
    ASSERT_NEAR(7.0, vect1.dot(vect2), 0.001);
}

TEST(CaseTwoDimensionalVector, CrossProduct) {
    TwoDimensionalVector vect1(3,4);
    TwoDimensionalVector vect2(1,2);
    ASSERT_NEAR((3.0*2.0)-(4.0*1.0), vect1.cross(vect2), 0.001);
}

TEST(CaseTwoDimensionalVector, Subtract) {
    TwoDimensionalVector vect1(3,4);
    TwoDimensionalVector vect2(1,1);
    ASSERT_EQ("[2.00,3.00]", vect1.subtract(vect2).info());
}

TEST(CaseTwoDimensionalVector, Info) {
    TwoDimensionalVector vect(3,4);
    ASSERT_EQ(std::string("[3.00,4.00]"), vect.info());
}