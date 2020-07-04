#include "widget.hpp"
#include <iostream>
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, int fontsize)
        : _x(x), _y(y), _size_x(sx-1), _size_y(sy-1), __fontsize(fontsize), _targeted(false), _focused(false), _focusable(true){
    __fontfile = "LiberationSans-Regular.ttf";
    // __fontsize = 14; - default
    _fonthight = genv::gout.cascent()+genv::gout.cdescent();
    gout.load_font(__fontfile, __fontsize); //size - hight in pixels : [14 - 15 px]
    _frame_r = _frame_g = _frame_b = 255;
}

void Widget::set_focused(bool f) {
    if(!_focusable){
        //std::cout<<"Warning: A widget tried to be focused, although that was unfocusable."<<std::endl;
        return;
    }
    _focused = f;
}
bool Widget::is_focused(){return _focused;}
void Widget::set_focusable(bool f){
    if(!f && _focused) _focused = false;
    if(!f && _targeted) _targeted = false;
    _focusable = f;
}
bool Widget::is_focusable(){return _focusable;}



bool Widget::mouse_above(event ev){
    if(ev.type != ev_mouse) return false;
    int mx = ev.pos_x;
    int my = ev.pos_y;
    return _x<=mx && mx<=(_x+_size_x) && _y<=my && my<_y+_size_y;
}

bool Widget::focusing_click(event ev){
    return is_focusable() && mouse_above(ev) && ev.button == btn_left;
}

void Widget::focus_by_click(event ev){
    if(!is_focusable()) return;

    if(ev.type == ev_mouse && mouse_above(ev))
        _targeted = true;
    else if(ev.type == ev_mouse && !mouse_above(ev))
        _targeted = false;
    if(ev.button == btn_left && mouse_above(ev))
        set_focused(true);
    else if(ev.button == btn_left && !mouse_above(ev))
        set_focused(false);

}

void Widget::show_frame(canvas &c){
    int x=_x, y=_y, sx=_size_x, sy=_size_y;

    if( is_focused()) c<<color(0 ,255, 0);
    else if(_targeted) c<<color(50 ,170, 50);
    else if(!is_focusable()) c<<color(130,130,130);
    else gout<<color(_frame_r, _frame_g, _frame_b);
    c<<move_to(x,y)<<line(sx,0)<<line(0,sy)<<line(-sx,0)<<line(0,-sy);

    //if(_targeted && !is_focused()) c<<color(_frame_r, _frame_g, _frame_b);
    c<<move_to(x+1,y+1)<<line(sx-2,0)<<line(0,sy-2)<<line(-sx+2,0)<<line(0,-sy+2);
}
