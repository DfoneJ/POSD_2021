#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <exception>
#include <iostream>
#include <math.h>
#include "shape.h"
#include "two_dimensional_vector.h"

using namespace std;
using std::exception;

class Triangle: public Shape {
    public:
        Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
            _a = cal_edge(vec1.x(),vec1.y(),0,0);
            _b = cal_edge(vec1.x(),vec1.y(),vec2.x(),vec2.y());
            _c = cal_edge(vec2.x(),vec2.y(),0,0);

            c0x = 0.0;
            c0y = 0.0;
            c1x = vec1.x();
            c1y = vec1.y();
            c2x = vec2.x();
            c2y = vec2.y();

            if(this->area()==0 || isTriangle(vec1,vec2) == false )
                throw std::string("vectors cannot make a triangle");
        }

        double area() const override{
            double s = (_a+_b+_c)/2;
            return sqrt(s * (s-_a) * (s-_b) * (s-_c));  //海龍公式
        }

        double perimeter() const override{
            return _a+_b+_c;
        }

        std::string info() const override{
            char information[63];
            sprintf(information, "Triangle ([%.2lf,%.2lf] [%.2lf,%.2lf])",
            (round(c1x*100.00))/100.00,(round(c1y*100.00))/100.00,
            (round(c2x*100.00))/100.00,(round(c2y*100.00))/100.00);
            return information;
        }

    private:
        double _a,_b,_c;
        double c0x,c0y,c1x,c1y,c2x,c2y;

        bool isTriangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2){
            double m1 = (vec1.y()/vec1.x());
            double m2 = (vec2.y()/vec2.x());
            if(m1 == m2) return false;  //斜率相等則兩向量平行
            else return true;
        }

        double cal_edge(double x1,double y1,double x2,double y2){
            return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
        }
};

#endif