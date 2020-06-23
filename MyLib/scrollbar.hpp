#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "widget.hpp"
#include "graphics.hpp"

struct ScrollBar : public Widget{
    ScrollBar(int x, int y, int sx, int sy);
    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) override;
};

#endif // SCROLLBAR_HPP
