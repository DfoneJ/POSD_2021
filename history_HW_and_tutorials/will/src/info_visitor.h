#ifndef INFOVISITOR_H
#define INFOVISITOR_H

#include "shape.h"
#include "compound_shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "visitor.h"
class InfoVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        double a = ellipse->getSemiMajorAxes();
        double b = ellipse->getSemiMinorAxes();
        
        std::ostringstream ss;
        ss << std::fixed;
        ss << setprecision(3);
        
        ss << "Ellipse (" << a <<", "<< b << ")";
        str = ss.str();
        
        // create info of ellipse, same way as ellipse->info().
        // DO NOT use ellipse->info() to get info directly.
        // you may add public function for Ellipse to get it's data members.
    }

    void visit(Triangle* triangle) {
        vector<TwoDimensionalCoordinate*> vectors =triangle->getVector();
        std::ostringstream ss;
        ss << std::fixed;
        ss << setprecision(3);
         

         ss << "Triangle ([" 
         << vectors[0]->getX() <<", "
         << vectors[0]->getY() <<"], "
         <<"["
         << vectors[1]->getX() <<", "
         << vectors[1]->getY() <<"], "
         <<"["
         << vectors[2]->getX() <<", "
         << vectors[2]->getY() <<"])";
         ss<<std::setprecision(3);
         str = ss.str();
        //  str =  "Triangle (["
        //                   +TruncateNumberStr(vectors[0]->getX())+", "
        //                   +TruncateNumberStr(vectors[0]->getY())+"], "
        //                   +"["+TruncateNumberStr(vectors[1]->getX())+", "
        //                   +TruncateNumberStr(vectors[1]->getY())+"], "
        //                   +"["+TruncateNumberStr(vectors[2]->getX())+", "
        //                   +TruncateNumberStr(vectors[2]->getY())
        //                   +"])";

        // create info of ellipse, same way as triangle->info().
        // DO NOT use triangle->info() to get info directly.
        // you may add public function for Triangle to get it's data members.
    }

    void visit(Rectangle* rectangle) {
        
        double _length = rectangle->getWidth();
        double _width = rectangle->getLength();

        std::ostringstream ss;
        ss << std::fixed;
        ss << setprecision(3);
        ss << "Rectangle (" << _width <<", "<<  _length << ")";
        str = ss.str();

        // create info of rectangle, same way as rectangle->info().
        // DO NOT use rectangle->info() to get info directly.
        // you may add public function for Rectangle to get it's data members.
    }

    void visit(CompoundShape* compoundShape) {
        std::list<Shape *> shapes =  compoundShape->getSubShapes();

        str="Compound Shape {";
        for(std::list<Shape*>::const_iterator it=shapes.begin() ; it!=shapes.end() ; it++){
            Visitor *vis = new InfoVisitor();
            (*it)->accept(vis);
            if (!(str == "Compound Shape {")){
                str += ", ";
            }
            str += (dynamic_cast<InfoVisitor*>(vis))->info();//每一次迴圈加入 info           
        }
        str += "}";
        
        // create info of compoundShape, same way as compoundShape->info().
        // DO NOT use compoundShape->info() to get info directly.
        // you may add public function for CompoundShape to get it's data members.
    }

    std::string info() const {
        // return info;
        return str;
    }
private:
    std::string str="";
};
#endif
