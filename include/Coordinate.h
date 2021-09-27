#ifndef LED_MATRIX_CONTROL_COORDINATE_H
#define LED_MATRIX_CONTROL_COORDINATE_H


class Coordinate {
public:
    Coordinate();

    Coordinate(float x, float y);

    float getX() const;

    float getY() const;

    float getTheta() const;

    float getR() const;

    Coordinate calculate_relative(float origin_x, float origin_y) const;

    Coordinate calculate_relative(Coordinate origin) const;

    Coordinate calculate_relative(const Coordinate &origin) const;

    bool operator==(const Coordinate &rhs) const;

    bool operator!=(const Coordinate &rhs) const;

    Coordinate operator+(const Coordinate &rhs) const;

    Coordinate operator-(const Coordinate &rhs) const;

private:
    float x{0.0};
    float y{0.0};


};


#endif //LED_MATRIX_CONTROL_COORDINATE_H
