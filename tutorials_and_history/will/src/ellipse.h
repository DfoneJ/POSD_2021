#if !defined( ELLIPSE_H )
#define ELLIPSE_H
#include "./shape.h"

class Ellipse: public Shape{
public:

    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes): Shape(id)  {
      if(semiMajorAxes <= 0.0 || semiMinorAxes <= 0.0) throw std::string("This is not an ellipse!");

      if(semiMajorAxes<semiMinorAxes) throw std::string("This is not an ellipse!");

      _semiMajorAxes = semiMajorAxes;
      _semiMinorAxes = semiMinorAxes;
      _id = id;
    }
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color): Shape(id,color){
      if(semiMajorAxes <= 0.0 || semiMinorAxes <= 0.0) throw std::string("This is not an ellipse!");

      if(semiMajorAxes<semiMinorAxes) throw std::string("This is not an ellipse!");

      _semiMajorAxes = semiMajorAxes;
      _semiMinorAxes = semiMinorAxes;
      _id = id;
      _color = color;
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
        double a = _semiMajorAxes;
        double b = _semiMinorAxes;
        double s = M_PI*a*b;
        return s;

    }

    double perimeter() const {
        double a = _semiMajorAxes;
        double b = _semiMinorAxes;
        double l = 2*M_PI*b+4*(a-b);
        return l;
    }

    string info() const {
        return "Ellipse ("+TruncateNumberStr(_semiMajorAxes)+", "+TruncateNumberStr(_semiMinorAxes)+")";
    }
    std::string type() const {
      return "Ellipse";
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
    double getSemiMajorAxes(){
      return _semiMajorAxes;
    }
    double getSemiMinorAxes(){
      return _semiMinorAxes;
    }

  private:
    //data members
    double _semiMajorAxes, _semiMinorAxes;
    std::string _color="white";
    std::string _id="";
};

#endif
