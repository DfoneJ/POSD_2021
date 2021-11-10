#if !defined( RECTANGLE_H )
#define RECTANGLE_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include "./shape.h"
class Rectangle: public Shape {
public:

    Rectangle(std::string id, double length, double width): Shape(id){
      if(length <= 0.0 || width <= 0.0) throw std::string("This is not a rectangle!");
      _id = id;
      _width = width;
      _length = length;
    }
    Rectangle(std::string id, double length, double width, std::string color): Shape(id,color){
      if(length <= 0.0 || width <= 0.0) throw std::string("This is not a rectangle!");
      _id = id;
      _color = color;
      _width = width;
      _length = length;
    }


    string TruncateNumberStr(double num) const{
      std::ostringstream streamObj3;
      streamObj3 << std::fixed;
      streamObj3 << setprecision(3);
      streamObj3 << num;
      return streamObj3.str();
    }

    double TruncateNumberDouble(double num) const{
      string s=TruncateNumberStr(num);
      return stod(s);
    }

    double area() const {
        return TruncateNumberDouble(_width*_length);
    }

    double perimeter() const {
        return TruncateNumberDouble((_width+_length)*2.0);
    }

    string info() const {
        return "Rectangle ("+TruncateNumberStr(_length)+", "+TruncateNumberStr(_width)+")";
    }

    std::string type() const {
      return "Rectangle";
    }

    void addShape(Shape *shape){
       throw std::string("Only compound shape can add shape!");
    }
    void deleteShapeById(std::string id){
      throw std::string("Only compound shape can delete shape!");
    }
    Shape*  getShapeById(std::string id){
      throw std::string("Only compound shape can get shape!");
    }
    void accept(Visitor* visitor){
      visitor->visit(this);
    }
    double getWidth(){
      return _width;
    }
    double getLength(){
      return _length;
    }
  private:
    //data members
    double _width, _length;
    std::string _color="white";
    std::string _id="";
  };

  #endif
