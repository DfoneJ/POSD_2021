#include <iostream>
#include "../src/circle.h"

TEST(CaseCircle, CreateFail) {
    try {
        Circle c(-10.0);
     }catch(std::string e) {
            ASSERT_EQ(std::string("radius of circle should larger than zero"), e);
     }
}

TEST(CaseCircle, Area) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
}

TEST(CaseCircle, Perimeter) {
    Circle c(10.0);
    ASSERT_NEAR(2*10.0*3.141592, c.perimeter(), 0.001);
}

TEST(CaseCircle, Info) {
    Circle c(10.0);
    ASSERT_EQ(std::string("Circle (10.00)"), c.info());
}