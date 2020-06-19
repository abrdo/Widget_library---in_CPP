#include "checkbox.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace std;
using namespace genv;

CheckBox::CheckBox(int x, int y, int sx, int sy) : Widget(x, y, sx, sy), _checked(false){}

void CheckBox::set_checked(bool ch) {_checked = ch;}

void CheckBox::toggle(){
    _checked = !_checked;
}



void CheckBox::handle(event ev){
    if(ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y)){
        _focused = true;
    }
    if(ev.button == btn_left && !is_selected(ev.pos_x, ev.pos_y)){
        _focused = false;
    }
    //checked:
    if(_focused && (ev.button == -btn_left || ev.keycode == key_enter || ev.keycode == ' '))
        CheckBox::toggle();
}

void CheckBox::show(){
    if(_focused) gout<<color(0 ,255, 0);
    else gout<<color(255,255,255);
    gout<<move_to(_x,_y)<<box(_size_x, _size_y);
    gout<<move_to(_x+2, _y+2)<<color(255,255,255)<<box(_size_x-4, _size_y-4);
    gout<<move_to(_x+4, _y+4)<<color(0,0,0)<<box(_size_x-8, _size_y-8);
    if(_checked){
        gout<<color(255,255,255);
        gout<<move_to(_x+6, _y+6)<<line(_size_x-12, _size_y-12);
        gout<<move_to(_x+5, _y+6)<<line(_size_x-13, _size_y-12);
        gout<<move_to(_x+7, _y+6)<<line(_size_x-11, _size_y-12);
        gout<<move_to(_x+_size_x-6, _y+6)<<line(-_size_x+12, _size_y-12);
        gout<<move_to(_x+_size_x-7, _y+6)<<line(-_size_x+11, _size_y-12);
        gout<<move_to(_x+_size_x-5, _y+6)<<line(-_size_x+13, _size_y-12);
    }
}


