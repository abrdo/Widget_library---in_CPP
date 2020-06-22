#ifndef DYNAMICTEXT_HPP
#define DYNAMICTEXT_HPP

#include "widget.hpp"
#include "graphics.hpp"

class DynamicText : public Widget{
    std::string _text;
public:
    DynamicText(int x, int y, int sx, int sy);
    void handle(genv::event ev) override;
    void show() override;
};

#endif // DYNAMICTEXT_HPP
