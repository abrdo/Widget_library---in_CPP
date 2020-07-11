#include "window.hpp"
#include <iostream>
using namespace std;
using namespace genv;


Window::Window(int XX, int YY) : _XX(XX), _YY(YY), _focused(-1), _exit(false),
                            _bgcol_r(15), _bgcol_g(15), _bgcol_b(40){}

Window::~Window(){
    for(auto w : _widgets)
        delete w;
}

void Window::iterate_focused_by_tab(event ev){
    if(ev.keycode == key_tab && _widgets.size()!=0){
        int prev_focused;
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
        while(1){
            if(_focused < _widgets.size()-1)
                _focused++;
            else _focused = 0;
            if(_widgets[_focused]->is_focusable()) break;
            if(_focused == prev_focused){
                _focused = -1;
                break;
            }
        }
        if (_focused != -1) _widgets[_focused]->set_focused(true);
    }
}

void Window::handle__iterate_focused_by_tab__show(genv::event ev){
    for(auto w : _widgets){
        w->handle(ev);
    }

    iterate_focused_by_tab(ev);

    if(ev.type == ev_timer){
        gout<<color(_bgcol_r, _bgcol_g, _bgcol_b)<<move_to(0,0)<<box(_XX,_YY);
        for(auto w : _widgets)
            w->show();
        gout<<refresh;
    }
};



void Window::run(int timer){
    gout.open(_XX, _YY);
    gin.timer(timer);
    event ev;
    while(gin >> ev && !_exit){
        handle__iterate_focused_by_tab__show(ev);
        if(ev.keycode == key_escape)
            _exit = true;
    }
    _exit = false;
}
