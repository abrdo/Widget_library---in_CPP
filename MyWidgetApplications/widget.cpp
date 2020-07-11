#include "widget.hpp"
#include <iostream>
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, int fontsize, Window* win) :
        _x(x), _y(y), _size_x(sx-1), _size_y(sy-1),
        _targeted(false), _focused(false), _focusable(true),
        __fontsize(fontsize), /*default=14*/
        __fontfile("LiberationSans-Regular.ttf"),
        _frame_r(200), _frame_g(200),_frame_b(200),
        _bgcol_r(35), _bgcol_g(35), _bgcol_b(55),
        _window(win)
{
    gout.load_font(__fontfile, __fontsize); //size - hight in pixels : [14 - 15 px]
    _fonthight = genv::gout.cascent()+genv::gout.cdescent();
    /* hatter legyen az app hattere:
    if(_window){
        _bgcol_r = _window->_bgcol_r;
        _bgcol_r = _window->_bgcol_r;
        _bgcol_r = _window->_bgcol_r;
    }
    */
}


Widget::Widget(int x, int y, int sx, int sy, unsigned char bgr, unsigned char bgg, unsigned char bgb)
        : Widget(x,y,sx,sy){
    _bgcol_r = bgr;
    _bgcol_g = bgg;
    _bgcol_b = bgb;
}

bool Widget::is_focused(){return _focused;}
void Widget::set_focused(bool f) {
    if(!_focusable){
        //std::cout<<"Warning: A widget tried to be focused, although that was unfocusable."<<std::endl;
        return;
    }
    _focused = f;
}
bool Widget::is_focusable(){return _focusable;}
void Widget::set_focusable(bool f){
    if(!f && _focused) _focused = false;
    if(!f && _targeted) _targeted = false;
    _focusable = f;
}



bool Widget::mouse_above(event ev) const{
    if(ev.type != ev_mouse) return false;
    int mx = ev.pos_x;
    int my = ev.pos_y;
    return _x<=mx && mx<=(_x+_size_x) && _y<=my && my<_y+_size_y;
}

bool Widget::focusing_click(event ev) const{
    return _focusable && mouse_above(ev) && ev.button == btn_left;
}

void Widget::focus_by_click(event ev){
    if(!_focusable) return;

    if(ev.type == ev_mouse && mouse_above(ev))
        _targeted = true;
    else if(ev.type == ev_mouse && !mouse_above(ev))
        _targeted = false;
    if(ev.button == btn_left && mouse_above(ev))
        _focused = true;
    else if(ev.button == btn_left && !mouse_above(ev))
        _focused = false;

}

void Widget::show_frame(canvas &c) const{
    int x=_x, y=_y, sx=_size_x, sy=_size_y;

    if(_focused) c<<color(0 ,255, 0);
    else if(_targeted) c<<color(50 ,170, 50);
    else if(!_focusable) c<<color(130,130,130);
    else gout<<color(_frame_r, _frame_g, _frame_b);
    c<<move_to(x,y)<<line(sx,0)<<line(0,sy)<<line(-sx,0)<<line(0,-sy);

    //if(_targeted && !is_focused()) c<<color(_frame_r, _frame_g, _frame_b);
    c<<move_to(x+1,y+1)<<line(sx-2,0)<<line(0,sy-2)<<line(-sx+2,0)<<line(0,-sy+2);
}
