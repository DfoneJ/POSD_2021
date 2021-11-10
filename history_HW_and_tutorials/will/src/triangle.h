#if !defined( TRIANGLE_H )
#define TRIANGLE_H
#include "./shape.h"

class Triangle : public Shape {
public:

  Triangle(std::string id, std::vector<TwoDimensionalCoordinate*> vectors):Shape(id) {

        if (vectors.size()==3){
            // a = sqrt(deltaX ^2 + deltaY ^2)
            _vectors = vectors;
            _a = sqrt(pow((vectors[0]->getX()-vectors[1]->getX()),2) + pow((vectors[0]->getY()-vectors[1]->getY()),2));
            _b = sqrt(pow((vectors[0]->getX()-vectors[2]->getX()),2) + pow((vectors[0]->getY()-vectors[2]->getY()),2));
            _c = sqrt(pow((vectors[1]->getX()-vectors[2]->getX()),2) + pow((vectors[1]->getY()-vectors[2]->getY()),2));
            _id = id;
            if(area()<= 0.0) throw std::string("This is not a triangle!");

        }else{
          throw std::string("This is not a triangle!");
        }

    }
    Triangle(std::string id, std::vector<TwoDimensionalCoordinate*> vectors, std::string color): Shape(id,color){
        if (vectors.size()==3){
            // a = sqrt(deltaX ^2 + deltaY ^2)
            _vectors = vectors;
            _a = sqrt(pow((vectors[0]->getX()-vectors[1]->getX()),2) + pow((vectors[0]->getY()-vectors[1]->getY()),2));
            _b = sqrt(pow((vectors[0]->getX()-vectors[2]->getX()),2) + pow((vectors[0]->getY()-vectors[2]->getY()),2));
            _c = sqrt(pow((vectors[1]->getX()-vectors[2]->getX()),2) + pow((vectors[1]->getY()-vectors[2]->getY()),2));
            _id = id;
            _color = color;
            if(area()<= 0.0) throw std::string("This is not a triangle!");

        }else{
          throw std::string("This is not a triangle!");
        }
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
      double s = (_a + _b + _c) / 2;
      return sqrt(s * (s - _a) * (s - _b) * (s - _c));
    }

    double perimeter() const {
        return  TruncateNumberDouble(_a + _b + _c);
    }

    string info() const {

        return "Triangle (["
                          +TruncateNumberStr(_vectors[0]->getX())+", "
                          +TruncateNumberStr(_vectors[0]->getY())+"], "
                          +"["+TruncateNumberStr(_vectors[1]->getX())+", "
                          +TruncateNumberStr(_vectors[1]->getY())+"], "
                          +"["+TruncateNumberStr(_vectors[2]->getX())+", "
                          +TruncateNumberStr(_vectors[2]->getY())
                          +"])";
    }

    std::string type() const {
      return "Triangle";
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

    std::vector<TwoDimensionalCoordinate*> getVector(){
      return _vectors;
    }

private:
    double _a, _b, _c;
    std::vector<TwoDimensionalCoordinate*> _vectors;
    std::string _color="white";
    std::string _id="";
  };
#endif
