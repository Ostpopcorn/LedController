//
// Created by adied_000 on 2021-09-27.
//

#ifndef LED_MATRIX_CONTROL_COLOR_H
#define LED_MATRIX_CONTROL_COLOR_H


template<typename color_value_type>
class ColorRGB {

    void setColor(color_value_type input_red, color_value_type input_green, color_value_type input_blue);

    void setRed(color_value_type input_red);

    void setGreen(color_value_type input_green);

    void setBlue(color_value_type input_blue);

private:
    bool isValidLedValue(color_value_type value);

    color_value_type red{};
    color_value_type green{};
    color_value_type blue{};
};


#endif //LED_MATRIX_CONTROL_COLOR_H
