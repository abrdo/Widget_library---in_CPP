#include "application.hpp"
#include "numbereditor.hpp"
#include "texteditor.hpp"
#include "statictext.hpp"
#include "checkbox.hpp"

#include "graphics.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;


class MyApplication : public Application{
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
    }

    void run(int timer = 40) override {
        event_loop(timer);
    };
};


int main(){
    MyApplication myapp;
    myapp.run();
    return 0;
}
