#include "../include/LedController.h"


template<int led_type, typename color_value_type>
void LedController<led_type, color_value_type>::tick_time() {
    time += time_step;
    for (typename std::list<AnimationLayer>::iterator i = std::begin(list); i != std::end(list); ++i) {
        i->pattern.addOffset(time_step);
        // Checks if it is old enough to be removed it should be removed.
        if (i->termination_offset != 0) {
            if (i->pattern.getOffset() > i->termination_offset) {
                list.erase(i);
            }
        }
    }
}

template<int led_type, typename color_value_type>
float LedController<led_type, color_value_type>::getTime() const {
    return time;
}

template<int led_type, typename color_value_type>
void LedController<led_type, color_value_type>::set_time(float new_time) {
    time = new_time;
    for (AnimationLayer layer: list) {
        layer.local_time = time;
    }
}
