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

class CraftApp : public dowi::Window
{
    dowi::StaticText* raktar_text;
    dowi::StaticText* kraftolhato_text;
    dowi::StaticText* ujtargy_text;

    dowi::SelectorList* raktarL;
    dowi::SelectorList* kraftolhatoL;
    dowi::SelectorList* kellenekL;

    dowi::TextEditor* ujtargyE;

    dowi::FuncButton* kraftolB;
    dowi::FuncButton* kellB;
    dowi::FuncButton* keszB;
    //--------------------------------------------
    std::map<Epitoanyag, int> raktar;

public:
    CraftApp(int XX = 550, int YY = 400);
};

#endif // CRAFTAPP_HPP
