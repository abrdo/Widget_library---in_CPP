#include "application.hpp"
#include "numbereditor.hpp"
#include "texteditor.hpp"
#include "statictext.hpp"
#include "checkbox.hpp"
#include "selectorlist.hpp"
#include "funcbutton.hpp"

#include "graphics.hpp"
#include <iostream>
#include <vector>


using namespace genv;
using namespace std;


class MyApplication : public Application{
    SelectorList* _sl;
    FuncButton* _b;
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
        new_widget(new StaticText(40, 350, "check"));

        _sl = new SelectorList(400, 10, 100, 103);
        new_widget(_sl);
        _b = new FuncButton(400, 200, "Button");
        new_widget(_b);
    }

    void run(int timer = 40) override {
        for (string s : {"Lili","Kata", "Anna", "Steve", "Peti", "Zsuzsi", "Cili", "Janos", "Peter"}){
            _sl->new_item(s);
        }
        _sl->delete_selected();
        //-----
        event_loop(timer);
    };
};



int main(){
    MyApplication myapp;
    myapp.run();

    return 0;
}

