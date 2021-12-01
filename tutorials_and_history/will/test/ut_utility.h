#include "../src/utility.h"
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"
#include <gtest/gtest.h>

class UtilityTest : public ::testing::Test {
protected:
  void SetUp() override {

     r34 = new Rectangle("r34", 3, 4);
     r22 = new Rectangle("r22", 2, 2);
     triangleVector.clear();
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
     t345 = new Triangle("t345", triangleVector);
     shapeList.push_back(r34);
     shapeList.push_back(r22);
     mbox2 = new CompoundShape("4",  shapeList);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
      delete mbox2;

  }

    Shape * r34;
    Shape * r22;
    Shape * t345;
    vector<TwoDimensionalCoordinate*> vec;
    vector<TwoDimensionalCoordinate*> triangleVector;
    list<Shape*> shapeList;
    Shape * mbox2;
};

TEST_F(UtilityTest, UtilityTest_for_exception) {
  try{
      getShapeById(r34,"r34");
      FAIL(); // you want fail but success means this test fail.
    }catch(std::string e){
      EXPECT_EQ(std::string("Only compound shape can get shape!"), e);
    }
}

TEST_F(UtilityTest, UtilityTest_getShapeById){

  Shape * s = getShapeById(mbox2, "r22");
  ASSERT_EQ(r22, s);
}

TEST_F(UtilityTest, compound_shape_filter_shape_by_area){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    std::deque<Shape *> deque1 = filterShape(mShape, AreaFilter(10, 5));
    ASSERT_EQ(1, deque1.size());
}

TEST_F(UtilityTest, compound_shape_filter_shape_by_color){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    list<Shape *> shapes2 = {mShape};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    std::deque<Shape *> deque1 = filterShape(mShape2, ColorFilter("white"));
    ASSERT_EQ(2, deque1.size());
}

TEST_F(UtilityTest, compound_shape_filter_shape_by_perimeter){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    list<Shape *> shapes2 = {mShape};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    std::deque<Shape *> deque1 = filterShape(mShape2, PerimeterFilter(20, 1));
      ASSERT_EQ(3, deque1.size());
}

TEST_F(UtilityTest, compound_shape_filter_shape_by_type){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    list<Shape *> shapes2 = {mShape};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    std::deque<Shape *> deque1 = filterShape(mShape2, TypeFilter("Triangle"));
    ASSERT_EQ(1, deque1.size());
}
