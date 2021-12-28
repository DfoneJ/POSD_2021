#include "../../src/iterator/compound_iterator.h"
#include "../../src/compound_shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"

TEST(CaseCompoundIterator, CurrentItem) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    cs->addShape(c);
    Iterator* csit = cs->createIterator();
    ASSERT_EQ(c, csit->currentItem());
    delete cs;
    delete csit;
}

TEST(CaseCompoundIterator, Next) {
    CompoundShape* cs = new CompoundShape();
    Circle* c1 = new Circle(1.0);
    Circle* c2 = new Circle(2.0);
    cs->addShape(c1);
    cs->addShape(c2);
    Iterator* csit = cs->createIterator();
    ASSERT_EQ(c1, csit->currentItem());
    csit->next();
    ASSERT_EQ(c2, csit->currentItem());
    delete cs;
    delete csit;
}

TEST(CaseCompoundIterator, IsDone) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    cs->addShape(c);
    Iterator* csit = cs->createIterator();
    csit->next();
    ASSERT_TRUE(csit->isDone());
    delete cs;
    delete csit;
}