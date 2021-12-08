#pragma once

#include <string>

// #include "../circle.h"
// #include "../compound_shape.h"
// #include "../rectangle.h"
// #include "../triangle.h"
#include "../shape.h"
// #include "../iterator/compound_iterator.h"
#include "shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor {
public:
    void visitCircle(Circle* circle) override { result = circle->info()+std::string("\n"); }
    void visitRectangle(Rectangle* rectangle) override { result = rectangle->info()+std::string("\n"); }
    void visitTriangle(Triangle* triangle) override { result = triangle->info()+std::string("\n"); }

    void visitCompoundShape(CompoundShape* compoundShape) {
        clean_CompoundResult();
        CompoundResult = CompoundResult + compoundShape->info() + std::string("{\n");
        Iterator* csit = compoundShape->createIterator();
        _depth += 1;
        for (csit->first(); !csit->isDone(); csit->next()) {
            addIndent();
            if (csit->currentItem()->info()=="CompoundShape") {
                previous_content += CompoundResult;
                csit->currentItem()->accept(this);
            }
            else {
                csit->currentItem()->accept(this);
                CompoundResult += this->getResult();
            }
        }
        delete csit;
        _depth -= 1;
        addIndent();
        previous_content = previous_content + CompoundResult + "}\n";
        clean_CompoundResult();
        if (_depth==0) {
            result = previous_content;
            clean_Previous_Content();
        }
    }
    //CompoundShape{\n  Circle (12.35)\n  CompoundShape{\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n

    std::string getResult() const override { return result; }
    
private:
    int _depth = 0;
    std::string result = "";
    std::string CompoundResult = "";
    std::string previous_content = "";
    void clean_CompoundResult() { CompoundResult=""; }
    void clean_Previous_Content() { previous_content=""; }
    void addIndent() { for (int i=0; i<_depth; i++) CompoundResult += std::string("  "); }
};