#ifndef LED_MATRIX_CONTROL_COLOR_H
#define LED_MATRIX_CONTROL_COLOR_H

template<typename color_value_type>
class ColorBase {
protected:

    bool isValidLedValue(color_value_type value);
};

template<typename color_value_type>
class ColorSingle : public ColorBase<color_value_type> {

public:
    void setColor(color_value_type input_color);

    color_value_type getColor() const;

private:
    color_value_type color{};
};


template<typename color_value_type>
class ColorRGB : public ColorBase<color_value_type> {
public:
    ColorRGB() = default;

    ColorRGB(color_value_type red, color_value_type green, color_value_type blue);

    void setColor(color_value_type input_red, color_value_type input_green, color_value_type input_blue);

    color_value_type getRed() const;

    color_value_type getGreen() const;

    color_value_type getBlue() const;

    void setRed(color_value_type input_red);

    void setGreen(color_value_type input_green);

    void setBlue(color_value_type input_blue);

private:
    color_value_type red{};
    color_value_type green{};
    color_value_type blue{};
};


#endif //LED_MATRIX_CONTROL_COLOR_H
