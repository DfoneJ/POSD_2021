#pragma once

#include <math.h>

class TwoDimensionalVector {
    public:
        TwoDimensionalVector() {}
        TwoDimensionalVector(double x, double y) : _x(x), _y(y) { sprintf(_info, "[%.2lf,%.2lf]", (round(_x*100))/100, (round(_y*100))/100); }

        double x() const { return _x; }

        double y() const { return _y; }

        double length() const { return sqrt(pow(_x,2) + pow(_y,2)); }

        double dot(TwoDimensionalVector vec) const { return (_x * vec.x()) + (_y * vec.y()); }

        double cross(TwoDimensionalVector vec) const { return (_x * vec.y()) - (_y * vec.x()); }

        TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
            TwoDimensionalVector vector(_x-vec.x(),_y-vec.y());
            return vector;
        }

        std::string info() const { return _info; }

    private:
        double _x, _y;
        char _info[15];
};
