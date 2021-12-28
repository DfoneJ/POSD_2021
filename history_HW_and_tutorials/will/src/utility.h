#ifndef UTILITY_H
#define UTILITY_H
#include "./shape.h"

#include <iostream>

#include <deque>

class Utility {
  public:
    Utility() {}
};

Shape * getShapeById(Shape * shape, std::string id) {
  // access the shape with iterator pattern.
  // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
  // return a shape under the input shape tree sturcture that matches the id.
  // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
  // throw std::string "Expected get shape but shape not found" when no shape found with the given id.

  Iterator * it = shape -> createIterator();

  if (it -> isDone()) {
    throw std::string("Only compound shape can get shape!");
  }

  for (it -> first(); !it -> isDone(); it -> next()) {
    if (it -> currentItem() -> id() == id) {
      return it -> currentItem();
    }
    try{                                //不然就去其中的子圖找找
        return  getShapeById(it -> currentItem(),id);
    }catch(string e){}                  //各子圖找不到的話，不處理
  }

  throw std::string("Expected get shape but shape not found"); //在所有子圖都找不到才會丟出例外
}

template < class Filter >
  std::deque < Shape * > filterShape(Shape * shape, Filter filter) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturcture that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
    std::deque<Shape *> deque1;                                // empty deque of Shape
    Iterator * it = shape -> createIterator();
    if (it -> isDone()) {
      throw std::string("Only compound shape can filter shape!");
    }

    for (it -> first(); !it -> isDone(); it -> next()) {
      if (filter(it->currentItem())) {
         deque1.push_back(it->currentItem());
      }
      try{                                //不然就去其中的子圖找找
          std::deque<Shape *>deque2 = filterShape(it->currentItem(),filter);
          // cout<<"子圖 deque size:"<<deque2.size()<<endl;
          for(std::deque<Shape*>::const_iterator deque_It=deque2.begin() ; deque_It!=deque2.end() ; deque_It++){
              deque1.push_back(*deque_It);
              // cout<<"deque2:"<<(*deque_It)->info()<<endl;
          }
      }catch(string e){}                  //各子圖找不到的話，不處理
    }
    return deque1;
  }

class AreaFilter {
  public:
    AreaFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {

    }
  bool operator()(Shape * shape) const {
    return (shape -> area() <= _upperBound) && (shape -> area() >= _lowerBound);
  }
  private:
    const double _upperBound;
    const double _lowerBound;

};

class PerimeterFilter {
  public:
    PerimeterFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {

    }
  bool operator()(Shape * shape) const {
    return (shape -> perimeter() <= _upperBound) && (shape -> perimeter() >= _lowerBound);
  }
  private:
    const double _upperBound;
    const double _lowerBound;
};

class ColorFilter {
  public:
    ColorFilter(std::string color): _color(color) {}
  bool operator()(Shape * shape) const {
    return shape -> color() == _color;
  }
  private:
    const std::string _color;
};

class TypeFilter {
  public:
    TypeFilter(std::string type): _type(type) {}
  bool operator()(Shape * shape) const {
    return shape -> type() == _type;
  }
  private:
    const std::string _type;
};

#endif
