#include <cstdint>
#include "../include/Led.h"

Led::Led() {}

Led::Led(const Coordinate &coordinate) : coordinate(coordinate) {}

template<typename led_value_type>
LedRGB<led_value_type>::LedRGB() {}

template<typename led_value_type>
LedRGB<led_value_type>::LedRGB(const Coordinate &coordinate):Led(coordinate) {}

template<typename led_value_type>
void LedRGB<led_value_type>::setRed(led_value_type red) {
    if (isValidLedValue(red)){
        LedRGB::red = red;
    }else{
        //Out of bounds
    }
}

template<typename led_value_type>
void LedRGB<led_value_type>::setGreen(led_value_type green) {
    if (isValidLedValue(green)){
        LedRGB::green = green;
    }else{
        //Out of bounds
    }
}

template<typename led_value_type>
void LedRGB<led_value_type>::setBlue(led_value_type blue) {
    if (isValidLedValue(blue)){
        LedRGB::blue = blue;
    }else{
        //Out of bounds
    }
}

template<typename led_value_type>
bool LedRGB<led_value_type>::isValidLedValue(led_value_type value) {
    return value > 0;
}

