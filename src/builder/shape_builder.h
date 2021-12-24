#pragma once

#include <stack>
#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"
#include "../compound_shape.h"

class ShapeBuilder {
public:
    static ShapeBuilder* getInstance() {
        static ShapeBuilder instance;
        return &instance;
    }

    ~ShapeBuilder() { reset(); }

    void buildCircle(double radius) { _shapeStack.push(new Circle(radius)); } // Push Circle into stack

    void buildRectangle(double length, double width) { _shapeStack.push(new Rectangle(length, width)); } // Push Rectangle into stack

    void buildTriangle(double x1, double y1, double x2, double y2) { // Push Triangle into stack
        TwoDimensionalVector v1(x1,y1);
        TwoDimensionalVector v2(x2,y2);
        _shapeStack.push(new Triangle(v1, v2));
    }

    void buildCompoundBegin() { _shapeStack.push(new CompoundShape()); } // Push an empty CompoundShape into stack

    void buildCompoundEnd() {
        std::stack<Shape*> components; // a stack which will contains pointers to Shape that will be added to CompoudShape as a CompoundShape member
        while( !isCompound(_shapeStack.top()) || isNoneEmptyCompound(_shapeStack.top()) ) { // push Shapes into stack that will be added to CompoudShape as a CompoundShape member
            components.push(_shapeStack.top());
            _shapeStack.pop();
        }
        // Now, the _shapeStack top is the CompoundShape pointer which wait for adding Shapes
        while(!components.empty()) {
            _shapeStack.top()->addShape(components.top());
            components.pop();
        }
        // Finishing the add Shapes of CompoundShape, still, the CompoundShape pointer is at the top of _shapeStack
    }

    Shape* getShape() {
        if(!_shapeStack.empty()) {
            Shape* result = _shapeStack.top();
            _shapeStack.pop();
            return result;
        }
        else {
            Shape* Empty = nullptr;
            return Empty;
        }
    }  // There should be only 1 porinter of Shape, left in the stack, at the end !

    void reset() {
        while(!_shapeStack.empty()) {
            Shape* shape = _shapeStack.top();
            _shapeStack.pop();
            delete shape;
        }
    }

private:
    ShapeBuilder(){};
    std::stack<Shape*> _shapeStack; // A stack which contains pointers to Shape
    bool isCompound(Shape* s) { return  typeid(*s)==typeid(CompoundShape); }
    bool isNoneEmptyCompound(Shape* s) { return isCompound(s)&&!s->createIterator()->isDone(); }
};