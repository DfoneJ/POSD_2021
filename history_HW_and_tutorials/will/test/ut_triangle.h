#include "../src/triangle.h"
#include <gtest/gtest.h>
TEST(Triangle, TriangleArea) {
  TwoDimensionalCoordinate t1(1, 0);
  TwoDimensionalCoordinate t2(1, 3);
  TwoDimensionalCoordinate t3(5, 0);
  vector<TwoDimensionalCoordinate*> vec;

  vec.push_back(&t1);
  vec.push_back(&t2);
  vec.push_back(&t3);

  Triangle triangle("1",vec);
  ASSERT_EQ(6, triangle.area());
}

TEST(Triangle, TrianglePerimeter) {
  TwoDimensionalCoordinate t1(1, 0);
  TwoDimensionalCoordinate t2(1, 3);
  TwoDimensionalCoordinate t3(5, 0);
  vector<TwoDimensionalCoordinate*> vec;

  vec.push_back(&t1);
  vec.push_back(&t2);
  vec.push_back(&t3);
  Triangle triangle2("1",vec);
  ASSERT_EQ(12, triangle2.perimeter());
}


TEST(Triangle, TestTriangleInfo) {
  TwoDimensionalCoordinate t1(1, 0);
  TwoDimensionalCoordinate t2(1, 3);
  TwoDimensionalCoordinate t3(5.0000, 0);
  vector<TwoDimensionalCoordinate*> vec;

  vec.push_back(&t1);
  vec.push_back(&t2);
  vec.push_back(&t3);
  Triangle triangle3("1",vec);
  ASSERT_EQ("Triangle ([1.000, 0.000], [1.000, 3.000], [5.000, 0.000])", triangle3.info());

}

TEST(Triangle, TestTriangleFail) {
  try{
      TwoDimensionalCoordinate t1(0, 0);
      TwoDimensionalCoordinate t2(5, 0);
      // TwoDimensionalCoordinate t3(100, 0);
      vector<TwoDimensionalCoordinate*> vec;

      vec.push_back(&t1);
      vec.push_back(&t2);
      // vec.push_back(&t3);
      Triangle triangle4("1",vec);
       FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("This is not a triangle!"), e);
    }
}
