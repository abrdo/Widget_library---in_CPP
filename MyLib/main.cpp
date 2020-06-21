#include "checkbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "numbereditor.hpp"

#include "graphics.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;


int main()
{
    gout.open(400,400);
    vector<Widget*> widgets;
//------------------------------------------------------------------------------------
    CheckBox* cb = new CheckBox(10,10,40,40);
    widgets.push_back(cb);
    StaticText* st = new StaticText(10,60, "Naaaa mi a helyzet?? Helloka!");
    widgets.push_back(st);
    TextEditor* te = new TextEditor(10,110,100);
    widgets.push_back(te);
    NumberEditor* ne = new NumberEditor(10, 160, 60);
    widgets.push_back(ne);
//-------------------------------------------------------------------------------------
    event ev;
    gin.timer(50);
    while(gin >> ev && ev.keycode != key_escape) {

        gout<<color(0,0,0)<<move_to(0,0)<<box(400,400);
        for(auto w : widgets){
            w->handle(ev);
        }

        if(ev.type == ev_timer){
            for(auto w : widgets)
                w->show();
            gout<<refresh;
        }



    }
    return 0;
}
