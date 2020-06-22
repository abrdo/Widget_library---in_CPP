#include "application.hpp"
#include "numbereditor.hpp"
#include "texteditor.hpp"
#include "statictext.hpp"
#include "checkbox.hpp"
#include "selectorlist.hpp"

#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <list>
using namespace genv;
using namespace std;


class MyApplication : public Application{
    SelectorList* _sl;
public:
    MyApplication(int XX = 800, int YY = 400) : Application(XX,YY){
        new_widget(new NumberEditor(10,10, true, 0, 100));
        new_widget(new NumberEditor(10,60));
        new_widget(new NumberEditor(10,110));
        new_widget(new TextEditor(10,160, 100));
        new_widget(new StaticText(10, 210, "Helloka! Mi a  helyzet?"));
        new_widget(new StaticText(10,300, "Neved:"));
        new_widget(new TextEditor(60,300, 140));
        new_widget(new CheckBox(10, 350, 20,20));
        new_widget(new StaticText(40, 350, "cserkesz"));

        _sl = new SelectorList(400, 10, 100, 100);
        new_widget(_sl);
    }

    void run(int timer = 40) override {
        for (string s : {"Lili","Kata", "Anna", "Steve", "Peti"}){
            _sl->new_item(s);
        }
        _sl->delete_selected();
        event_loop(timer);
    };
};



int main(){
/*
    StaticText* t = new StaticText(400,300, "Itt vagyok :)");
    //t->show();
    list<StaticText*> l = {t};
    list<StaticText*>::iterator it = l.begin();
    gout.open(800,400);
    (*it)->show();
    gout<<refresh;
    event ev;
    while(gin>>ev){}


    list<int> l2 = {1,2,3,4,5};
    list<int>::iterator it2 = l2.begin();
    for(list<int>::iterator it = it2; it!=l2.end(); it++){}
    cout<<*it2<<endl<<endl;
*/
    MyApplication myapp;
    myapp.run();

    return 0;
}
