#include "statictext.hpp"
#include <iostream>
using namespace std;
using namespace genv;

StaticText::StaticText(int x, int y, string text, unsigned char r, unsigned char g, unsigned char b) : Widget(x,y,0,0), _text(text){
    _r=r; _g=g; _b=b;
    set_focusable(false);
    _size_x = gout.twidth(_text);
    _size_y = gout.cascent() + gout.cdescent();
    cout<<_y<<endl;
    cout<<"font y size: "<<_size_y<<endl;
}

void StaticText::show(genv::canvas &c){
    c<<move_to(_x,_y)<<color(_r,_g,_b)<<text(_text);

}


