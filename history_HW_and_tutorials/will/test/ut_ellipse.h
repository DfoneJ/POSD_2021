#include "../src/ellipse.h"
#include <gtest/gtest.h>
TEST(Ellipse, EllipsePerimeter) {
  Ellipse("1",7, 4);
  // Ellipse ellipse(7, 4);
  ASSERT_NEAR(37.1327, Ellipse("1",7, 4).perimeter(),0.001);
}

TEST(Ellipse, EllipseArea) {
  Ellipse ellipse2("1",7, 4);
  ASSERT_NEAR(87.9646, ellipse2.area(),0.001);

}

TEST(Ellipse, TestEllipseInfo) {
  Ellipse ellipse3("1",7, 4);
  EXPECT_EQ("Ellipse (7.000, 4.000)", ellipse3.info());

}

TEST(Ellipse, TestEllipseFail1) {
  try{
      Ellipse ellipse("1",1, 4.301);
      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("This is not an ellipse!"), e);
    }
}

TEST(Ellipse, TestEllipseFail2) {
  try{
      Ellipse ellipse("1",-1.220, 0.301);
      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("This is not an ellipse!"), e);
    }
}

TEST(Ellipse, TestEllipse_Add_Shape) {
  try{
      Ellipse ellipse("1",12, 6);
      Shape * r34 = new Rectangle("1",3,4);
      ellipse.addShape(r34);
      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("Only compound shape can add shape!"), e);
    }
}

TEST(Ellipse, TestEllipse_Delete_Shape) {
  try{
      Ellipse ellipse("1",12, 6);
      ellipse.deleteShapeById("123");

      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("Only compound shape can delete shape!"), e);
    }
}

TEST(Ellipse, TestEllipse_Get_Shape) {
  try{
      Ellipse ellipse("1",12, 6);
      ellipse.deleteShapeById("123");

      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("Only compound shape can delete shape!"), e);
    }
}
