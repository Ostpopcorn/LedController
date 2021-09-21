#ifndef LED_MATRIX_CONTROL_LED_H
#define LED_MATRIX_CONTROL_LED_H

#include "Coordinate.h"

class Led {
public:
    Led();

    Led(const Coordinate &coordinate);

private:
    Coordinate coordinate{};
};


template<typename led_value_type>
class LedRGB : public Led{
public:
    LedRGB();

    LedRGB(const Coordinate &coordinate);

    void setRed(led_value_type red);

    void setGreen(led_value_type green);

    void setBlue(led_value_type blue);

private:
    bool isValidLedValue(led_value_type value);
    led_value_type red{};
    led_value_type green{};
    led_value_type blue{};
};



#endif //LED_MATRIX_CONTROL_LED_H
