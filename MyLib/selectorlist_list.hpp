#ifndef SELECTORLIST_LIST_HPP
#define SELECTORLIST_LIST_HPP

#include "widget.hpp"
#include "statictext.hpp"
#include "scrollbar.hpp"
#include <list>



class SelectorList_list : public Widget{
    std::list<StaticText> _items;
    std::list<StaticText>::iterator _selected_it;
    ScrollBar* _scrollbar;


public:
    SelectorList_list(int x, int y, int sx, int sy);
    ~SelectorList_list();

    void new_item(std::string itemtext);
    void delete_selected();

    void handle(genv::event ev) override;
    void show() override;

    //DEBUG:
    std::string get_selected_text(){
        if(_selected_it == _items.end()) return "Helllo";
        return _selected_it->_text;
    }
};

#endif // SELECTORLIST_LIST_HPP
