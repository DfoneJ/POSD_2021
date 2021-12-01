#ifndef TWO_DIMENSIONAL_H
#define TWO_DIMENSIONAL_H
#include <math.h>

class TwoDimensionalVector {
    public:
        TwoDimensionalVector(double x, double y) {
            _x = x;
            _y = y;
        }

        double x() const {
            return _x;
        }

        double y() const {
            return _y;
        }

        double length() const {
            return sqrt(pow(_x,2) + pow(_y,2));
        }

        double dot(TwoDimensionalVector vec) const {
            return (_x * vec.x()) + (_y * vec.y());
        }

        double cross(TwoDimensionalVector vec) const {
            return (_x * vec.y()) - (_y * vec.x());
        }

        TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
            TwoDimensionalVector vector(_x-vec.x(),_y-vec.y());
            return vector;
        }

        std::string info() const {
            char information[63];
            sprintf(information, "[%.2lf,%.2lf]", (round(_x*100.00))/100.00, (round(_y*100.00))/100.00);
            return information;
        }
    private:
        double _x,_y;
};

#endif