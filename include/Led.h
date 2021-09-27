#ifndef LED_MATRIX_CONTROL_LED_H
#define LED_MATRIX_CONTROL_LED_H

#include "Coordinate.h"
#include "Color.h"
class Led {
public:
    Led();

    Led(const Coordinate &coordinate);

    Led(Coordinate &&coordinate);

private:
    Coordinate coordinate{};
};


template<typename color_value_type>
class LedRGB : public Led {
public:
    LedRGB();

    LedRGB(Coordinate &&coordinate);

    LedRGB(const Coordinate &coordinate);

private:
    ColorRGB<color_value_type> color{};

};



#endif //LED_MATRIX_CONTROL_LED_H
