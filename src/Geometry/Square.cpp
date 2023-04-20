#include "Square.h"
#include <cmath>
#include <cstdlib>
#include "../Service/ExceptionService.h"
using namespace CustomExceptions;
namespace Geometry{
    Square::Square(double x, double y, double side, double angle)
            : x(x), y(y), side(side), angle(angle) {}

    bool Square::operator==(const Square& other) const {
        return (this->x == other.x && this->y == other.y &&
                this->side == other.side && this->angle == other.angle);
    }

    bool Square::operator!=(const Square& other) const {
        return !(*this == other);
    }

    bool Square::operator<(const Square& other) const {
        return squareArea(*this) < squareArea(other);
    }

    bool Square::operator>(const Square& other) const {
        return squareArea(*this) > squareArea(other);
    }

    Square Square::operator*(double num) const {
        return {x, y, side * num, angle};
    }

    Square Square::operator+(const std::pair<double, double>& vec) const {
        double newX = x + vec.first;
        double newY = y + vec.second;
        return {newX, newY, side, angle};
    }

    Square *Square::create(int argc, char* argv[]) {
        if (argc < 5){
            throw NotEnoughArgumentsException();
        }
        return new Square(std::atof(argv[1]),
                          std::atof(argv[2]),
                          std::atof(argv[3]),
                          std::atof(argv[4]));
    }


    double squareArea(const Square& square) {
        double radAngle = square.getAngle() * M_PI / 180.0;
        double cosA = cos(radAngle);
        double sinA = sin(radAngle);
        std::pair<double, double> vec1 = std::make_pair(square.getSide() * cosA, square.getSide() * sinA);
        std::pair<double, double> vec2 = std::make_pair(-square.getSide() * sinA, square.getSide() * cosA);
        return parallelogramArea(vec1, vec2);
    }

    double parallelogramArea(const std::pair<double, double>& vec1, const std::pair<double, double>& vec2) {
        return fabs(vec1.first * vec2.second - vec1.second * vec2.first);
    }


}
