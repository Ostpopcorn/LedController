#ifndef LED_MATRIX_CONTROL_ANIMATOR_H
#define LED_MATRIX_CONTROL_ANIMATOR_H

#include "Color.h"
#include <cmath>

template<typename color_value_type>
class Animator {
public:
    void tick_time();

    void set_time(float new_time);

    virtual ColorSingle<color_value_type> get_color_single();

    virtual ColorRGB<color_value_type> get_color_RGB();

    float getTime() const;

private:
    float time{0};
    float time_step{0.1};
};

template<typename color_value_type>
class SineWaveAnimator : public Animator<color_value_type> {
public:
    ColorSingle<color_value_type> get_color_single() override;

    ColorRGB<color_value_type> get_color_RGB() override;

private:
};

#endif //LED_MATRIX_CONTROL_ANIMATOR_H
