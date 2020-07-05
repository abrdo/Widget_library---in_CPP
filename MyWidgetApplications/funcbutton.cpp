#include "graphics.hpp"
#include "funcbutton.hpp"
#include <iostream>

using namespace std;
using namespace genv;

FuncButton::FuncButton(int x, int y, std::string label, std::function<void()> func, int sx, int sy)
                    : Widget(x,y,sx,sy), _f(func), _label(label), _pushed(false){}

void FuncButton::handle(genv::event ev){
    focus_by_click(ev);
    if(focusing_click(ev) || _focused && (ev.keycode == key_enter || ev.keycode == key_space)){
        _f();
        _pushed = true;
    }
    if(_pushed && (ev.button == -btn_left || ev.keycode == -key_enter || ev.keycode == -key_space)){
        _pushed = false;
        if(ev.keycode != -key_enter && ev.keycode != -key_space){
            _focused = false;
        }
    }

}

void FuncButton::show(genv::canvas &c) const{
    c<<move_to(_x,_y)<<color(_bgcol_r, _bgcol_g, _bgcol_b)<<box(_size_x, _size_y);
    if(!_focusable) c<<color(130,130,130);
    else if(_pushed) c<<color(90,90,90);
    else c<<color(255,255,255);
    c << move_to(_x+_size_x/2-c.twidth(_label)/2, _y+_size_y/2-_fonthight/2)<< text(_label);
    show_frame(c);
}
