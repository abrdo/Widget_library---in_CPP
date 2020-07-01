#include "texteditor.hpp"
#include <iostream>
#include <ctime>
using namespace std;
using namespace genv;

TextEditor::TextEditor(int x, int y, int sx, int sy) : Widget(x,y,sx,sy), _text(""), _cursor_visible(true), _text_if_empty(x+3,_y+_size_y/2-_fonthight/2,"type here...", 90,90,90){}


void TextEditor::handle(event ev){
    Widget::focus_by_click(ev);
    // Typing:
    if(is_focused()){
        if(' ' <= ev.keycode && ev.keycode <= '~' && gout.twidth(_text+" |") < _size_x-6){
            _text += ev.keycode;
        } else if(ev.keycode == key_backspace && _text.size() > 0){
            _text.pop_back();
        }
        if(ev.type == ev_timer)
            if(time(0)%2==0)
                _cursor_visible = true;
            else _cursor_visible = false;
    }

}

void TextEditor::show(genv::canvas &c){
    Widget::show_frame();
    if(_text!="")
        c<<move_to(_x+3, _y+_size_y/2-_fonthight/2)<<color(255,255,255)<<text(_text);
    else c<<move_to(_x+3, _y+3)<<color(255,255,255);
    if(is_focused() && _cursor_visible)
        c<<text("|");
    if(_text == "" && is_focusable())
        _text_if_empty.show();

}
