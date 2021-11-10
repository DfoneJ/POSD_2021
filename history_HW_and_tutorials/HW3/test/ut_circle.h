#include <iostream>
#include "../src/circle.h"

TEST(CaseCircle, CreateFail) {
    try {
        Circle c(-10.0);
        FAIL();
    }
    catch(std::string e) {
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

TEST(CaseCircle, CreateIterator) {
    Circle c(10.0);
    Iterator* cit = c.createIterator();
    // first
    try {
        cit->first();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no first()!"), e);
    }
    // currentItem
    try {
        cit->currentItem();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no currentItem()!"), e);
    }
    // next
    try {
        cit->next();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("nulptr has no next()!"), e);
    }
    // isDone
    ASSERT_EQ(cit->isDone(),true);
    delete cit;
}

TEST(CaseCircle, AddShapeFail) {
    Circle c(10.0);
    Circle* c1 = new Circle(1.1);
    try {
        c.addShape(c1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Cannot do addShape!"), e);
    }
    delete c1;
}

TEST(CaseCircle, DeleteShapeFail) {
    Circle c(10.0);
    Circle* c1 = new Circle(1.1);
    try {
        c.deleteShape(c1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Cannot do deleteShape!"), e);
    }
    delete c1;
}