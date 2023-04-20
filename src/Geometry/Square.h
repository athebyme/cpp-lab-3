#ifndef CPP_SQUARE_LAB3_SQUARE_H
#define CPP_SQUARE_LAB3_SQUARE_H
#include <utility>


namespace Geometry{
    class Square {
    private:
        double x;
        double y;
        double side;
        double angle;
    public:
        Square(double x, double y, double side, double angle);

        bool operator==(const Square& other) const;
        bool operator!=(const Square& other) const;
        bool operator<(const Square& other) const;
        bool operator>(const Square& other) const;

        double getAngle() const {
            return this->angle;
        }

        double getSide() const{
            return this->side;
        }
        double getX() const {
            return this->x;
        }
        double getY() const {
            return this->y;
        }

        Square operator*(double num) const;

        Square operator+(const std::pair<double, double>& vec) const;

        static Square* create(int argc, char *argv[]);
    };
    double squareArea(const Square& square);

    double parallelogramArea(const std::pair<double, double>& vec1, const std::pair<double, double>& vec2);
}
#endif
