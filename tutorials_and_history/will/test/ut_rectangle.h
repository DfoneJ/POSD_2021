#include "../src/rectangle.h"
#include <gtest/gtest.h>

TEST(Rectangle, RectangleArea) {
  Rectangle rectangle("1",3.0777, 4.2);
  ASSERT_EQ(12.926, rectangle.area());
}


TEST(Rectangle, RectanglePerimeter) {
  Rectangle rectangle2("1",3.0777, 4.2);
  ASSERT_EQ(14.555, rectangle2.perimeter());
}


TEST(Rectangle, TestRectangleInfo) {
  Rectangle rectangle3("1",3.712, 5);
  ASSERT_EQ("Rectangle (3.712, 5.000)", rectangle3.info());
}

TEST(Rectangle, TestRectangleFail) {
  try{
      Rectangle rectangle4("1",-1.220, 0.301);
      FAIL(); // you want fail but success means this test fail.
    }catch(std::string e){
      EXPECT_EQ(std::string("This is not a rectangle!"), e);
    }
}
