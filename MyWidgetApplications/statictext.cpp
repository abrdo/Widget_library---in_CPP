#include "statictext.hpp"
#include <iostream>
using namespace std;
using namespace genv;


StaticText::StaticText(int x, int y, string text, unsigned char r, unsigned char g, unsigned char b,
             bool show_frame, int sx, int sy, unsigned char frame_r, unsigned char frame_g, unsigned char frame_b)
             : Widget(x,y,0,0), _text(text) {
    _r=r; _g=g; _b=b;
    set_focusable(false);

    _size_x = sx-1;
    _size_y = sy-1;
    //_size_x = gout.twidth(_text)+6;
    //_size_y = _fonthight;

    // if show_frame is given:
    _show_frame = show_frame;
    _frame_r, _frame_g, _frame_b = frame_r, frame_g, frame_b;
    /*
    if(_show_frame){
        _size_x = sx-1;
        _size_y = sy-1;
    }
    */


}

void StaticText::show(genv::canvas &c){
    if(_show_frame)
        Widget::show_frame();
    if(_text!="")
        c<<move_to(_x+3, _y+_size_y/2-_fonthight/2)<<color(_r,_g,_b)<<text(_text);

}


