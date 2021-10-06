#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdio.h>
#include <exception>
#include <iostream>
#include "shape.h"
#include <cmath>

using namespace std;
using std::exception;

class Circle : public Shape {
    public:
        Circle(double radius){
            if(radius <=0)
                throw std::string("radius of circle should larger than zero");
            _radius = radius;
        }

        double area() const override{
            return pow(_radius, 2) * M_PI;
        }

        double perimeter() const override{
            return 2 * M_PI * _radius;
        }

        std::string info() const {
            char information[63];
            sprintf(information, "Circle (%.2lf)", (round(_radius*100.00))/100.00);
            return information;
        }
    private:
        double _radius;
};

#endif