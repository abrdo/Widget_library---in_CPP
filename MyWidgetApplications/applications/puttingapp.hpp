#ifndef PUTTINGAPP_HPP
#define PUTTINGAPP_HPP

#include "../window.hpp"
#include "../selectorlist.hpp"
#include "../funcbutton.hpp"


class PuttingApp : public dowi::Window{
    dowi::SelectorList* _list1;
    dowi::SelectorList* _list2;
    dowi::FuncButton* _1to2;
    dowi::FuncButton* _2to1;
public:
    PuttingApp(int XX = 300, int YY=300);

    void put_selected_from_to(dowi::SelectorList* list_from, dowi::SelectorList* list_to);
};

#endif // PUTTINGAPP_HPP
