#include "../src/utility.h"
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape_iterator.h"
#include "../src/iterator.h"
#include "../src/visitor.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"
#include <gtest/gtest.h>
class VisitorTest : public ::testing::Test {
protected:
  void SetUp() override {

     r34 = new Rectangle("r34", 3, 4);
     r22 = new Rectangle("r22", 2, 2);
     e74 = new Ellipse("e74",7,4);
     triangleVector.clear();
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
     t345 = new Triangle("t345", triangleVector);
     
     shapeList_small.push_back(r34);
     shapeList_small.push_back(r22);
     mbox_small = new CompoundShape("small_box",  shapeList_small);

     shapeList_big.push_back(mbox_small);
     mbox_big = new CompoundShape("big_box",  shapeList_big);
  }

  void TearDown() override {
    delete r34;
    delete r22;
    delete t345;
    delete e74;
    delete mbox_small;
    delete mbox_big; 
  }

    Shape * r34;
    Shape * r22;
    Shape * t345;
    Shape * e74;
    vector<TwoDimensionalCoordinate*> vec;
    vector<TwoDimensionalCoordinate*> triangleVector;
    list<Shape*> shapeList_small;
    list<Shape*> shapeList_big;
    Shape * mbox_small;
    Shape * mbox_big;
};

TEST_F(VisitorTest, VisitorTest_for_area) {
  Visitor *vis = new AreaVisitor();
  r22->accept(vis);
  ASSERT_EQ(4.0 , (dynamic_cast<AreaVisitor*>(vis))->area());
  e74->accept(vis);
  ASSERT_NEAR(87.9646 , (dynamic_cast<AreaVisitor*>(vis))->area(),0.001);
  t345->accept(vis);
  ASSERT_EQ(6.0 , (dynamic_cast<AreaVisitor*>(vis))->area());
}

TEST_F(VisitorTest, VisitorTest_for_info) {
  Visitor *vis = new InfoVisitor();
  r22->accept(vis);
  ASSERT_EQ("Rectangle (2.000, 2.000)" , (dynamic_cast<InfoVisitor*>(vis))->info());
  e74->accept(vis);
  ASSERT_EQ("Ellipse (7.000, 4.000)" , (dynamic_cast<InfoVisitor*>(vis))->info());
  t345->accept(vis);
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])" , (dynamic_cast<InfoVisitor*>(vis))->info());
}

TEST_F(VisitorTest, compound_shape_info_level_3_tree_structure) {
  Visitor *vis = new InfoVisitor();
  mbox_big->accept(vis);
  ASSERT_EQ("Compound Shape {Compound Shape {Rectangle (3.000, 4.000), Rectangle (2.000, 2.000)}}" , (dynamic_cast<InfoVisitor*>(vis))->info());
}

TEST_F(VisitorTest, compound_shape_area_level_3_tree_structure) {
  Visitor *vis = new AreaVisitor();
  mbox_big->accept(vis);
  ASSERT_EQ(16 , (dynamic_cast<AreaVisitor*>(vis))->area());
}