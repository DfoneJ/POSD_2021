#include "../src/rectangle.h"

TEST(CaseRectangle, CreateFail) {
    try {
        Rectangle rect(-3.0,4.0);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("edges of rectangle should larger than zero"), e);
    }
    try {
        Rectangle rect(3.0,-4.0);
        FAIL();
    }
    catch(std::string e) {
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

TEST(CaseRectangle, CreateIterator) {
    Rectangle rect(3.0,4.0);
    Iterator* rit = rect.createIterator();
    // first
    try {
        rit->first();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Already met the end !"), e);
    }
    // currentItem
    try {
        rit->currentItem();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Already met the end !"), e);
    }
    // next
    try {
        rit->next();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("Already met the end !"), e);
    }
    // isDone
    ASSERT_EQ(rit->isDone(),true);
    delete rit;
}

TEST(CaseRectangle, AddShape) {
    Rectangle rect(3.0,4.0);
    Rectangle* r1 = new Rectangle(3.0,4.0);
    try {
        rect.addShape(r1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("can't add shape"), e);
    }
    delete r1;
}

TEST(CaseRectangle, DeleteShape) {
    Rectangle rect(3.0,4.0);
    Rectangle* r1 = new Rectangle(3.0,4.0);
    try {
        rect.deleteShape(r1);
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("can't delete shape"), e);
    }
    delete r1;
}