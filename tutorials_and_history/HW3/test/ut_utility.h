#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/utility.h"

TEST(CaseUtility, SelectShape) {
    CompoundShape* cs1 = new CompoundShape();
    Circle* c = new Circle(1.1);
    cs1->addShape(c);
    Rectangle* r = new Rectangle(3.14 ,4);
    cs1->addShape(r);

    CompoundShape* cs2 = new CompoundShape();
    TwoDimensionalVector vect1(3,0);
    TwoDimensionalVector vect2(0,4);
    Triangle* t = new Triangle(vect1,vect2);
    cs2->addShape(t);

    cs2->addShape(cs1);

    Shape* result = selectShape(cs2, [](Shape* shape){
        return shape->area() > 10.0 && shape->area() < 20.0;
    });
    ASSERT_EQ(cs1, result);
    delete c;
    delete r;
    delete t;
    delete cs1, cs2;
}
