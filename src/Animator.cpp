#include "../include/Animator.h"

void Animator::tick_time() {
    ++time;
}

void Animator::set_time(int new_time) {
    time = new_time;
}
