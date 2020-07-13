#include "craftapp.hpp"

#include <iostream>
using namespace genv;
using namespace std;
using namespace dowi;

CraftApp::CraftApp(int XX, int YY) : Window(XX,YY){
        raktar_text = new StaticText(10, 25,"Raktar:");
        _widgets.push_back(raktar_text);
        raktarL = new SelectorList(10, 50, 100, 100);
        _widgets.push_back(raktarL);
        kraftolhato_text = new StaticText(10, 175, "Kraftolato:");
        _widgets.push_back(kraftolhato_text);
        kraftolhatoL = new SelectorList(10, 200, 100, 100);
        _widgets.push_back(kraftolhatoL);
        kraftolB = new FuncButton(10,310, "Kraftol", [](){});
        _widgets.push_back(kraftolB);

        ujtargy_text = new StaticText(150,25, "Uj_targy:");
        _widgets.push_back(ujtargy_text);
        ujtargyE = new TextEditor(150,50);
        _widgets.push_back(ujtargyE);
        kellenekL = new SelectorList(150,100, 100, 100);
        _widgets.push_back(kellenekL);
        kellB = new FuncButton(150,215, "Kell bele", [](){});
        _widgets.push_back(kellB);
        keszB = new FuncButton(150,250, "Kesz a targy", [](){});
        _widgets.push_back(keszB);
        //---------------------------------------------------------------
        // Data

        raktar[Epitoanyag("fa", {})] = 100;
        raktar[Epitoanyag("ko", {})] = 100;
        raktar[Epitoanyag("szog", {})] = 100;
        raktar[Epitoanyag("agyag", {})] = 100;


        // Widget upload with data
        for(auto tetel : raktar){
            string tetel_szov = (tetel.first).nev + ": " + Widget::to_str(tetel.second);
            raktarL->new_item(tetel_szov);
        }

}
