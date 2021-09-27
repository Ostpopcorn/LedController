#ifndef LED_MATRIX_CONTROL_ANIMATOR_H
#define LED_MATRIX_CONTROL_ANIMATOR_H


class Animator {
public:
    void tick_time();

    void set_time(int new_time);


private:
    int time{};
    float time_step{};
};

class SineWaveAnimator : public Animator {

};

#endif //LED_MATRIX_CONTROL_ANIMATOR_H
