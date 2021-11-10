#pragma once

#include <stdio.h>
#include <exception>
#include <iostream>
#include <list>
#include "shape.h"
#include "iterator/compound_iterator.h"

using namespace std;
using std::exception;

class CompoundShape : public Shape {
public:
    ~CompoundShape() { }

    CompoundShape(){
        _text = "CompoundShape\n{\n";
        //cout << *(_shapes.begin()) << endl;  // 0
    }
    
    double area() const override {
        double area = _area;
        for(Shape* s:_shapes){area += s->area();}
        return area;
    }

    double perimeter() const override {
        double perimeter = _perimeter;
        for(Shape* s:_shapes){perimeter += s->perimeter();}
        return perimeter;
    }

    std::string info() const override {
        std::string text = _text;
        for(Shape* s:_shapes){text += s->info() + "\n";}
        return text + "}";
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override {_shapes.push_back(shape);}

    void deleteShape(Shape* shape) override {
        _shapes.remove(shape);
    }
private:
    std::list<Shape*> _shapes;
    double _area = 0.0;
    double _perimeter = 0.0;
    std::string _text="";
};