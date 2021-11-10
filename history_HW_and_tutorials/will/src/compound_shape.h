#ifndef _COMPOUND_SHAPE_H_
#define _COMPOUND_SHAPE_H_
#include "shape.h"
#include "shape_iterator.h"
#include <list>

class CompoundShape : public Shape {
public:
    CompoundShape(std::string id, std::list<Shape*> shapes) : Shape(id, "transparent") {
        // The default color of compound shape should be "transparent".
        // When there's no shape contain in the compound shape,
        // Modify CompoundShape constructor, now it's available to accpet empty std::list<Shape*> without throwing exception.
        _shapes.assign(shapes.begin(),shapes.end());
    
    }

    Iterator* createIterator()  const {
        // return ShapeIterator
        return new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
    }

    double area() const {
        // return sum of all containing shapes area.
        double totalArea = 0.0;
        for(std::list<Shape *>::const_iterator i = _shapes.begin(); i != _shapes.end(); i++){
            totalArea += (*i)->area();
        }
        return totalArea;
    }

    double perimeter() const {
        // return sum of all containing shapes perimeter.
        double totalperimeter = 0.0;
        for(std::list<Shape *>::const_iterator i = _shapes.begin(); i != _shapes.end(); i++){
            totalperimeter += (*i)->perimeter();
        }
        return totalperimeter;
    }

    std::string info() const {
        // return list of all containing shapes info with wrapped of "CompoundShape {}".
        // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
        std::string compoundShapeInfo = "Compound Shape {";
        for(std::list<Shape *>::const_iterator i = _shapes.begin(); i != _shapes.end(); i++){
            if (!(compoundShapeInfo == "Compound Shape {")){
                compoundShapeInfo += ", ";
            }
            compoundShapeInfo += (*i)->info();
        }
        compoundShapeInfo += "}";
        return compoundShapeInfo;
    }

    string type() const {
        return "Compound Shape";
    }

    void addShape(Shape* shape) {
        // add shape into compound shape.
        _shapes.push_back(shape);
    }

    void deleteShapeById(std::string id) {
        // search and delete a shape through id,
        // search all the containing shapes and the tree structure below,
        // if no match of id, throw std::string "Expected delete shape but shape not found"
        bool isDeleted = false;
        for(std::list<Shape *>::iterator i = _shapes.begin(); i != _shapes.end();){
            if((*i)->id() == id){
                i = _shapes.erase(i);
                isDeleted = true;
            }else{
                try {
                    (*i)->deleteShapeById(id);
                    isDeleted = true;
                }catch(string e){
                    //ignore
                }
                i++;
            }
        }
        if(!isDeleted){
            throw std::string("Expected delete shape but shape not found");
        }
    }

    Shape* getShapeById(std::string id) const{
            // search and return a shape through id,
            // search all the containing shapes and the tree structure below,
            // if no match of id, throw std::string "Expected get shape but shape not found"
            for(std::list<Shape*>::const_iterator it=_shapes.begin() ; it!=_shapes.end() ; it++){
                if (id==(*it)->id()){//找到了就直接回傳
                  return (*it);
                }
                try{                                //不然就去其中的子圖找找
                    return  (*it)->getShapeById(id);
                }catch(string e){}                  //各子圖找不到的話，不處理
            }
            throw std::string("Expected get shape but shape not found");//在所有子圖都找不到才會丟出例外
    }
    void accept(Visitor* visitor){
      visitor->visit(this);
    }
    
    std::list<Shape *> getSubShapes(){
        return _shapes;
    }


private:
    std::list<Shape *> _shapes;
};

#endif
