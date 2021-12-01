#ifndef AREAVISITOR_H
#define AREAVISITOR_H

#include "shape.h"
#include "compound_shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "visitor.h"

class AreaVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) override{

        double a = ellipse->getSemiMajorAxes();
        double b = ellipse->getSemiMinorAxes();
        double s = M_PI*a*b;
        _area = ellipse->area();
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
    }

    void visit(Triangle* triangle) override{
         vector<TwoDimensionalCoordinate*> vectors =triangle->getVector();
         double _a = sqrt(pow((vectors[0]->getX()-vectors[1]->getX()),2) + pow((vectors[0]->getY()-vectors[1]->getY()),2));
         double _b = sqrt(pow((vectors[0]->getX()-vectors[2]->getX()),2) + pow((vectors[0]->getY()-vectors[2]->getY()),2));
         double _c = sqrt(pow((vectors[1]->getX()-vectors[2]->getX()),2) + pow((vectors[1]->getY()-vectors[2]->getY()),2));
         double s = (_a + _b + _c) / 2;
         _area = sqrt(s * (s - _a) * (s - _b) * (s - _c));
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
    }

    void visit(Rectangle* rectangle) override{
         _area = (rectangle->getWidth()) * (rectangle->getLength());
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
    }
    void visit(CompoundShape* compoundShape) override{
        std::list<Shape *> shapes =  compoundShape->getSubShapes();
        _area=0.0;
        Visitor *vis = new AreaVisitor();

        for(std::list<Shape*>::const_iterator it=shapes.begin() ; it!=shapes.end() ; it++){
            (*it)->accept(vis);
            _area += (dynamic_cast<AreaVisitor*>(vis))->area();//每一次迴圈加入面積
        }
        
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
    }

    double area() const {
        // return area;
        return _area;
    }
private:
  double _area = 0.0;

};
#endif