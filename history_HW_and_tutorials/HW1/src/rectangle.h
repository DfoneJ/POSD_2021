#ifndef  RECTANGLE_H
#define  RECTANGLE_H
#include <stdio.h>
#include <exception>
#include <iostream>
#include "shape.h"
#include <cmath>

using namespace std;
using std::exception;

class Rectangle : public Shape {
    public: 
        Rectangle(double length, double width) {
            if(length <=0 || width <=0)
                throw std::string("edges of rectangle should larger than zero");
            _length = length;
            _width = width;
        }

        double area() const override{
            return _length * _width;
        }

        double perimeter() const override{
            return (_length + _width) * 2.000;
        }
        
        std::string info() const override{
            char information[63];
            sprintf(information, "Rectangle (%.2lf %.2lf)",
            (round(_length*100.00))/100.00, (round(_width*100.00))/100.00);
            return information;
        }

    private:
        double  _length,_width ;

};

#endif
