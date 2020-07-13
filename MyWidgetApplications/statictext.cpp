#include "statictext.hpp"
using namespace std;
using namespace genv;
using namespace dowi;


StaticText::StaticText(int x, int y, string text, unsigned char r, unsigned char g, unsigned char b,
             bool show_frame, int sx, int sy, int fontsize,
             unsigned char frame_r, unsigned char frame_g, unsigned char frame_b)
             : Widget(x,y,0,0, fontsize), _text(text) {
    _r=r; _g=g; _b=b;
    _focusable = false;

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

void StaticText::show(genv::canvas &c) const{
    if(_show_frame)
        Widget::show_frame();

    canvas c2;
    c2.load_font(__fontfile, __fontsize);
    c2.open(c2.twidth(_text), c2.cascent() + c2.cdescent());
    c2.transparent(true);

    if(_text!="")
        c2<<move_to(0,0)<<color(_r,_g,_b)<<text(_text);

    gout<<stamp(c2, _x+3, _y+_size_y/2-(c2.cascent() + c2.cdescent())/2);

    /*
    if(_text!="")
        c<<move_to(_x+3, _y+_size_y/2-_fonthight/2)<<color(_r,_g,_b)<<text(_text);
    */
}


