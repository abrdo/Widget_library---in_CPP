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
    std::string get_selected(){if(_selected_index!=-1) return _items[_selected_index]->_text; else return "ERR";}

    void new_item(std::string itemtext);
    void delete_selected();

    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) override;


    bool selection(){return _selected_index != -1;}
    int disp_items_size(){return _items.size()*_leading;};
};

#endif // SELECTORLIST_HPP
