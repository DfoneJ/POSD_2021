#include <iostream>
#include "../src/rectangle.h"

TEST(CaseRectangle, CreateFail) {
    try {
        Rectangle rect(-3.0,4.0);
     }catch(std::string e) {
            ASSERT_EQ(std::string("edges of rectangle should larger than zero"), e);
     }
}

TEST(CaseRectangle, Area) {
    Rectangle rect(3.0,4.0);
    ASSERT_NEAR(3.0 * 4.0, rect.area(), 0.001);
}

TEST(CaseRectangle, Perimeter) {
    Rectangle rect(3.0,4.0);
    ASSERT_NEAR((3.0 + 4.0) * 2, rect.perimeter(), 0.001);
}

TEST(CaseRectangle, Info) {
    Rectangle rect(3.0,4.0);
    ASSERT_EQ(std::string("Rectangle (3.00 4.00)"), rect.info());
}
