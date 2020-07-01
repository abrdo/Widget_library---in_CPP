#include "applications/basicbuttonapp.hpp"
#include "applications/widgettesterapp.hpp"

using namespace std;
using namespace genv;


int main(){
    WidgetTesterApp myapp;
    myapp.run();

    gout.open(400,400);

    vector<Widget*>widgets;
    Button *b1 = new Button(10,10, "Button");
    widgets.push_back(b1);
    CheckBox *cb1 = new CheckBox(10,40);
    widgets.push_back(cb1);
    for(Widget* w : widgets){
        w->show();
    }
    gout<<refresh;

    gin.timer(40);
    event ev;
    while(gin>>ev){

        for(Widget* w : widgets){
            w->handle(ev);
        }

        if(ev.type == ev_timer){
            gout<<color(0,0,0)<<move_to(0,0)<<box(400,400);
            for(Widget* w : widgets){
                w->show();
            }
            gout<<refresh;
        }
    }

    return 0;
}
