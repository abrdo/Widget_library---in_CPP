#ifndef IIIIIIIIIIIIIIIIIIII_HPP
#define IIIIIIIIIIIIIIIIIIII_HPP

#include "widget.hpp"
#include "graphics.hpp"

class IIIIIIIIIIIIIIIIIIII : public Widget{
public:
    IIIIIIIIIIIIIIIIIIII(int x, int y, int sx, int sy);
    void handle(genv::event ev) override;
    void show() override;
};

#endif // IIIIIIIIIIIIIIIIIIII_HPP
