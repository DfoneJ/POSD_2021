#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Triangle : public Shape {
    public:
        Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
            if(isParallel(vec1,vec2)) throw std::string("vectors are paralleled !");
            else {
                _vec1 = vec1;
                _vec2 = vec2;
                _p1x = vec1.x();
                _p1y = vec1.y();
                _p2x = vec2.x();
                _p2y = vec2.y();
                _a = vec1.length();
                _b = vec2.length();
                _c = sqrt( pow(_p1x-_p2x,2) + pow(_p1y-_p2y,2) ); //    sqrt[ (x1-x2)^2 + (y1-y2)^2 ]
            }
        }

        double area() const override {
            double s = (_a+_b+_c)/2;
            //海龍公式
            return sqrt(s * (s-_a) * (s-_b) * (s-_c)); // 面積
        } 

        double perimeter() const override { return _a+_b+_c; } // 周長

        std::string info() const override { return "Triangle ("+_vec1.info()+" "+_vec2.info()+")"; } // 資訊

        void addShape(Shape* shape) { throw std::string("can't add shape"); } // 加入形狀

        void deleteShape(Shape* shape) { throw std::string("can't delete shape"); } // 刪除形狀

        Iterator* createIterator() override { return new NullIterator(); } // Null 迭代器

        void accept(ShapeVisitor* visitor) override { visitor->visitTriangle(this); } // 接受拜訪

    private:
        TwoDimensionalVector _vec1;
        TwoDimensionalVector _vec2;
        double _p1x, _p1y;
        double _p2x, _p2y;
        double _a, _b, _c;
        char _info[50];

        bool isParallel(TwoDimensionalVector v1, TwoDimensionalVector v2) {
            if( v1.x()==0 && v2.x()==0 ) return true;
            else if( v1.x()!=0 && v2.x()!=0 ) return (v1.y()/v1.x() == v2.y()/v2.x());
            else return false;
        }

};
