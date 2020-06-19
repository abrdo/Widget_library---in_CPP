#include "widget.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy){}

void Widget::set_focused(bool f) {_focused = f;}

bool Widget::is_selected(int mx, int my){
    return _x<=mx && mx<=(_x+_size_x) && _y<=my && my<_size_y;
}

void Widget::handle(event ev){}
