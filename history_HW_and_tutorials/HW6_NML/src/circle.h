#pragma once

#include "shape.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Circle : public Shape {
    public:
        Circle(double radius) {
            if(radius <=0) {throw std::string("radius of circle should larger than zero");}
            else {
                _radius = radius;
                sprintf(_info, "Circle (%.2lf)", (round(_radius*100.00))/100.00);
            }
        }

        double area() const override { return pow(_radius,2)*M_PI; } // 面積

        double perimeter() const override { return 2*_radius*M_PI; } // 周長

        std::string info() const override { return _info; } // 資訊

        void addShape(Shape* shape) { throw std::string("can't add shape"); } // 加入形狀

        void deleteShape(Shape* shape) { throw std::string("can't delete shape"); } // 刪除形狀

        Iterator* createIterator() override { return new NullIterator(); } // Null 迭代器
        
        void accept(ShapeVisitor* visitor) override { visitor->visitCircle(this); } // 接受拜訪 

    private:
        double _radius;
        char _info[20];
};