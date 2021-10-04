#include "../include/Color.h"

template<typename color_value_type>
ColorRGBA<color_value_type>::ColorRGBA(color_value_type red, color_value_type green, color_value_type blue,
                                       color_value_type alpha):
        ColorRGB<color_value_type>(red, green, blue),
        ColorAlpha<color_value_type>(alpha) {

}

template<typename color_value_type>
ColorRGBA<color_value_type> &ColorRGBA<color_value_type>::operator=(const ColorRGB<color_value_type> &rhs) {
    this->setRed(rhs.getRed());
    this->setGreen(rhs.getGreen());
    this->setBlue(rhs.getBlue());
    this->setAlpha(std::numeric_limits<color_value_type>::max());
}

template<typename color_value_type>
ColorRGBA<color_value_type>::ColorRGBA(ColorRGB<color_value_type> &&rhs) {
    this->setRed(rhs.getRed());
    this->setGreen(rhs.getGreen());
    this->setBlue(rhs.getBlue());
    this->setAlpha(std::numeric_limits<color_value_type>::max());

}