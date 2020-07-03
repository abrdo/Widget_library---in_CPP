#include "widgettesterapp.hpp"
using namespace genv;
using namespace std;


WidgetTesterApp::WidgetTesterApp(int XX, int YY) : Application(XX,YY){
    _widgets.push_back(new NumberEditor(10,10, 200, 25, true, -22, 100));
    _widgets.push_back(new NumberEditor(10,60, true, -22, 100, true));
    _widgets.push_back(new NumberEditor(10,110));
    _widgets.push_back(new TextEditor(10,160, 100));
    _widgets.push_back(new StaticText(10, 210, "Helloka! Mi a  helyzet?"));
    _widgets.push_back(new StaticText(7,300, "Neved:"));
    _widgets.push_back(new TextEditor(60,300, 140));
    _widgets.push_back(new CheckBox(10, 350, 20,20));
    _widgets.push_back(new StaticText(40, 350, "check"));

    _sl = new SelectorList(400, 10, 100, 103);
    _widgets.push_back(_sl);
    _b = new FuncButton(400, 200, "Button", [](){});
    _widgets.push_back(_b);

    for (string s : {"Lili","Kata", "Anna", "Steve", "Peti", "Zsuzsi", "Cili", "Janos", "Peter"}){
        _sl->new_item(s);
    }
}
