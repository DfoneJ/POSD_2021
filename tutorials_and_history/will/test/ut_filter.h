#include "../src/shape_filter.h"
#include "../src/shape_setter.h"
#include "../src/filter.h"
#include <gtest/gtest.h>

TEST(FilterTest, ShapeFilter) {
    std::list<Shape*> data ={};
    Shape * r34 = new Rectangle("1",3,4);
    Shape * r34_b = new Rectangle("1",3,4,"black");
    data.push_back(r34);
    data.push_back(r34_b);
    Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() <= 20;});
    Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() >= 10;});
    Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "black";});

    areaFilter->setNext(perimeterFilter)->setNext(colorFilter);
    std::list<Shape*> results = areaFilter->push(data);
    ASSERT_EQ(1, results.size());
}
TEST(FilterTest, ShapeSetter) {
     std::list<Shape*> data ={};
    Shape * r34 = new Rectangle("1",3,4);
    Shape * r34_b = new Rectangle("1",3,4,"black");
    data.push_back(r34);
    data.push_back(r34_b);

    Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() < 30;});
    Filter* perimeterFilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() > 10;});
    Filter* colorSetter = new ShapeSetter([](Shape* shape) {shape->setColor("black");});
    Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "black";});
    areaFilter->setNext(perimeterFilter)->setNext(colorSetter)->setNext(colorFilter);
    std::list<Shape*> results = areaFilter->push(data);
    ASSERT_EQ(2, results.size());

}