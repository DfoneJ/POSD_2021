#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../src/utility.h"
#include <deque>
class CompoundShapeTest : public ::testing::Test {
protected:
  void SetUp() override {
     vector<TwoDimensionalCoordinate*> triangleVector;
     r34 = new Rectangle("r34", 3, 4);
     r22 = new Rectangle("r22", 2, 2);
     triangleVector.clear();
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
     triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
     t345 = new Triangle("t345", triangleVector);
  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
  }

    Shape * r34;
    
    Shape * r22;
    Shape * t345;
};

TEST_F(CompoundShapeTest, CreateCompoundShape){
    ASSERT_EQ("Rectangle", r22->type());
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    Shape * br34 = new Rectangle("br34", 3, 4, "blue");
    mShape->addShape(br34);
    ASSERT_EQ("r22", mShape->getShapeById("r22")->id());
    ASSERT_EQ("br34", mShape->getShapeById("br34")->id());
    ASSERT_EQ("white", mShape->getShapeById("r22")->color());
    ASSERT_EQ("blue", mShape->getShapeById("br34")->color());

  
}

TEST_F(CompoundShapeTest, Compound_Shape_GetShapeByID_Not_Found) {
  try{
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    list<Shape *> shapes2 = {r34};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    mShape2->addShape(mShape);
      EXPECT_EQ("m1", mShape2->getShapeById("5")->id());
      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("Expected get shape but shape not found"), e);
    }
}

TEST_F(CompoundShapeTest, AddCompoundShapeToCompoundShape){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    list<Shape *> shapes2 = {r34};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    mShape2->addShape(mShape);
    ASSERT_EQ("m1", mShape2->getShapeById("m1")->id());
}

TEST_F(CompoundShapeTest, CompoundShapeArea){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    ASSERT_EQ(10, mShape->area());
    mShape->addShape(r34);
    ASSERT_EQ(22, mShape->area());
}

TEST_F(CompoundShapeTest, CompoundShapePerimeter){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    ASSERT_EQ(20, mShape->perimeter());
    mShape->addShape(r34);
    ASSERT_EQ(34, mShape->perimeter());
}

TEST_F(CompoundShapeTest, CompoundShapeInfo){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    ASSERT_EQ("Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", mShape->info());
    mShape->addShape(r34);
    ASSERT_EQ("Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000)}", mShape->info());
    list<Shape *> shapes2 = {mShape, r34};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    ASSERT_EQ("Compound Shape {Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000)}, Rectangle (3.000, 4.000)}", mShape2->info());
}

TEST_F(CompoundShapeTest, GetShapeById){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    ASSERT_EQ(r22, mShape->getShapeById("r22"));
}

TEST_F(CompoundShapeTest, DeleteShapeById){
    list<Shape *> shapes = {r22, t345};
    CompoundShape * mShape = new CompoundShape("m1", shapes);
    mShape->deleteShapeById("r22");
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", mShape->info());
    try {
        mShape->deleteShapeById("r34");
        FAIL();
    }catch(string e) {
      ASSERT_EQ("Expected delete shape but shape not found", e);
    }

    mShape->addShape(r34);
    ASSERT_EQ(r34, mShape->getShapeById("r34"));
    list<Shape *> shapes2 = {mShape, r22};
    CompoundShape * mShape2 = new CompoundShape("m2", shapes2);
    mShape2->deleteShapeById("r34");
    ASSERT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}, Rectangle (2.000, 2.000)}", mShape2->info());
    mShape2->deleteShapeById("m1");
    ASSERT_EQ("Compound Shape {Rectangle (2.000, 2.000)}", mShape2->info());
}
