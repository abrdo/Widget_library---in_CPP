#include "widget.hpp"
#include <iostream>
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy), _focused(false), _focusable(true){
    gout.load_font("LiberationSans-Regular.ttf", 14); //size - hight in pixels : [14 - 15 px]
    _fonthight = genv::gout.cascent()+genv::gout.cdescent();
}

void Widget::set_focused(bool f) {
    if(!_focusable){
        std::cout<<"Warning: A widget tried to be focused, although that was unfocusable."<<std::endl;
        return;
    }
    _focused = f;
}
bool Widget::is_focused(){return _focused;}
void Widget::set_focusable(bool f){_focusable = f;}
bool Widget::is_focusable(){return _focusable;}




bool Widget::mouse_above(int mx, int my){
    return _x<=mx && mx<=(_x+_size_x) && _y<=my && my<_y+_size_y;
}

void Widget::handle(event ev){}

void Widget::focus_by_click(event ev){
    if(ev.button == btn_left && mouse_above(ev.pos_x, ev.pos_y)){
        set_focused(true);
    }
    if(ev.button == btn_left && !mouse_above(ev.pos_x, ev.pos_y)){
        set_focused(false);
    }
}

void Widget::show_frame(){
    if(is_focused()) gout<<color(0 ,255, 0);
    else if(!is_focusable()) gout<<color(130,130,130);
    else gout<<color(255,255,255);
    gout<<move_to(_x,_y)<<box(_size_x, _size_y);

    //if(!is_focusable()) gout<<color(130,130,130);
    //else gout<<color(255,255,255);
    //gout<<move_to(_x+1, _y+1)<<box(_size_x-2, _size_y-2);

    gout<<move_to(_x+2, _y+2)<<color(0,0,0)<<box(_size_x-4, _size_y-4);
}
