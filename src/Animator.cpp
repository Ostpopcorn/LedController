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
ColorSingle<color_value_type> Animator<color_value_type>::get_color_single() {
    return ColorSingle<color_value_type>();
}

template<typename color_value_type>
ColorRGB<color_value_type> Animator<color_value_type>::get_color_RGB() {
    return ColorRGB<color_value_type>();
}


template<typename color_value_type>
ColorSingle<color_value_type> SineWaveAnimator<color_value_type>::get_color_single() {
    return ColorSingle<color_value_type>();
}

template<typename color_value_type>
ColorRGB<color_value_type> SineWaveAnimator<color_value_type>::get_color_RGB() {
    return ColorRGB<color_value_type>();
}
