#include "../include/Color.h"

template<typename led_value_type>
bool ColorBase<led_value_type>::isValidLedValue(led_value_type value) {
    return value > 0;
}

template<typename color_value_type>
color_value_type ColorAlpha<color_value_type>::getAlpha() const {
    return alpha;
}

template<typename color_value_type>
void ColorAlpha<color_value_type>::setAlpha(color_value_type in_alpha) {
    alpha = in_alpha;
}

template<typename color_value_type>
ColorAlpha<color_value_type>::ColorAlpha(color_value_type alpha):alpha(alpha) {}

template<typename color_value_type>
void ColorSingle<color_value_type>::setColor(color_value_type input_color) {
    if (isValidLedValue(input_color)) {
        ColorSingle::red = input_color;
    } else {
        //Out of bounds
    }
}

template<typename color_value_type>
color_value_type ColorSingle<color_value_type>::getColor() const {
    return color;
}
