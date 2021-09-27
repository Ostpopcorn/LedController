#ifndef LED_MATRIX_CONTROL_ANIMATOR_H
#define LED_MATRIX_CONTROL_ANIMATOR_H

#include "Color.h"
#include "Coordinate.h"
#include <cmath>


template<typename color_value_type>
class Animator {
public:
    /*
     * Steps a time step
     */
    void tick_time();

    void set_time(float new_time);

    /*
     * Virtual functions that can be used to get color, these are supposed to be overwritten
     * to give a good interface when choosing from different animations.
     * All different color schemes get its own function, currently single color and RGB color are
     * implemented.
     */
    virtual ColorSingle<color_value_type> get_color_single(const Coordinate &led_coordinate);

    virtual ColorRGB<color_value_type> get_color_RGB(const Coordinate &led_coordinate);

    /*
     * Gets scaled current time that the animation uses.
     */
    float getTime() const;

    /*
     * Scales the animations in given direction.
     */
    float x_scale{1.0};
    float y_scale{1.0};

private:
    float time{0};
    float time_step{0.1};
};

/*
 * A simple sine wave animation to test the system.
 */
template<typename color_value_type>
class SineWaveAnimator : public Animator<color_value_type> {
public:
    ColorSingle<color_value_type> get_color_single(const Coordinate &led_coordinate) override;

    ColorRGB<color_value_type> get_color_RGB(const Coordinate &led_coordinate) override;

private:
};

#endif //LED_MATRIX_CONTROL_ANIMATOR_H
