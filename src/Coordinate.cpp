#include <cmath>
#include "../include/Coordinate.h"

float Coordinate::getX() const {
    return x;
}

float Coordinate::getY() const {
    return y;
}

float Coordinate::getTheta() const {
    return atan2f(y, x);
}

float Coordinate::getR() const {
    return hypotf(x, y);
}

Coordinate::Coordinate() {}

Coordinate::Coordinate(float x, float y) : x(x), y(y) {
}

Coordinate Coordinate::calculate_relative(Coordinate origin) const {
    return (*this) - origin;
}

Coordinate Coordinate::calculate_relative(const Coordinate &origin) const {
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
