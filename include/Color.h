#ifndef LED_MATRIX_CONTROL_COLOR_H
#define LED_MATRIX_CONTROL_COLOR_H


#include <limits>

template<typename color_value_type>
class ColorBase {
public:
    static bool isValidLedValue(color_value_type value);

    static inline color_value_type maxLedValue{std::numeric_limits<color_value_type>::max()};
    static inline color_value_type minLedValue{0};
};

template<typename color_value_type>
class ColorAlpha {
public:
    ColorAlpha() = default;

    ColorAlpha(color_value_type alpha);

    color_value_type getAlpha() const;

    void setAlpha(color_value_type alpha);

private:
    // initialize with maximum possible value so stating value is opaque
    color_value_type alpha{ColorBase<color_value_type>::maxLedValue};
};


template<typename color_value_type>
class ColorSingle : public ColorBase<color_value_type> {

public:
    void setColor(color_value_type input_color);

    color_value_type getColor() const;

private:
    // initialize with maximum possible value
    color_value_type color{ColorBase<color_value_type>::maxLedValue};
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
    // initialize with maximum possible value so stating color is white
    color_value_type red{ColorBase<color_value_type>::maxLedValue};
    color_value_type green{ColorBase<color_value_type>::maxLedValue};
    color_value_type blue{ColorBase<color_value_type>::maxLedValue};
};

template<typename color_value_type>
class ColorRGBA : public ColorRGB<color_value_type>, public ColorAlpha<color_value_type> {
public:
    ColorRGBA() = default;

    ColorRGBA(color_value_type red, color_value_type green, color_value_type blue, color_value_type alpha);

    // Functions for creating RGBA from RGB
    ColorRGBA(ColorRGB<color_value_type> &&rhs);

    ColorRGBA<color_value_type> &operator=(const ColorRGB<color_value_type> &rhs);

};

#include "../src/Color.tpp"
#include "../src/ColorRGB.tpp"
#include "../src/ColorRGBA.tpp"

#endif //LED_MATRIX_CONTROL_COLOR_H
