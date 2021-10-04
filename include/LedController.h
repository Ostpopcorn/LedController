#ifndef LED_MATRIX_CONTROL_LEDCONTROLLER_H
#define LED_MATRIX_CONTROL_LEDCONTROLLER_H

#include <list>
#include "Pattern.h"

// TODO read led configuration from file.
// TODO Make animations stackable
typedef enum {
    PWM_PINS = 1,
    WS2812B,
} led_type_t;

/*
 * LedController is the map between Animation objects and the output to the leds.
 */
template<int led_type, typename color_value_type>
class LedController {

    class AnimationLayer {
    public:
        Pattern<color_value_type> pattern{};

        // Some notion of when it should be removed.
        // if zero it will persist
        float termination_offset{0};
        // Maybe a type, so if it is induced by other or the "base" animation
        // That could possibly also handle transparency
    };

    /*
     * All current animations are layered so the animation that is on the end
     * of the list is with top priority.
     */
    std::list<AnimationLayer> list{};
    float time_step{0.1};
    float time{0};

    /*
     * Steps a time step
     */
    void tick_time();

    /*
     * Gets scaled current time that the animation uses.
     */
    float getTime() const;

    /*
     * Sets current time
     */
    void set_time(float new_time);

};

/*
 * WS2812B definition
 */
template<>
class LedController<WS2812B, u_int8_t> {

};

#include "../src/LedController.tpp"

#endif //LED_MATRIX_CONTROL_LEDCONTROLLER_H
