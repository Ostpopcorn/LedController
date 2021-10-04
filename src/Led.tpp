#include <cstdint>
#include <utility>
#include "../include/Led.h"

Led::Led() {}

Led::Led(const Coordinate &coordinate) : coordinate(coordinate) {}

Led::Led(Coordinate &&coordinate) : coordinate(coordinate) {}


template<typename led_value_type>
LedRGB<led_value_type>::LedRGB() {}

template<typename led_value_type>
LedRGB<led_value_type>::LedRGB(const Coordinate &coordinate):Led(coordinate) {}

template<typename color_value_type>
LedRGB<color_value_type>::LedRGB(Coordinate &&coordinate):Led(coordinate) {

}

template<typename color_value_type>
const ColorRGB<color_value_type> &LedRGB<color_value_type>::getColor() const {
    return color;
}

template<typename color_value_type>
void LedRGB<color_value_type>::setColor(const ColorRGB<color_value_type> &color) {
    LedRGB::color = color;
}
