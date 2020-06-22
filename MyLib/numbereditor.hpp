#ifndef NUMBEREDITOR_HPP
#define NUMBEREDITOR_HPP

#include "widget.hpp"
#include "graphics.hpp"

class NumberEditor : public Widget{
    std::string _snum;
    bool _cursor_visible;
public:
    NumberEditor(int x, int y, int sx, int sy = 30); //genv::gout.cascent()+genv::gout.cdescent()+7
    void handle(genv::event ev) override;
    void show() override;
};

#endif // NUMBEREDITOR_HPP
