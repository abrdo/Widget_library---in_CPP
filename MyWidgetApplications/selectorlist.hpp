#ifndef SELECTORLIST_HPP
#define SELECTORLIST_HPP

#include "widget.hpp"
#include "statictextcomp.hpp"
#include <vector>



class SelectorList : public Widget{
    std::vector<StaticTextComp*> _items;
    int _selected_index;
    int _leading;
    int _scroll_shift;


public:
    SelectorList(int x, int y, int sx, int sy);
    ~SelectorList();

    std::string get_selected(){if(_selected_index!=-1) return _items[_selected_index]->_text; else return "__ERR__";}
    int get_selected_index() { return _selected_index; }
    void set_selected_index(int index) { _selected_index = index;}

    void new_item(std::string itemtext);
    void delete_selected();
    void clear(){_items.clear();}

    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) const override;


    bool selection(){return _selected_index != -1;}
    int disp_items_size(){return _items.size()*_leading;} // items-canvas y-length
};

#endif // SELECTORLIST_HPP
