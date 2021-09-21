//
// Created by adrian on 2021-09-20.
//

#ifndef LED_MATRIX_CONTROL_LED_H
#define LED_MATRIX_CONTROL_LED_H


class led {
private:
    float x{0.0};
    float y{0.0};

    void calculate_polar();
    float theta{0.0};
    float r{0.0};

};


#endif //LED_MATRIX_CONTROL_LED_H
