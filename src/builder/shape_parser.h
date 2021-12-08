#pragma once

#include <fstream>
#include <sstream>
#include "scanner.h"
#include "shape_builder.h"

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        std::ifstream infile(filePath);
        std::string line;
        while (std::getline(infile, line)) _input += line;
        infile.close();
        _scanner = new Scanner(_input); // Scanner 負責幫忙 Parser 從檔案內容中抓到 tokens
        _builder = new ShapeBuilder(); // Builder 負責讓 Parser 在 parse() 贖後可以依照抓到的 token 創造對應的形狀
    }

    ~ShapeParser() {
        delete _scanner;
        delete _builder;
    }

    void parse() {
        std::string token="";
        while(!_scanner->isDone()) {
            token = _scanner->next();
            if(token == "Circle") _builder->buildCircle(_scanner->nextDouble()); // 1 double
            else if(token == "Rectangle") {
                double length = _scanner->nextDouble();
                double width = _scanner->nextDouble();
                _builder->buildRectangle(length, width); 
            }
            else if(token == "Triangle") {
                double x1 = _scanner->nextDouble();
                double y1 = _scanner->nextDouble();
                double x2 = _scanner->nextDouble();
                double y2 = _scanner->nextDouble();
                _builder->buildTriangle(x1, y1, x2, y2);
            }
            else if(token == "CompoundShape") _builder->buildCompoundBegin();
            else if(token == "}") _builder->buildCompoundEnd();
        }
    }

    Shape* getShape() { return _builder->getShape();}

private:
    std::string _input ="";
    Scanner* _scanner;
    ShapeBuilder* _builder;
};
