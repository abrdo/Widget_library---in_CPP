#ifndef ACCOUNTINGAPP_HPP
#define ACCOUNTINGAPP_HPP

#include "../window.hpp"
#include "../texteditor.hpp"
#include "../numbereditor.hpp"
#include "../statictext.hpp"
#include "../selectorlist.hpp"
#include "../funcbutton.hpp"

#include <vector>

struct item{
    std::string name;
    int money;

    item(std::string n, int m) : name(n), money(m) {}
};



class AccountingApp : public Window{

    std::vector<item*> _items;
    int _selected_index;

    TextEditor* _nameW;
    NumberEditor* _moneyW;
    FuncButton* _add_to_listW;
    SelectorList* _itemsW;
    StaticText* _balanceW;
    FuncButton* _undoW;
    FuncButton* _deleteW;
    FuncButton* _modifyW;

public:
    AccountingApp(int XX = 400, int YY = 400);
    ~AccountingApp();

    void add_to_list(std::string name, int money);
    void undo();
    void delete_selected();
    void modify_selected_to(std::string name, int money);

    void update_widgets();
};

#endif // ACCOUNTINGAPP_HPP
