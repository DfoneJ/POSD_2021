#pragma once
#include <deque>
#include <stack>
#include <vector>
#include <string> 

#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "compound_shape.h"

class ShapeBuilder {
public:
    ShapeBuilder() {}
    
    void buildRectangle(double length, double width) {
        // build a rectangle with an unique id and push in a std::stack.
        Shape * r = new Rectangle(std::to_string(id),length,width);
        _pushdown.push(r);
        id++;
    }
    
    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        // cout<<"buildEllipse(double "<<semiMajorAxes<< "double "<<semiMinorAxes<<endl;
        // build a ellipse with an unique id and push in a std::stack.
         Shape * e = new Ellipse(std::to_string(id),semiMajorAxes, semiMinorAxes);
          _pushdown.push(e);
         id++;
    }
    
    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        // build a triangle with an unique id and push in a std::stack.
        vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(x1, y1));
        triangleVector.push_back(new TwoDimensionalCoordinate(x2, y2));
        triangleVector.push_back(new TwoDimensionalCoordinate(x3, y3));
        Shape * t = new Triangle(std::to_string(id), triangleVector);
        _pushdown.push(t);
        id++;
    }
    


    void buildCompoundShapeBegin() {
        // for notifing beginning of a Compound Shape.
        list<Shape *> list = {new Rectangle("placeholder_for_empty_compoudShape", 1, 1)};
        Shape * compoundShape = new CompoundShape(to_string(id), list);
        _pushdown.push(compoundShape);
        id++;
    }
    
    void buildCompoundShapeEnd() {
        // for notifing ending of a Compound Shape.
        std::deque<Shape*> subShapes;
        while(_pushdown.top()->createIterator()->isDone() || _pushdown.top()->createIterator()->currentItem()->id()!="placeholder_for_empty_compoudShape"){
            subShapes.push_back(_pushdown.top());
            _pushdown.pop();
        }
        _pushdown.top()->deleteShapeById("placeholder_for_empty_compoudShape");
        for(auto it=subShapes.rbegin(); it!=subShapes.rend(); it++){
            _pushdown.top()->addShape(*it);
        }
    }

    std::deque<Shape*> getResult() {
        // return result.
        // cout<<" std::deque<Shape*> getResult()"<<endl;
        std::deque<Shape *> result;
        while(!_pushdown.empty()){
            result.push_back(_pushdown.top());
            // cout<<_pushdown.top()->info()<<endl;
            _pushdown.pop();
        }
        return std::deque<Shape*>(result.rbegin(),result.rend());//以反向順序把資料回傳(因為之前使用了stake)
    }

private:
    std::stack<Shape*> _pushdown;
    
    int id = 0;
};
