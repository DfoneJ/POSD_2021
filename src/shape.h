#pragma once

#include <string>
#include <cmath>
#include <exception>

class Iterator;
class ShapeVisitor;

class Shape {
   public:
    virtual ~Shape(){};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual void addShape(Shape* shape) { throw "can't add shape"; }

    virtual void deleteShape(Shape* shape) { throw "can't delete shape"; }
    
    virtual Iterator* createIterator() = 0;
    
    virtual void accept(ShapeVisitor* visitor) = 0;
};