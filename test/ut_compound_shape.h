#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

TEST(CaseCompoundShape, Area) {
    CompoundShape* cs = new CompoundShape();
    ASSERT_NEAR(cs->area(), 0, 0.001);
    delete cs;
}

TEST(CaseCompoundShape, Perimeter) {
    CompoundShape* cs = new CompoundShape();
    ASSERT_NEAR(cs->perimeter(), 0, 0.001);
    delete cs;
}

TEST(CaseCompoundShape, Info) {
    CompoundShape* cs = new CompoundShape();
    ASSERT_EQ(cs->info(), "CompoundShape");
    delete cs;
}

TEST(CaseCompoundShape, CreateIterator) {
    CompoundShape* cs = new CompoundShape();
    Iterator* csit = cs->createIterator();
    ASSERT_TRUE(csit->isDone());
    delete csit;
    delete cs;
}

TEST(CaseCompoundShape, AddShape) {
    CompoundShape* cs = new CompoundShape();
    Circle* c1 = new Circle(2.0);
    Circle* c2 = new Circle(1.0);
    cs->addShape(c1);
    cs->addShape(c2);
    Iterator* csit = cs->createIterator();
    ASSERT_TRUE( csit->currentItem() == c1);
    csit->next();
    ASSERT_TRUE( csit->currentItem() == c2);
    delete cs;
    delete c1;
    delete c2;
    delete csit;
}

TEST(CaseCompoundShape, DeleteShape) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(2.0);
    cs->addShape(c);
    Iterator* csit1 = cs->createIterator(); // 新增circle後的內容
    ASSERT_TRUE( csit1->currentItem() == c);
    cs->deleteShape(c);
    Iterator* csit2 = cs->createIterator(); // 刪除circle後的內容
    ASSERT_TRUE( csit2->isDone());
    ASSERT_EQ(std::string("P13CompoundShape"), typeid(cs).name());
    ASSERT_EQ(typeid(CompoundShape), typeid(*cs));
    delete cs;
    delete c;
    delete csit1;
    delete csit2;
}