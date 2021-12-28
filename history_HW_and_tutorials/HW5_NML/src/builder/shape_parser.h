#pragma once

#include <exception>
#include <fstream>
#include <sstream>
#include "scanner.h"
#include "shape_builder.h"
#include <iostream>

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
            if(token == "Circle") {
                if(_scanner->next() != "(") { throw std::string("Invalid input !"); }
                double radius = _scanner->nextDouble();
                if(_scanner->next() != ")") { throw std::string("Invalid input !"); }
                // std::cout << "Build Circle" << std::endl;
                _builder->buildCircle(radius); // 1 double
            }
            else if(token == "Rectangle") {
                if(_scanner->next() != "(") { throw std::string("Invalid input !"); }
                double length = _scanner->nextDouble();
                std::string RectangleSpecialCase = _scanner->next(); // Special case !!
                if(RectangleSpecialCase == ",") { // (3.14, 4.00)
                    double width = _scanner->nextDouble();
                    if(_scanner->next() != ")") { throw std::string("Invalid input !"); }
                    _builder->buildRectangle(length, width);
                }
                if(RectangleSpecialCase == ")") { // (3.14 4.00)
                    double width = _scanner->nextDouble();
                    _builder->buildRectangle(length, width);
                }
                if((RectangleSpecialCase!=",") && (RectangleSpecialCase!=")")) { throw std::string("Invalid input !"); }
                // std::cout << "Build Rectangle" << std::endl;
            }
            else if(token == "Triangle") {
                if(_scanner->next() != "(") { throw std::string("Invalid input !"); }
                if(_scanner->next() != "[") { throw std::string("Invalid input !"); }
                double x1 = _scanner->nextDouble();
                if(_scanner->next() != ",") { throw std::string("Invalid input !"); }
                double y1 = _scanner->nextDouble();
                if(_scanner->next() != "]") { throw std::string("Invalid input !"); }
                if(_scanner->next() != "[") { throw std::string("Invalid input !"); }
                double x2 = _scanner->nextDouble();
                if(_scanner->next() != ",") { throw std::string("Invalid input !"); }
                double y2 = _scanner->nextDouble();
                if(_scanner->next() != "]") { throw std::string("Invalid input !"); }
                if(_scanner->next() != ")") { throw std::string("Invalid input !"); }
                // std::cout << "Build Triangle" << std::endl;
                _builder->buildTriangle(x1, y1, x2, y2);
            }
            else if(token == "CompoundShape") {
                if(_scanner->next() != "{") { throw std::string("Invalid input !"); }
                // std::cout << "Build CompoundShape Begin" << std::endl;
                _builder->buildCompoundBegin();
            }
            else if(token == "}") {
                // std::cout << "Build CompoundShape End" << std::endl;
                _builder->buildCompoundEnd();
            }
        }
    }

    Shape* getShape() { return _builder->getShape();}

private:
    std::string _input ="";
    Scanner* _scanner;
    ShapeBuilder* _builder;
};
