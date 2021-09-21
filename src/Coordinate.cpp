#include <cmath>
#include "../include/Coordinate.h"

void Coordinate::calculate_polar() {
    r = hypotf(x, y);
    theta = atan2f(y, x);
}

float Coordinate::getX() const {
    return x;
}

float Coordinate::getY() const {
    return y;
}

float Coordinate::getTheta() const {
    return theta;
}

float Coordinate::getR() const {
    return r;
}

Coordinate::Coordinate() {}

Coordinate::Coordinate(float x, float y) : x(x), y(y) {
    calculate_polar();
}

Coordinate Coordinate::calculate_relative(Coordinate origin) const {
    return (*this) - origin;
}

Coordinate Coordinate::calculate_relative(float origin_x, float origin_y) const {
    return (*this) - Coordinate{origin_x, origin_y};
}

bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Coordinate::operator!=(const Coordinate &rhs) const {
    return !(rhs == *this);
}

Coordinate Coordinate::operator+(const Coordinate &rhs) const {
    return Coordinate{getX() + rhs.getX(), getY() + rhs.getY()};
}

Coordinate Coordinate::operator-(const Coordinate &rhs) const {
    return Coordinate{getX() - rhs.getX(), getY() - rhs.getY()};
}
