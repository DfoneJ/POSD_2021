#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle: public Shape {
    public:
        Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
            
        }

        double area() const { }

        double perimeter() const { }

        std::string info() const { }
};

#endif