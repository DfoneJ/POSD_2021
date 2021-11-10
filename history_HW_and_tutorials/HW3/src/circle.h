#pragma once

#include <stdio.h>
#include <exception>
#include <iostream>
#include "shape.h"
#include <cmath>
#include "iterator/null_iterator.h"

using namespace std;
using std::exception;

class Circle : public Shape {
    public:
        Circle(double radius){
            if(radius <=0){throw std::string("radius of circle should larger than zero");}
            else {_radius = radius;}
        }

        double area() const override{
            return pow(_radius, 2) * M_PI;
        }

        double perimeter() const override{
            return 2 * M_PI * _radius;
        }

        std::string info() const override{
            char information[63];
            sprintf(information, "Circle (%.2lf)", (round(_radius*100.00))/100.00);
            return information;
        }

        Iterator* createIterator() override {return new NullIterator();}

        void addShape(Shape* shape) {throw std::string("Cannot do addShape!");}

        void deleteShape(Shape* shape) {throw std::string("Cannot do deleteShape!");}
    private:
        double _radius;
};
