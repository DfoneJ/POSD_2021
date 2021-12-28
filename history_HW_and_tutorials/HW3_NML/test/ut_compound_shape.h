#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/utility.h"

TEST(CaseCompoundShape, FirstCreation) {
    CompoundShape* cs1 = new CompoundShape();
    ASSERT_EQ(std::string("CompoundShape\n{\n}"), cs1->info());
    ASSERT_NEAR(cs1->area(), 0.00, 0.001);
    ASSERT_NEAR(cs1->perimeter(), 0.00, 0.001);
    Iterator* csit = cs1->createIterator();
    
    // first
    csit->first(); //no exception should be thrown

    // currentItem
    try {
        csit->currentItem();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("already met the end!"), e);
    }
    // next
    try {
        csit->next();
        FAIL();
    }
    catch(std::string e) {
        ASSERT_EQ(std::string("already met the end!"), e);
    }
    // isDone
    ASSERT_EQ(csit->isDone(),true);
    delete cs1;
    delete csit;
}

TEST(CaseCompoundShape, AddAndArea) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    cs1->addShape(c1);
    ASSERT_NEAR(cs1->area(), 1.1*1.1*3.14159, 0.001);
    delete cs1;
}

TEST(CaseCompoundShape, AddAndPerimeter) {
    CompoundShape* cs1 = new CompoundShape();
    Rectangle* r1 = new Rectangle(3.14 ,4);
    cs1->addShape(r1);
    ASSERT_NEAR(cs1->perimeter(), (3.14 + 4)*2, 0.001);
    delete cs1;
}

TEST(CaseCompoundShape, AddAndInfo) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    cs1->addShape(c1);
    Rectangle* r = new Rectangle(3.14 ,4);
    cs1->addShape(r);

    CompoundShape* cs2 = new CompoundShape();
    Circle *c2 = new Circle(12.34567);
    cs2->addShape(c2);
    cs2->addShape(cs1);

    ASSERT_EQ(cs2->info(),std::string("CompoundShape\n{\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}"));
    delete cs2;
}

TEST(CaseCompoundShape, AddAndCreateIterator) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    cs1->addShape(c1);
    Rectangle* r = new Rectangle(3.14 ,4);
    cs1->addShape(r);

    CompoundShape* cs2 = new CompoundShape();
    Circle *c2 = new Circle(12.34567);
    cs2->addShape(c2);
    cs2->addShape(cs1);

    Iterator* csit = cs2->createIterator();

    csit->first();
    ASSERT_EQ(c2, csit->currentItem());

    csit->next();
    ASSERT_EQ(cs1, csit->currentItem());

    csit->next();
    ASSERT_TRUE(csit->isDone());
    delete cs2;
    delete csit;
}

TEST(CaseCompoundShape, AddAndDeleteShape) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    cs1->addShape(c1);
    Rectangle* r = new Rectangle(3.14 ,4);
    cs1->addShape(r);

    CompoundShape* cs2 = new CompoundShape();
    Circle *c2 = new Circle(12.34567);
    cs2->addShape(c1);
    cs2->addShape(c1);
    cs2->addShape(c2);
    cs2->addShape(cs1);
    ASSERT_EQ(cs2->info(),std::string("CompoundShape\n{\nCircle (1.10)\nCircle (1.10)\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}"));

    cs2->deleteShape(c1);
    ASSERT_EQ(cs2->info(),std::string("CompoundShape\n{\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}"));

    delete cs2;
}