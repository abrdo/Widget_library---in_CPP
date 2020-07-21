#include "accountingapp.hpp"

#include <iostream>
using namespace dowi;

AccountingApp::AccountingApp(int XX, int YY) : Window(XX,YY){
    _items = {};
    _selected_index = -1;

    _nameW = new TextEditor(25,10, 200);
    _widgets.push_back(_nameW);
    _moneyW = new NumberEditor(25,50, 100);
    _widgets.push_back(_moneyW);
    _add_to_listW = new FuncButton(25+110,50, "add to list", [&](){ this->add_to_list(_nameW->get_text(), _moneyW->get_number());}, 90);
    _widgets.push_back(_add_to_listW);
    _itemsW = new SelectorList(25, 100, 325, 100);
    _widgets.push_back(_itemsW);
    _balanceW = new StaticText(25, 225, "Balance: 0");
    _widgets.push_back(_balanceW);

    _undoW = new FuncButton(25, 275, "undo", [&](){ this->undo();},70);
    _widgets.push_back(_undoW);
    _deleteW = new FuncButton(25+1*75, 275, "delete", [&](){ this->delete_selected(); },70);
    _widgets.push_back(_deleteW);
    _modifyW = new FuncButton(25+2*75, 275, "modify", [&](){this->modify_selected_to(_nameW->get_text(), _moneyW->get_number());},70);
    _widgets.push_back(_modifyW);

    _items.push_back(new item("Boldogkovaralja-Bodvaszilas", -70));
    _items.push_back(new item("magnum", -500));
    _items.push_back(new item("kaktus", -300));
    _items.push_back(new item("osztondij", 20000));
    _items.push_back(new item("Boldogkovaralja-Bodvaszilas", -70));
    _items.push_back(new item("magnum", -500));
    _items.push_back(new item("kaktus", -300));
    _items.push_back(new item("osztondij", 20000));
    _items.push_back(new item("Boldogkovaralja-Bodvaszilas", -70));
    _items.push_back(new item("magnum", -500));
    _items.push_back(new item("kaktus", -300));
    _items.push_back(new item("osztondij", 20000));
    _items.push_back(new item("Boldogkovaralja-Bodvaszilas", -70));
    _items.push_back(new item("magnum", -500));
    _items.push_back(new item("kaktus", -300));
    _items.push_back(new item("osztondij", 20000));
    _items.push_back(new item("Boldogkovaralja-Bodvaszilas", -70));
    _items.push_back(new item("magnum", -500));
    _items.push_back(new item("kaktus", -300));
    _items.push_back(new item("osztondij", 20000));

    update();
}


void AccountingApp::add_to_list(std::string pname, int pmoney){
    _items.push_back(new item(pname, pmoney));
    update();
}

void AccountingApp::undo(){
    if(!_items.empty())
        _items.pop_back();
    update();
}

void AccountingApp::delete_selected(){
    _selected_index = _itemsW->get_selected_index();
    if(_selected_index == -1)
        return;

    _items.erase(_items.begin()+_selected_index);
    //_selected_index = -1;
    if (_selected_index == _items.size()) _selected_index = _items.size()-1;

    update();
}

void AccountingApp::modify_selected_to(std::string pname, int pmoney){
    _selected_index = _itemsW->get_selected_index();
    if(_selected_index == -1)
        return;
    *_items[_selected_index] = item(pname, pmoney);
    update();
}

/////////////  UPDATE  /////////////////////
void AccountingApp::update(){
    _itemsW->clear();
    int sum = 0;
    for(item *i : _items){
        std::string t = i->name + ": " + Widget::to_str(i->money);
        _itemsW->new_item(t);
        sum += i->money;
    }
    _itemsW->set_selected_index(_selected_index);
    _balanceW->set_text("Balance: " + Widget::to_str(sum));

    refresh();

    /*
    TODO(optional):  -- tldr: if ma widget modified -> update model
     //else update_widgets() is not called when selectorlist selection modified
    for every widget for every non const function
        - at the beginning store previous state
        - at the end compare with actual state
            -> if modified
                - call *parent window's *virtual update_widgets() method
                    ->in update_widgets() we have to handle if it is called from     funcbutton or from a simple Widget
                                                                                        -if from funcbutton - bool from_funcbutton. -> write model -> widgwts
                                                                                                                                else-> write widgets -> model
                - OR call a functor.

    if(_selected_index == -1){
        _deleteW->set_focusable(false);
        _modifyW->set_focusable(false);
    }else{
        _deleteW->set_focusable(true);
        _modifyW->set_focusable(true);
    }
    */

}


AccountingApp::~AccountingApp(){
    for(item* i : _items)
        delete i;
}

