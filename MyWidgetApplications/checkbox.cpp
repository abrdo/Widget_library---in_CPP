#include "checkbox.hpp"
#include <iostream>
using namespace std;
using namespace genv;

CheckBox::CheckBox(int x, int y, int sx, int sy) : Widget(x, y, sx, sy), _checked(false){}

void CheckBox::set_checked(bool ch) {_checked = ch;}

void CheckBox::toggle(){
    _checked = !_checked;
}


void CheckBox::handle(event ev){
    Widget::focus_by_click(ev);
    //checked:
    if(Widget::focusing_click(ev)
       || (is_focused() && (ev.keycode == key_enter || ev.keycode == ' '))
       )

        CheckBox::toggle();
}


void CheckBox::show(genv::canvas &c){
    Widget::show_frame();
    if(_checked){
        if(!is_focusable()) c<<color(130,130,130);
        else c<<color(255,255,255);
        c<<move_to(_x+4, _y+5)<<line(_size_x-9, _size_y-9);
        c<<move_to(_x+5, _y+5)<<line(_size_x-9, _size_y-9);
        c<<move_to(_x+6, _y+5)<<line(_size_x-9, _size_y-9);
        c<<move_to(_x+_size_x-4, _y+5)<<line(-_size_x+9, _size_y-9);
        c<<move_to(_x+_size_x-5, _y+5)<<line(-_size_x+9, _size_y-9);
        c<<move_to(_x+_size_x-6, _y+5)<<line(-_size_x+9, _size_y-9);
    }
}
