#include "numbereditor.hpp"
#include <iostream>
#include <ctime>
using namespace std;
using namespace genv;

NumberEditor::NumberEditor(int x, int y, bool p_isbounded, int lb, int ub, bool set2bound)
                : Widget(x,y,0,25), _is_bounded(p_isbounded), _lbound(lb), _ubound(ub), _snum("0"), _set_to_bound(set2bound){
    if(_ubound < _lbound){
        cerr<<"ERROR: The lower bound must be smaller than the upper bound by the bounded NumberEditor."<<endl;
        //exit(1);
    }
    _size_x = gout.twidth(to_str(max(_lbound, _ubound))+"|")+25; // 25 = 18 + ...
}

NumberEditor::NumberEditor(int x, int y, int sx, int sy, bool p_isbounded, int lb, int ub, bool set2bound, int fontsize, int bgr, int bgg, int bgb)
                : NumberEditor(x, y, p_isbounded, lb, ub, set2bound){
    _size_x = sx;
    _size_y = sy;
    __fontsize = fontsize;
    if(bgb != -1){
        _bgcol_r = bgr;
        _bgcol_g = bgg;
        _bgcol_b = bgb;
    }
}


bool NumberEditor::is_in_range(int i){
    return _lbound < i && i < _ubound;
}

void NumberEditor::handle(event ev){
    if(!_focusable) return;
    string prev_snum = _snum;
    Widget::focus_by_click(ev);
    if(!_focused){
        if(_snum == "-") _snum = "";
        //if(_ubound < to_int(_snum)) _snum = to_str(_ubound);
        //if(_lbound > to_int(_snum)) _snum = to_str(_lbound);
    }
    // Typing:
    if(_focused){
        if('0' <= ev.keycode && ev.keycode <= '9' && gout.twidth(_snum+" |")+14 < _size_x-6){
            if(_snum == "0") _snum = "";
            _snum += ev.keycode;
        }
        if(_snum == "" && ev.keycode == '-')  // negative numbers
            _snum += ev.keycode;
        if(ev.keycode == key_backspace && _snum.size() > 0){
            _snum.pop_back();
        }
        if(ev.type == ev_timer)
            if(time(0)%2==0)
                _cursor_visible = true;
            else _cursor_visible = false;
    }
    if(!is_empty()){
        //========================================= Increase / Decrease BEGIN ========================================================
        if(_focused){
            if(ev.keycode == key_up){
                _snum = to_str(to_int(_snum)+1);
            }
            if(ev.keycode == key_down){
                _snum = to_str(to_int(_snum)-1);
            }
            if(ev.keycode == key_pgup){
                _snum = to_str(to_int(_snum)+10);
            }
            if(ev.keycode == key_pgdn){
                _snum = to_str(to_int(_snum)-10);
            }
        }
        int tx = _x+_size_x, ty = _y+_size_y;
        if(ev.button == btn_left && is_inside(ev.pos_x, ev.pos_y, tx-13, tx-2, _y+2, _y+_size_y/2)){
            _snum = to_str(to_int(_snum)+1);
        }
        if(ev.button == btn_left && is_inside(ev.pos_x, ev.pos_y, tx-13, tx-2, ty-_size_y/2, ty-2)){
            _snum = to_str(to_int(_snum)-1);
        }

        //======================================= Increase / Decrease END ======================================================
        // Overflow handle: -----------------------------------------------------------------
        if(_snum!="" && _snum!="-"){
            if(_set_to_bound){
                if(_ubound < to_int(_snum)) _snum = to_str(_ubound);
                if(_lbound > to_int(_snum)) _snum = to_str(_lbound);
            }else{
                if(_ubound < to_int(_snum)) _snum = prev_snum;
                if(_lbound > to_int(_snum)) _snum = prev_snum;
            }
        }
    }
}

void NumberEditor::show(genv::canvas &c) const{
    c<<move_to(_x,_y)<<color(_bgcol_r, _bgcol_g, _bgcol_b)<<box(_size_x, _size_y);
    Widget::show_frame();
    // buttons show
    int tx = _x+ _size_x, ty = _y+ _size_y;
    c<<color(255,255,255)<<move_to(tx-15, _y+2)<<box(13, _size_y - 4); //buttons white background - grid
    c<<color(100,100,100);
    c<<move_to(tx-14, _y+2)<<box(12,(_size_y+1)/2-3); //buttons
    c<<move_to(tx-14, ty-3)<<box(12,-((_size_y+1)/2-3));
    c<<color(255,255,255);
    c<<move_to(tx-8,_y+5)<<line(3,4); //top triangle
    c<<move_to(tx-8,_y+5)<<line(-3,4);
    c<<move_to(tx-11,_y+9)<<line(7,0);
    c<<move_to(tx-8,ty-5)<<line(3,-4); //down triangle
    c<<move_to(tx-8,ty-5)<<line(-3,-4);
    c<<move_to(tx-11,ty-9)<<line(7,0);

    // number show
    canvas c2;
    c2.load_font(__fontfile, __fontsize);
    c2.open(c2.twidth(_snum+"|"), c2.cascent() + c2.cdescent());
    c2.transparent(true);
    if(_snum!="")
        c2<<move_to(0,0)<<color(255,255,255)<<text(_snum); //text
    else c2<<move_to(0, 0)<<color(255,255,255);
    if(_focused && _cursor_visible)
        c2<<text("|");
    gout<<stamp(c2, _x+__fontsize/2, _y+_size_y/2-(c2.cascent() + c2.cdescent())/2);
    /*
    if(_snum!="")
        c<<move_to(_x+3, _y+3)<<color(255,255,255)<<text(_snum); //text
    else c<<move_to(_x+3, _y+3)<<color(255,255,255);
    if(is_focused() && _cursor_visible)
        c<<text("|");
    */
}
