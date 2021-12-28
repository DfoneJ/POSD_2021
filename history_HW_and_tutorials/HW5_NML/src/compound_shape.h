#pragma once

#include <list>
#include "./iterator/compound_iterator.h"
#include "./visitor/shape_visitor.h"
#include "./shape.h"

class CompoundShape : public Shape {
public:
    ~CompoundShape() { for(Shape* s : _shapes) delete s; }

    double area() const override { 
        double area = 0;
        for (Shape* s : _shapes) area += s->area();
        return area; 
    } // 面積

    double perimeter() const override { 
        double perimeter = 0;
        for (Shape* s : _shapes) perimeter += s->perimeter();
        return perimeter;
    } // 周長

    std::string info() const override { return std::string("CompoundShape"); } // 資訊

    void addShape(Shape* shape) override { // 加入形狀
        _shapes.push_back(shape);
    }
    
    void deleteShape(Shape* shape) override { // 刪除形狀
        for (Shape* s : _shapes) { 
            if (s->info() == "CompoundShape") s->deleteShape(shape);
        }
        delete shape;
        _shapes.remove(shape); //刪除成員
    }

    Iterator* createIterator() override { // Compound 迭代器
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void accept(ShapeVisitor* visitor) override { visitor->visitCompoundShape(this); } // 接受拜訪

private:
    std::list<Shape*> _shapes;
};