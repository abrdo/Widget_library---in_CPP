#include "statictextcomp.hpp"
#include <iostream>
using namespace std;
using namespace genv;
using namespace dowi;

StaticTextComp::StaticTextComp(int x, int y, string text, unsigned char r, unsigned char g, unsigned char b) : Widget(x,y,0,0), _text(text){
    _r=r; _g=g; _b=b;
    _focusable = false;
    _size_x = gout.twidth(_text);
    _size_y = gout.cascent() + gout.cdescent();
}

void StaticTextComp::show(genv::canvas &c) const{
    c<<move_to(_x,_y)<<color(_r,_g,_b)<<text(_text);

}




