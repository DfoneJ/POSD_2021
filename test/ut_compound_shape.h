#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

class CaseCompoundShape : public ::testing::Test {
protected:
    void SetUp() override { cs = new CompoundShape(); }

    void TearDown() override { delete cs; }

    CompoundShape* cs;
};

TEST_F(CaseCompoundShape, Area) {
    ASSERT_NEAR(cs->area(), 0, 0.001);
}

TEST_F(CaseCompoundShape, Perimeter) {
    ASSERT_NEAR(cs->perimeter(), 0, 0.001);
}

TEST_F(CaseCompoundShape, Info) {
    ASSERT_EQ(cs->info(), "CompoundShape");
}

TEST_F(CaseCompoundShape, CreateIterator) {
    Iterator* csit = cs->createIterator();
    ASSERT_TRUE(csit->isDone());
    delete csit;
}

TEST_F(CaseCompoundShape, AddShape) {
    Circle* c1 = new Circle(2.0);
    Circle* c2 = new Circle(1.0);
    cs->addShape(c1);
    cs->addShape(c2);
    Iterator* csit = cs->createIterator();
    ASSERT_TRUE( csit->currentItem() == c1);
    csit->next();
    ASSERT_TRUE( csit->currentItem() == c2);
    delete csit;
}

TEST_F(CaseCompoundShape, DeleteShape) {
    Circle* c = new Circle(2.0);
    cs->addShape(c);
    Iterator* csit1 = cs->createIterator(); // 新增circle後的內容
    ASSERT_TRUE( csit1->currentItem() == c);
    cs->deleteShape(c);
    Iterator* csit2 = cs->createIterator(); // 刪除circle後的內容
    ASSERT_TRUE( csit2->isDone());
    ASSERT_EQ(std::string("P13CompoundShape"), typeid(cs).name());
    ASSERT_EQ(typeid(CompoundShape), typeid(*cs));
    delete csit1;
    delete csit2;
}