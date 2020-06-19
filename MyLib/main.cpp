#include "checkbox.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;


int main()
{
    gout.open(400,400);

    CheckBox* cb = new CheckBox(10,10,30,30);
    //cb->show();
    gout<< refresh;
    event ev;
    while(gin >> ev) {
        gout<<color(0,0,0)<<move_to(0,0)<<box(400,400);
        if(ev.keycode == 'a' ){
            cb->set_focused(true);
        }
        cb->handle(ev);
        cb->show();
        gout<<refresh;

    }
    return 0;
}
