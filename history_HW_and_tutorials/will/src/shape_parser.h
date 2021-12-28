#pragma once

#include "scanner.h"
#include "shape_builder.h"
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <cstdlib>

class ShapeParser {
public:
  ShapeParser(std::string input) {
      _scanner = new Scanner(input);
      _shapeBuilder = new ShapeBuilder();
      _shapes["Triangle"] = true;
      _shapes["Ellipse"] = true;
      _shapes["Rectangle"] = true;
      _shapes["CompoundShape"] = true;
  }

  void parser() {
    std::string next = "";
    try{
      while(1){
        if(isCritical(next)) next = buildShapeAndReturnLastToken(next);
        if(next == "}") break;
        next = _scanner->nextToken();
      }
    }catch(std::string e){}
  }

  std::deque<Shape*> getResult() {
      return _shapeBuilder->getResult();
  }
private:
  Scanner * _scanner;
  ShapeBuilder * _shapeBuilder;
  std::map<std::string, bool> _shapes;

  std::string buildShapeAndReturnLastToken(std::string token){
    std::vector<double> args;
    std::string argument = "";

    if(token == "CompoundShape") {
      _shapeBuilder->buildCompoundShapeBegin();
      parser();
      _shapeBuilder->buildCompoundShapeEnd();
      return argument;
    }

    while(!isEndCharacter(argument)){
      argument = _scanner->nextToken();
      if(isArgument(argument)) args.push_back(atof(argument.c_str()));
    }

    if(argument == "}") return argument;
    if(token == "Ellipse" && args.size() == 2) _shapeBuilder->buildEllipse(args[0], args[1]);
    if(token == "Rectangle" && args.size() == 2) _shapeBuilder->buildRectangle(args[0], args[1]);
    if(token == "Triangle" && args.size() == 6) _shapeBuilder->buildTriangle(args[0], args[1], args[2], args[3], args[4], args[5]);
    return argument;
  }

  bool isCritical(std::string token){
    return (_shapes.find(token) != _shapes.end());
  }

  bool isArgument(std::string token){
    for(char c : token) if(isdigit(c)) return true;
    return false;
  }

  bool isEndCharacter(std::string token){
    return (token[0] == '}' || token[0] == ')');
  }
};
