#include "../include/Animator.h"

template<typename color_value_type>
void Animator<color_value_type>::tick_time() {
    time += time_step;
}

template<typename color_value_type>
void Animator<color_value_type>::set_time(float new_time) {
    time = new_time;
}

template<typename color_value_type>
float Animator<color_value_type>::getTime() const {
    return time;
}


template<typename color_value_type>
ColorSingle<color_value_type> Animator<color_value_type>::get_color_single(const Coordinate &led_coordinate) {
    return ColorSingle<color_value_type>();
}

template<typename color_value_type>
ColorRGB<color_value_type> Animator<color_value_type>::get_color_RGB(const Coordinate &led_coordinate) {
    return ColorRGB<color_value_type>();
}


template<typename color_value_type>
ColorSingle<color_value_type> SineWaveAnimator<color_value_type>::get_color_single(const Coordinate &led_coordinate) {
    ColorSingle<color_value_type> color;
    color = ColorSingle<color_value_type>();
    color.setColor(sin(led_coordinate.getX() * this->x_scale) + this->getTime());
    return color;
}

template<typename color_value_type>
ColorRGB<color_value_type> SineWaveAnimator<color_value_type>::get_color_RGB(const Coordinate &led_coordinate) {
    ColorRGB<color_value_type> color{};
    color.setRed(led_coordinate.getX() * this->x_scale + this->getTime());
    color.setGreen(led_coordinate.getY() * this->y_scale + this->getTime());
    color.setBlue(this->getTime());
    return color;
}
