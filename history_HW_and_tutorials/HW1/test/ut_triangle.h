#include <iostream>
#include "../src/triangle.h"

TEST(CaseTriangle, CreateFail) {
    try {
        TwoDimensionalVector vect1(3,4);
        TwoDimensionalVector vect2(-3,-4);
        Triangle triangle(vect1,vect2);
     }catch(std::string e) {
            ASSERT_EQ(std::string("vectors cannot make a triangle"), e);
     }
}

TEST(CaseTriangle, Area) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    ASSERT_NEAR(6.0, triangle.area(), 0.001);
}

TEST(CaseTriangle, Perimeter) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    ASSERT_NEAR(3.0 + 4.0 + 5.0, triangle.perimeter(), 0.001);
}

TEST(CaseTriangle, Info) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    ASSERT_EQ(std::string("Triangle ([3.00,0.00] [0.00,4.00])"), triangle.info());
}