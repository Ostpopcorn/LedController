//
// Created by adrian on 2021-09-20.
//

#include <cmath>
#include "../include/led.h"

void led::calculate_polar() {
        r = hypotf(x,y);
        theta = atan2f(y,x);
}
