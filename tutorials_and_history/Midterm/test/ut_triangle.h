#include <iostream>
#include "../src/triangle.h"

TEST(CaseTriangle, CreateFail) {
    try {
        TwoDimensionalVector vect1(3,4);
        TwoDimensionalVector vect2(-3,-4);
        Triangle triangle(vect1,vect2);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("vectors are paralleled !"), e);
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

TEST(CaseTriangle, CreateIterator) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    Iterator* tit = triangle.createIterator();
    // first
    try {
        tit->first();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no first()!"), e);
    }
    // currentItem
    try {
        tit->currentItem();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no currentItem()!"), e);
    }
    // next
    try {
        tit->next();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no next()!"), e);
    }
    // isDone
    ASSERT_EQ(tit->isDone(),true);
    delete tit;
}

TEST(CaseTriangle, AddShape) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    Triangle* t1 = new Triangle(vect1,vect2);
    try {
        triangle.addShape(t1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Cannot do addShape!"), e);
    }
    delete t1;
}

TEST(CaseTriangle, DeleteShape) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle triangle(vect1,vect2);
    Triangle* t1 = new Triangle(vect1,vect2);
    try {
        triangle.deleteShape(t1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Cannot do deleteShape!"), e);
    }
    delete t1;
}