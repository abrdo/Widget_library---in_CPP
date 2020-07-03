#include "button.hpp"
#include "graphics.hpp"
using namespace std;
using namespace genv;


Button::Button(int x, int y, std::string label, int sx, int sy) : Widget(x,y,sx,sy), _label(label){}

void Button::handle(event ev){
    focus_by_click(ev);
    if(focusing_click(ev)){
        action();
    }
}

void Button::show(canvas &c){
    show_frame(c);
    c<<color(255,255,255);
    c << move_to(_x+_size_x/2-gout.twidth(_label)/2, _y+_size_y/2-_fonthight/2)<<text(_label);
}

void Button::action(){} //virtual
