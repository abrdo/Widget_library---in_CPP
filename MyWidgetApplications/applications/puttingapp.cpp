#include "puttingapp.hpp"

using namespace dowi;

PuttingApp::PuttingApp(int XX, int YY): Window(XX,YY){
    _list1 = new SelectorList(10, 10, 100, 100);
    _widgets.push_back(_list1);
    _list2 = new SelectorList(180, 10, 100, 100);
    _widgets.push_back(_list2);
    _1to2 = new FuncButton(120, 50, "->", [=](){put_selected_from_to(_list1, _list2);}, 20,20);
    _widgets.push_back(_1to2);
    _2to1 = new FuncButton(150, 50, "<-", [=](){put_selected_from_to(_list2, _list1);}, 20,20);
    _widgets.push_back(_2to1);

    _list1->new_item("alma");
    _list1->new_item("korte");
    _list1->new_item("cseresznye");
    _list2->new_item("1");
    _list2->new_item("2");
    _list2->new_item("3");
}

void PuttingApp::put_selected_from_to(SelectorList* list_from, SelectorList* list_to){
    if(!list_from->selection()) return;
    list_to->new_item(list_from->get_selected());
    list_from->delete_selected();
}

