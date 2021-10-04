#include "../include/Pattern.h"


template<typename color_value_type>
ColorSingle<color_value_type> Pattern<color_value_type>::get_color_single(const Coordinate &led_coordinate) {
    return ColorSingle<color_value_type>();
}

template<typename color_value_type>
ColorRGB<color_value_type> Pattern<color_value_type>::get_color_RGB(const Coordinate &led_coordinate) {
    return ColorRGB<color_value_type>();
}

template<typename color_value_type>
ColorAlpha<color_value_type> Pattern<color_value_type>::get_transparency_mask(const Coordinate &led_coordinate) {
    // Always max
    return ColorAlpha<color_value_type>();
}

template<typename color_value_type>
ColorRGBA<color_value_type> Pattern<color_value_type>::get_color_RGBA(const Coordinate &led_coordinate) {
    ColorRGBA<color_value_type> rgb = this->get_color_RGB(led_coordinate);
    return ColorRGBA<color_value_type>();
}

template<typename color_value_type>
float Pattern<color_value_type>::getOffset() const {
    return animation_offset;
}

template<typename color_value_type>
void Pattern<color_value_type>::setOffset(float new_offset) {
    animation_offset = new_offset;
}

template<typename color_value_type>
void Pattern<color_value_type>::addOffset(float offset_to_add) {
    animation_offset += offset_to_add;
}


template<typename color_value_type>
ColorSingle<color_value_type> SineWaveAnimator<color_value_type>::get_color_single(const Coordinate &led_coordinate) {
    ColorSingle<color_value_type> color;
    color = ColorSingle<color_value_type>();
    color.setColor(sin(led_coordinate.getX() * this->x_scale) + this->getOffset());
    return color;
}

template<typename color_value_type>
ColorRGB<color_value_type> SineWaveAnimator<color_value_type>::get_color_RGB(const Coordinate &led_coordinate) {
    ColorRGB<color_value_type> color{};
    color.setRed(led_coordinate.getX() * this->x_scale + this->getOffset());
    color.setGreen(led_coordinate.getY() * this->y_scale + this->getOffset());
    color.setBlue(this->getOffset());
    return color;
}
