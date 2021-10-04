#ifndef LED_MATRIX_CONTROL_LEDCONTROLLER_H
#define LED_MATRIX_CONTROL_LEDCONTROLLER_H

// TODO Add alpha masks.
#include "Animator.h"

// TODO read led configuration from file.
// TODO Make animations stackable
typedef enum {
    PWM_PINS = 1,
    WS2812B,
} led_type_t;

/*
 * LedController is the map between Animation objects and the output to the leds.
 */
template<int led_type>
class LedController {
};

/*
 * WS2812B definition
 */
template<>
class LedController<WS2812B> {
    Animator<u_int8_t> current_animation{};
};

#include "../src/LedController.tpp"

#endif //LED_MATRIX_CONTROL_LEDCONTROLLER_H
