#include "graphics.hpp"
#include "funcbutton.hpp"
#include <iostream>

using namespace std;
using namespace genv;

 FuncButton::FuncButton(int x, int y, std::string label, /*std::function<void()> func,*/ int sx, int sy) : Widget(x,y,sx,sy),/*_f(func),*/_label(label){};

void FuncButton::handle(genv::event ev){
    focus_by_click(ev);
    if(focusing_click(ev)
       || is_focused() && ev.keycode == key_enter){
        call();
    }
}

void FuncButton::call(){
    _f(); //f(this);
}

void FuncButton::show(genv::canvas &c){
    c<<color(255,255,255);
    c << move_to(_x+_size_x/2-c.twidth(_label)/2, _y+_size_y/2-_fonthight/2)<< text(_label);
    show_frame(c);
}
