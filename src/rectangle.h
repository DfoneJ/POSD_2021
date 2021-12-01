#pragma once

#include "shape.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Rectangle : public Shape {
    public:
        Rectangle(double length, double width) {
            if(length <=0 || width <=0) { throw std::string("edges of rectangle should larger than zero"); }
            else{
                _length = length;
                _width = width;
                sprintf(_info, "Rectangle (%.2lf %.2lf)", (round(_length*100))/100, (round(_width*100))/100 );
            }
        }

        double area() const override { return (_length*_width); } // 面積

        double perimeter() const override { return 2*(_length+_width); } // 周長

        std::string info() const override { return _info; } // 資訊

        void addShape(Shape* shape) { throw std::string("can't add shape"); } // 加入形狀

        void deleteShape(Shape* shape) { throw std::string("can't delete shape"); } // 刪除形狀

        Iterator* createIterator() override { return new NullIterator(); } // Null 迭代器
        
        void accept(ShapeVisitor* visitor) override { visitor->visitRectangle(this); } // 接受拜訪

    private:
        double _length, _width;
        char _info[30];
};
