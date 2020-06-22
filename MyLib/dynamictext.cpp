#include "dynamictext.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace std;
using namespace genv;

DynamicText::DynamicText(int x, int y, int sx, int sy) : Widget(x,y,sx,sy), _text("Ide ird a szoveget."){}


void DynamicText::handle(event ev){
    Widget::focus_by_click(ev);
    ///TODO:Typing
    if(is_focused()){
        if(' ' <= ev.keycode && ev.keycode <= '~' && gout.twidth(_text) < _size_x-gout.twidth(" ")){
            _text += ev.keycode;
        } else if(ev.keycode == key_backspace && _text.size() > 10){
            _text.pop_back();
        }
    }

}
/*
        if(ev.keycode >= ' ' && ev.keycode <= '~' && gout.twidth(szov) < sx-gout.twidth(" ")){ //8 egy space mérete pixelben
            szov += ev.keycode;
        }else if(ev.keycode == key_backspace && szov.size() > 0){
            szov.pop_back();
        }
*/

void DynamicText::show(){
    Widget::show_frame();
    gout<<move_to(_x + 10, _y +30)<<color(255,255,255)<<text(_text);

}
