#include "../../src/visitor/shape_info_visitor.h"

class CaseInfoVisitor : public ::testing::Test {
protected:
    void SetUp() override { visitor = new ShapeInfoVisitor(); }

    void TearDown() override { delete visitor; }

    ShapeInfoVisitor* visitor;
};

TEST_F(CaseInfoVisitor, VisitCircle) {
    Shape* c = new Circle(12.3456);
    c->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "Circle (12.35)\n");
    delete c;
}

TEST_F(CaseInfoVisitor, VisitRectangle) {
    Shape* rect = new Rectangle(3, 4);
    rect->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "Rectangle (3.00 4.00)\n");
    delete rect;
}

TEST_F(CaseInfoVisitor, VisitTriangle) {
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Shape* tri = new Triangle(vect1,vect2);
    tri->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "Triangle ([3.00,0.00] [0.00,4.00])\n");
    delete tri;
}

TEST_F(CaseInfoVisitor, VisitOneLevelCompound) {
    Shape* cs = new CompoundShape();
    Circle* c1 = new Circle(2.0);
    Circle* c2 = new Circle(1.0);
    cs->addShape(c1);
    cs->addShape(c2);
    cs->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "CompoundShape {\n  Circle (2.00)\n  Circle (1.00)\n}\n");
    delete cs;
}

TEST_F(CaseInfoVisitor, VisitTwoLevelCompound) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c1 = new Circle(1.1);
    Rectangle* rect = new Rectangle(3.14 ,4);
    cs1->addShape(c1);
    cs1->addShape(rect);
    CompoundShape* cs2 = new CompoundShape();
    Circle* c2 = new Circle(12.34567);
    cs2->addShape(c2);
    cs2->addShape(cs1);
    cs2->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n");
    delete cs2;
}