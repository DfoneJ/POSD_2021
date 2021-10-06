#ifndef TWO_DIMENSIONAL_H
#define TWO_DIMENSIONAL_H

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
            return 0;
        }

        double dot(TwoDimensionalVector vec) const {

        }

        double cross(TwoDimensionalVector vec) const {

        }

        TwoDimensionalVector subtract(TwoDimensionalVector vec) const {

        }

        std::string info() const {
            char information[63];
            sprintf(information, "[%.2lf,%.2lf]", (double round(_x*100.00))/100.00, (double round(_y*100.00))/100.00);
            return information;
        }
    private:
        double _x,_y;
};

#endif