#if !defined( SHAPE_H )
#define SHAPE_H
#include <math.h>
#include <stdexcept>
#include "two_dimensional_coordinate.h"
#include "iterator.h"
#include "null_iterator.h"
#include "visitor.h"

using namespace std;

class Shape {
public:
   Shape(std::string id); // interface for default color "white".
   Shape(std::string id, std::string color); // interface for color input by user.

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual std::string type() const = 0;
    virtual void accept(Visitor* visitor) = 0;

    std::string id() const;
    std::string color() const;
    void setColor(std::string color);
    // for setting color.

    virtual void addShape(Shape *shape);
    virtual void deleteShapeById(std::string id);
    virtual Shape* getShapeById(std::string id) const;
    virtual Iterator* createIterator() const;



    virtual ~Shape(){}
protected:
  std::string _color="white";
  std::string _id="";



};
#endif
