#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

class StaticText : public Widget
{
    std::string _text;
    unsigned char _r, _g, _b;
public:
    StaticText(){}
    StaticText(int x, int y, std::string text, unsigned char r = 180, unsigned char g = 180, unsigned char = 180 );
    void show() override;

};

#endif // STATICTEXT_HPP
