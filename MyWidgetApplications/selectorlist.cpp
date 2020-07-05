#include "selectorlist.hpp"
#include <iostream>
#include <vector>
#include "statictext.hpp"

using namespace std;
using namespace genv;

SelectorList::SelectorList(int x, int y, int sx, int sy) : Widget(x,y,sx,sy){
    _items = {};
    _selected_index = -1;
    _leading = _fonthight+2;
    _scroll_shift = 0;
}

SelectorList::~SelectorList(){
    for(auto item : _items)
        delete item;
}

void SelectorList::new_item(string itemtext){
    int y = 5 + _items.size()*_leading;
    _items.push_back(new StaticTextComp(5, y, itemtext, 200,200,200));
}

void SelectorList::delete_selected(){
    if(_selected_index != -1){
        // modification of _y coordinates:
        for(int i = _items.size()-1; _selected_index < i; i--){
            _items[i]->set_y(_items[i-1]->get_y());
        }
        // deletion:
        delete _items[_selected_index];
        _items[_selected_index] = 0;
        for(int i = _selected_index; i<_items.size()-1; i++){
            _items[i]= _items[i+1];
        }
        _items.resize(_items.size()-1);
        _selected_index = -1;
    }
    else cerr<<"warning: Can't delete, because there is no selection from the SelectorList."<<endl;

}

void SelectorList::handle(event ev){
    focus_by_click(ev);

    if(_focused){
        if(ev.keycode == key_delete){
            if(_selected_index != -1) delete_selected();
        }
    }

    if(focusing_click(ev)){
        if(ev.pos_x<_x+_size_x-22){
            int new_sel_ind = (ev.pos_y + _scroll_shift -_y-5)/_leading;
            if(new_sel_ind < _items.size()) _selected_index = new_sel_ind;
        }else if(ev.pos_y < _y+22){
            _scroll_shift-=20;
        }else if(ev.pos_y > _y+_size_y-22){
            _scroll_shift+=20;
        }
    }
    if(_targeted){
        if(ev.button == btn_wheelup)
            _scroll_shift-=4;
        if(ev.button == btn_wheeldown)
            _scroll_shift+=4;
    }
    if(_focused && ev.keycode== key_up)
        _selected_index--;
    if(_focused && ev.keycode== key_down)
        _selected_index++;

    // _scroll_shift, _selected_index adjust, if it became invalid:
    if(_items.size()*_leading+10 < _size_y) // the length of the displayed list is shorter then the _size_y
        _scroll_shift = 0;
    else if(_scroll_shift < 0)
        _scroll_shift = 0;
    else if(_scroll_shift > _items.size()*_leading+10 - _size_y)
        _scroll_shift = _items.size()*_leading+10 - _size_y;
    if(_selected_index < -1)
        _selected_index = 0;
    else if(_selected_index > _items.size()-1)
        _selected_index = _items.size()-1;

}



void SelectorList::show(genv::canvas &c) const{
    c<<move_to(_x,_y)<<color(_bgcol_r, _bgcol_g, _bgcol_b)<<box(_size_x, _size_y);
    canvas canv;
    canv.open(_size_x+1, 5+_items.size()*_leading+1);
    canv.load_font(__fontfile, __fontsize);
    canv.transparent(true);

    // SELECT:
    if(_selected_index != -1){
        canv<<color(255,255,0)
            <<move_to(4, 5 + _selected_index*(_leading))<<box(_size_x-8, _leading);
    }
    // LIST:
    if(_selected_index != -1) _items[_selected_index]->set_rgb(70,70,70);
    for(auto item : _items){
        item->show(canv);
    }
    if(_selected_index != -1) _items[_selected_index]->set_rgb(200,200,200);

    c<<stamp(canv, 0, 0+_scroll_shift, _size_x, _size_y, _x, _y);

    // ScrollBar
    c<<color(150,150,150);
    c<<move_to(_x+_size_x-2, _y+2)<<box(-20, (_size_y-4));
    c<<color(100,100,100);
    c<<move_to(_x+_size_x-2, _y+2)<<box(-20,20);
    c<<move_to(_x+_size_x-2, _y+_size_y-2)<<box(-20,-20);

    // Frame
    show_frame();
}
