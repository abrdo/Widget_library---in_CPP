#include "selectorlist_list.hpp"
#include <iostream>
#include <vector>
#include "statictext.hpp"

using namespace std;
using namespace genv;

SelectorList_list::SelectorList_list(int x, int y, int sx, int sy) : Widget(x,y,sx,sy){
    _scrollbar = new ScrollBar(_size_x, _y, 5, _size_y);
    _items = {};
    _selected_it = _items.begin();
    std::list<StaticText>::iterator a = _items.end()--;
    //_selected_it = a;
    //_selected_it--;
}

SelectorList_list::~SelectorList_list(){
    delete _scrollbar;
}

void SelectorList_list::new_item(string itemtext){
    int y = _y+5 + _items.size()*(_fonthight + 3);
    _items.push_back(StaticText(_x+5, y, itemtext));
    _selected_it = _items.end();
}

void SelectorList_list::delete_selected(){
    if(_selected_it!=_items.end()){
        for(list<StaticText>::iterator it = _selected_it; it!=_items.end(); it++){

        }
        _items.erase(_selected_it);
        _selected_it = _items.end();

    }

}






void SelectorList_list::handle(event ev){
    focus_by_click(ev);
}

void SelectorList_list::show(){
    show_frame();

    for(StaticText item: _items){
        item.show();
    }

/*
    int ys = _y+5;
    for(list<string>::iterator it = _items.begin(); it!=_items.end(); it++){
        StaticText* itemS = new StaticText(_x+5, ys, *it);
        ys += itemS->get_size_y() + 3;

        itemS->show();
        delete itemS;
        //itemsS.push_back(itemS);
    }
*/


}
