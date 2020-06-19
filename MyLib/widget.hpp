#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget
{
protected:
    int _x, _y, _size_x, _size_y;
    bool _focused;

public:
    Widget(int x, int y, int sx, int sy);
    void set_focused(bool f);

    bool is_selected(int mouse_x, int mouse_y);
    virtual void handle(genv::event ev);
    virtual void show() = 0;


};

#endif // WIDGET_HPP
