#include "../application.hpp"
#include "button.hpp"
#include "../../checkbox.hpp"

#include <iostream>

using namespace std;
using namespace genv;

///---------------std::function button-----------------
#include <functional>

class STDfuncButton : public Button{
    function<void()> _f; // ilyen egyszerű!
public:
    STDfuncButton(int x, int y, string label, function<void()> f) : Button(x,y,label), _f(f){}
    void handle(event ev) override{
        focus_by_click(ev);
        if(Widget::focusing_click(ev)){
            _f();
        }
    }
};


///---------------Fv pointeres button-----------------------------
    // minden fv-hez kell külön statikus pár
    // így az "app" implicit paraméter "void*" explicit paraméterként megadható. ==>>  app.b1valtozzon() --> b1_valtozzon(void*) -ként hívható példányosítás nélkül.
    // Veszély: void* paramétert Application* -á kasztoljuk "kérdezés nélkül" - ez veszélyes...
typedef void (*Fvptr) (void* v);

class FvptrButton : public Button{
    Fvptr _f;
    void* _param;
public:
    FvptrButton(int x, int y, string label, Fvptr f, void* pparam) : Button(x,y,label), _f(f), _param(pparam){}
    void handle(event ev) override{
        focus_by_click(ev);
        if(Widget::focusing_click(ev)){
            _f(_param);
        }
    }
};


///---------------Basic Button for every function-----------------
    // minden app minden gombjához külön! (+kifejtés utána)
class ButtonApp;

class CheckboxSwichButton : public Button{
    ButtonApp* _app;
public:
    CheckboxSwichButton(int x, int y, std::string label, ButtonApp* app) : Button(x,y,label), _app(app){}
    void action();
};


void valami(void* v){
    cout<<"valami";
}


class ButtonApp : public Application{
    CheckBox* _cb;
    CheckboxSwichButton* _basicB;
    FvptrButton* _fvptrB;
    STDfuncButton* _stdfuncB;

public:
    ButtonApp(int XX = 400, int YY = 400): Application(XX, YY){
        _cb = new CheckBox(10,10);
        _widgets.push_back(_cb);
        _basicB = new CheckboxSwichButton(10,50,"BasicButtonááá", this);
        _widgets.push_back(_basicB);
        _fvptrB = new FvptrButton(10,100,"FvptrButton", static_SwitchCheckbox, this);
        _widgets.push_back(_fvptrB);
        _stdfuncB = new STDfuncButton(10,150,"STDfuncButton", [&](){ SwitchCheckbox(); });
        _widgets.push_back(_stdfuncB);
    }
    // FvptrButton-hoz kell minden fv-hez statikus pár:
    static void static_SwitchCheckbox(void* paramapp){
        ButtonApp* app = reinterpret_cast<ButtonApp*>(paramapp);
        app->SwitchCheckbox();
    }
    void SwitchCheckbox(){
        _cb->set_checked(!_cb->is_checked());
    }
};

// BasicButton kifejtés -----------
void CheckboxSwichButton::action(){
    _app->SwitchCheckbox();
}




int main(){
    ButtonApp myapp;
    myapp.run();

    return 0;
}
