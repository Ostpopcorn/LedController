#ifndef LED_MATRIX_CONTROL_PATTERN_H
#define LED_MATRIX_CONTROL_PATTERN_H

#include "Color.h"
#include "Coordinate.h"
#include <cmath>

template<typename color_value_type>
class Pattern {
public:
    /*
     * Animations dont know what time it is, but the do have an offset so animations
     * can still run, this offset is set by some external logic.
     */

    float getOffset() const;

    void addOffset(float offset_to_add);

    void setOffset(float new_offset);

    /*
     * Virtual functions that can be used to get color, these are supposed to be overwritten
     * to give a good interface when choosing from different animations.
     * All different color schemes get its own function, currently single color and RGB color are
     * implemented.
     */
    virtual ColorSingle<color_value_type> get_color_single(const Coordinate &led_coordinate);

    virtual ColorRGB<color_value_type> get_color_RGB(const Coordinate &led_coordinate);

    virtual ColorAlpha<color_value_type> get_transparency_mask(const Coordinate &led_coordinate);

    virtual ColorRGBA<color_value_type> get_color_RGBA(const Coordinate &led_coordinate);


    /*
     * Scales the animations in given direction.
     */
    float x_scale{1.0};
    float y_scale{1.0};

private:
    float animation_offset{0.0};

};

/*
 * A simple sine wave animation to test the system.
 */
template<typename color_value_type>
class SineWaveAnimator : public Pattern<color_value_type> {
public:
    ColorSingle<color_value_type> get_color_single(const Coordinate &led_coordinate) override;

    ColorRGB<color_value_type> get_color_RGB(const Coordinate &led_coordinate) override;

private:
};

#include "../src/Pattern.tpp"

#endif //LED_MATRIX_CONTROL_PATTERN_H
