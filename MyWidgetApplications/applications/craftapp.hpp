#ifndef CRAFTAPP_HPP
#define CRAFTAPP_HPP

#include "../window.hpp"

#include "../numbereditor.hpp"
#include "../texteditor.hpp"
#include "../statictext.hpp"
#include "../checkbox.hpp"
#include "../selectorlist.hpp"
#include "../funcbutton.hpp"

#include <map>


struct Epitoanyag{
    std::string nev;
    std::map<std::string,int> cost;

    Epitoanyag(std::string n, std::map<std::string,int> c): nev(n), cost(c){}

    friend bool operator<(const Epitoanyag &a, const Epitoanyag &b){ return a.nev < b.nev; }
};

class CraftApp : public Window
{
    StaticText* raktar_text;
    StaticText* kraftolhato_text;
    StaticText* ujtargy_text;

    SelectorList* raktarL;
    SelectorList* kraftolhatoL;
    SelectorList* kellenekL;

    TextEditor* ujtargyE;

    FuncButton* kraftolB;
    FuncButton* kellB;
    FuncButton* keszB;
    //--------------------------------------------
    std::map<Epitoanyag, int> raktar;

public:
    CraftApp(int XX = 550, int YY = 400);
};

#endif // CRAFTAPP_HPP
