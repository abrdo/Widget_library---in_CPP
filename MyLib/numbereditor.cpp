#include "numbereditor.hpp"
#include "graphics.hpp"
#include <iostream>
#include <ctime>
using namespace std;
using namespace genv;

NumberEditor::NumberEditor(int x, int y, int sx, int sy) : Widget(x,y,sx,sy), _snum("0"){}


void NumberEditor::handle(event ev){
    Widget::focus_by_click(ev);
    // Typing:
    if(is_focused()){
        if('0' <= ev.keycode && ev.keycode <= '9' && gout.twidth(_snum+" |")+14 < _size_x-6){
            if(_snum == "0") _snum = "";
            _snum += ev.keycode;
        }
        if(_snum == "" && ev.keycode == '-')  // negative numbers
            _snum += ev.keycode;
        if(ev.keycode == key_backspace && _snum.size() > 0){
            _snum.pop_back();
        }
        if(ev.type == ev_timer)
            if(time(0)%2==0)
                _cursor_visible = true;
            else _cursor_visible = false;

        if(ev.keycode == key_up){
            int num = to_int(_snum);
            num++;
            if(num*to_int(_snum)>=0) // avoiding overflow
                _snum = to_str(num);
        }
        if(ev.keycode == key_down){
            int num = to_int(_snum);
            num--;
            if(num*to_int(_snum)>=0) // avoiding underflow
                _snum = to_str(num);
        }
        if(ev.keycode == key_pgup){
            int num = to_int(_snum);
            num+=10;
            if(num*to_int(_snum)>=0) // avoiding overflow
                _snum = to_str(num);
        }
        if(ev.keycode == key_pgdn){
            int num = to_int(_snum);
            num-=10;
            if(num*to_int(_snum)>=0) // avoiding underflow
                _snum = to_str(num);
        }
    }
    int tx = _x+_size_x, ty = _y+_size_y;
    if(ev.button == btn_left && is_inside(ev.pos_x, ev.pos_y, tx-14, tx-2, _y+2, _y+14)){
        int num = to_int(_snum);
        num++;
        if(num*to_int(_snum)>=0) // avoiding overflow
            _snum = to_str(num);
    }
    if(ev.button == btn_left && is_inside(ev.pos_x, ev.pos_y, tx-14, tx-2, ty-14, ty-2)){
        int num = to_int(_snum);
        num--;
        if(num*to_int(_snum)>=0) // avoiding underflow
            _snum = to_str(num);
    }
}

void NumberEditor::show(){
    Widget::show_frame();
    // buttons show
    int tx = _x+ _size_x, ty = _y+ _size_y;
    gout<<color(255,255,255)<<move_to(tx-16, _y+2)<<box(14,26);
    gout<<color(100,100,100);
    gout<<move_to(tx-14, _y+2)<<box(12,12);
    gout<<move_to(tx-14, ty-14)<<box(12,12);
    gout<<color(255,255,255);
    gout<<move_to(tx-8,_y+5)<<line(3,6); //top triangle
    gout<<move_to(tx-8,_y+5)<<line(-3,6);
    gout<<move_to(tx-11,_y+11)<<line(7,0);
    gout<<move_to(tx-8,ty-5)<<line(3,-6); //down triangle
    gout<<move_to(tx-8,ty-5)<<line(-3,-6);
    gout<<move_to(tx-11,ty-11)<<line(7,0);

    // number show
    if(_snum!="")
        gout<<move_to(_x+3, _y+3)<<color(255,255,255)<<text(_snum);
    else gout<<move_to(_x+3, _y+3)<<color(255,255,255);
    if(is_focused() && _cursor_visible)
        gout<<text("|");
}
