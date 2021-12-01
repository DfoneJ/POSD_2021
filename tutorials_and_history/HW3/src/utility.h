#pragma once

#include "iterator/iterator.h"
#include "compound_shape.h"

/*Shape* selectFirstByArea(Shape* s, double min, double max) {
    Iterator* t = s->createIterator();
    Shape* result = nullptr;
    for(t->first() ; !t->isDone() ; t->next()){
        if(min < t->currentItem()->area() && t->currentItem()->area() < max){
            result = t->currentItem();
            break;
        }
    }
    delete t;
    return result;
}*/

/*Shape* selectFirstByArea(Iterator* t, double min, double max){
    for(t->first() ; !t->isDone() ; t->next()){
        if(min < t->currentItem()->area() && t->currentItem()->area() < max){
            return t->currentItem();
        }
    }
    return nullptr;
}*/

template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) {
    Iterator* sit = shape->createIterator();
    Shape* result = nullptr;
    for(sit->first() ; !sit->isDone() ; sit->next()){
        if(constraint(sit->currentItem())){
            result = sit->currentItem();
            break;
        }
    }
    delete sit;
    return result;
}