#pragma once

#include <exception>
#include <math.h>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "iterator/null_iterator.h"

using namespace std;
using std::exception;

class Triangle: public Shape {
    public:
        Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2) {
            if( isParallel(v1,v2) ) throw std::string("vectors are paralleled !");
            else {
                _p1x = v1.x();
                _p1y = v1.y();
                _p2x = v2.x();
                _p2y = v2.y();
                _a = v1.length();
                _b = v2.length();
                _c = sqrt( pow(_p1x-_p2x,2) + pow(_p1y-_p2y,2) ); //    sqrt[ (x1-x2)^2 + (y1-y2)^2 ]
            }
        }

        double area() const override{
            double s = (_a+_b+_c)/2;
            return sqrt(s * (s-_a) * (s-_b) * (s-_c));  //海龍公式
        }

        double perimeter() const override{
            return _a+_b+_c;
        }

        std::string info() const override{
            char temp[63];
            sprintf(temp , "Triangle ([%.2lf,%.2lf] [%.2lf,%.2lf])" , round(_p1x*100)/100 , round(_p1y*100)/100 , round(_p2x*100)/100 , round(_p2y*100)/100 );
            return temp;
        }

        Iterator* createIterator() override {return new NullIterator();}

        void addShape(Shape* shape) {throw std::string("Cannot do addShape!");}

        void deleteShape(Shape* shape) {throw std::string("Cannot do deleteShape!");}
    private:
        double _p1x, _p1y;
        double _p2x, _p2y;
        double _a, _b, _c;

        bool isParallel(TwoDimensionalVector v1, TwoDimensionalVector v2) {
        if( v1.x()==0 && v2.x()==0 ) return true;
        else if( v1.x()!=0 && v2.x()!=0 ) return (v1.y()/v1.x() == v2.y()/v2.x());
        else return false;
    }
};
