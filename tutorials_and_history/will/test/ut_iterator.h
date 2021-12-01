#include "../src/iterator.h"
#include "../src/null_iterator.h"
#include "../src/shape_iterator.h"
#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../src/utility.h"
#include <gtest/gtest.h>
class IteratorTest : public ::testing::Test {
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
     e74 = new Ellipse("1",7, 4);

  }

  void TearDown() override {
      delete r34;
      delete r22;
      delete t345;
      delete it;
  }

    Shape * r34;
    Shape * r22;
    Shape * t345;
    Shape * e74;
    Iterator * it;
};

TEST_F(IteratorTest, triangle_iterate_is_done){
  it = t345->createIterator();
  EXPECT_EQ(true, it->isDone());
}

TEST_F(IteratorTest, exception_for_triangle_iterate_next){
  it = t345->createIterator();
  try{
      it->next();
      FAIL(); // you want fail but success means this test fail.

    }catch(std::string e){
      EXPECT_EQ(std::string("No child member!"), e);
    }
}

TEST_F(IteratorTest, exception_for_triangle_iterate_first){
  it = t345->createIterator();
  try{
      it->first();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}
TEST_F(IteratorTest, exception_for_triangle_iterate_current_item){
  it = t345->createIterator();
  try{
      it->currentItem();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}


TEST_F(IteratorTest, rectangle_iterate_is_done){
  it = r34->createIterator();
  EXPECT_EQ(true, it->isDone());
}

TEST_F(IteratorTest, exception_for_rectangle_iterate_next){
  it = r34->createIterator();
  try{
      it->next();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}

TEST_F(IteratorTest, exception_for_rectangle_iterate_first){
  it = r34->createIterator();
  try{
      it->first();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}

TEST_F(IteratorTest, exception_for_rectangle_iterate_current_item){
  it = r34->createIterator();
  try{
      it->currentItem();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}

TEST_F(IteratorTest, ellipse_iterate_is_done){
  it = e74->createIterator();
  EXPECT_EQ(true, it->isDone());
}


TEST_F(IteratorTest, exception_for_ellipse_iterate_next){
  it = e74->createIterator();
  try{
      it->next();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}


TEST_F(IteratorTest, exception_for_ellipse_iterate_first){
  it = e74->createIterator();
  try{
      it->first();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}


TEST_F(IteratorTest, exception_for_ellipse_iterate_current_item){
  it = e74->createIterator();
  try{
      it->currentItem();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("No child member!"), e);
  }
}

TEST_F(IteratorTest, exception_for_compound_shape_iterate_next_out_of_range){
  list<Shape *> shapes = {r22};
  CompoundShape * mShape = new CompoundShape("m1", shapes);
  it = mShape->createIterator();
  try{
      it->next();
      it->next();
      FAIL(); // you want fail but success means this test fail.

  }catch(std::string e){
        EXPECT_EQ(std::string("Moving past the end!"), e);
  }
}

TEST_F(IteratorTest, compound_shape_iterate_is_done){
  list<Shape *> shapes = {r22};
  CompoundShape * mShape = new CompoundShape("m1", shapes);
  it = mShape->createIterator();
  it->next();
  EXPECT_EQ(true,it->isDone());
}

TEST_F(IteratorTest, compound_shape_iterate_first){
  list<Shape *> shapes = {r22};
  CompoundShape * mShape = new CompoundShape("m1", shapes);
  it = mShape->createIterator();
  it->first();
  EXPECT_EQ(r22,it->currentItem());
}

TEST_F(IteratorTest, compound_shape_iterate_current_next){
  list<Shape *> shapes = {t345,r22};
  CompoundShape * mShape = new CompoundShape("m1", shapes);
  it = mShape->createIterator();
  it->next();
  EXPECT_EQ(r22,it->currentItem());
}

TEST_F(IteratorTest, compound_shape_iterate_current_item){
  list<Shape *> shapes = {r22};
  CompoundShape * mShape = new CompoundShape("m1", shapes);
  it = mShape->createIterator();
  EXPECT_EQ(r22,it->currentItem());
}
