#include "application.hpp"
#include <iostream>
using namespace std;
using namespace genv;


Application::Application(int XX, int YY) : _XX(XX), _YY(YY){
    _focused = -1;
    gout.open(XX, YY);
}

Application::~Application(){
    for(auto w : _widgets)
        delete w;
}

void Application::new_widget(Widget* w){
    _widgets.push_back(w);
}

void Application::event_loop(int timer){
    gin.timer(timer);
    event ev;
    while(gin >> ev && ev.keycode != key_escape){
        if(ev.keycode == key_tab && _widgets.size()!=0){
            int prev_focused;
            /*if (_focused != -1){
                _widgets[_focused]->set_focused(false);
                prev_focused = _focused;
            }*/
            //else {
                for(int i = 0; i<_widgets.size(); i++){
                    if(_widgets[i]->is_focused()){
                        _widgets[i]->set_focused(false);
                        prev_focused = i;
                        break;
                    }
                    if(i == _widgets.size()-1){
                        prev_focused = _widgets.size()-1;
                    }
                }
                _focused = prev_focused;
                cout<<"prev focused: "<<prev_focused<<endl;;
            //}
            int i = 0;
            while(1){
                //cout<<i;
                if(_focused < _widgets.size()-1)
                    _focused++;
                else _focused = 0;
                if(_widgets[_focused]->is_focusable()) break;
                if(_focused == prev_focused){
                    _focused = -1;
                    break;
                }
                i++;
            }
            if (_focused != -1) _widgets[_focused]->set_focused(true);
        }

        for(auto w : _widgets){
            w->handle(ev);
        }
        if(ev.type == ev_timer){
            gout<<color(0,0,0)<<move_to(0,0)<<box(_XX,_YY);
            for(auto w : _widgets)
                w->show();
            gout<<refresh;
        }

    }
}
