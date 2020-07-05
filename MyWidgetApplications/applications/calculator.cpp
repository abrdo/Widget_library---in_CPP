#include "calculator.hpp"
#include <iostream>
#include <math.h>

using namespace genv;

Calculator::Calculator(int XX, int YY) : Window(XX,YY){
    // MODEL ----
    _op1 = _op2 = 0;
    _oper = null;
    _error_message = "";

    _ubound = 1e9-1;
    _lbound = -1e9+1;
    _op2_is_empty = true;


    // VIEW -----
    // display
    _op1W = new StaticText(25+4, 25, "0", 180, 180, 180, false, 150, 50, 20);
    _widgets.push_back(_op1W);

    _op2W = new NumberEditor(25, 75, 150, 45, true, _lbound, _ubound, false, 20/*-->fontsize*/, 30,30,30);
    _op2W->set_possibility_to_type_minus(false);
    _widgets.push_back(_op2W);

    _operW = new StaticText(2+4, 75, "", 180, 180, 180, false, 150, 50, 20);
    _widgets.push_back(_operW);

    // numbers
    for(int i=1; i<10; i++){
        _numberWs[i] = new FuncButton(25+(i-1)%3*50, 125+(i-1)/3*50, Widget::to_str(i), [=](){this->number_pushed(i);}, 50,50);
        _widgets.push_back(_numberWs[i]);
    }
    _signW = new FuncButton(25, 125+3*50, "+/-", [&](){_op2 = _op2W->get_number(); _op2_is_empty = _op2W->is_empty(); _op2 = -_op2; update();}, 50,50);
    _widgets.push_back(_signW);
    _numberWs[0] = new FuncButton(25+1*50, 125+3*50, "0", [=](){this->number_pushed(0);}, 50,50);
    _widgets.push_back(_numberWs[0]);

    // extra
    _backspaceW = new FuncButton(80+2*50, 75, "C", [=](){this->pop();}, 50,25);
    _widgets.push_back(_backspaceW);
    _undoW = new FuncButton(30+3*50, 100, "undo", [=](){this->undo();}, 50,25);
    _widgets.push_back(_undoW);
    _newW = new FuncButton(30+4*50, 75, "new", [=](){this->reset();}, 50,50);
    _widgets.push_back(_newW);

    // operations
    _addW = new FuncButton(30+3*50, 125, "+", [=](){this->operation_pushed(Operation::ADD);}, 50,50);
    _widgets.push_back(_addW);
    _substractW = new FuncButton(30+4*50, 125, "-", [=](){this->operation_pushed(Operation::SUBSTRACT);}, 50,50);
    _widgets.push_back(_substractW);
    _multiplyW = new FuncButton(30+3*50, 125+50, "x", [=](){this->operation_pushed(Operation::MULTIPLY);}, 50,50);
    _widgets.push_back(_multiplyW);
    _divideW = new FuncButton(30+4*50, 125+50, "/", [=](){this->operation_pushed(Operation::DIVIDE);}, 50,50);
    _widgets.push_back(_divideW);
    _equalsW = new FuncButton(30+3*50, 125+2*50, "=", [=](){this->operation_pushed(Operation::EQUALS);}, 100,50);
    _widgets.push_back(_equalsW);

    _default_button_frame_color = _newW->get_frame_color();
    reset();
}

void Calculator::undo(){
    _op1 = _history_op1[_history_op1.size()-1];
    _history_op1.pop_back();
    _op2 = 0;
    _oper = null;
    _error_message = "";
    update();
}

void Calculator::pop(){
    _op2 = _op2W->get_number();
    _op2_is_empty = _op2W->is_empty();
    _op2 /= 10;
    if(_op2==0)
        _op2_is_empty = true;
        update();
}

void Calculator::reset(){
    for(Widget*w : _widgets) w->set_focused(false);
    _op1 = _op2 = 0;
    _oper = null;
    _error_message = "";
    _history_op1.clear();
    _op2_is_empty = true;
    update();
    _op2W->set_focused(true);
}

void Calculator::update(){
    _newW->set_frame_color(_default_button_frame_color['r'], _default_button_frame_color['g'], _default_button_frame_color['b']);
    // if error
    if(_error_message!=""){
        _op1W->set_color(255, 70, 70);
        _op1W->set_text(_error_message);
        for(Widget* w : _widgets){
            w->set_focused(false);
            w->set_focusable(false);
        }
        _newW->set_focusable(true);
        _undoW->set_focusable(true);
        return;
    }else
        _op1W->set_color(180, 180, 180);
        for(Widget* w : _widgets) w->set_focusable(true);
    // end if error

    // display
    _op1W->set_text(Widget::to_str(_op1));
    if(!_op2_is_empty) _op2W->set_text(Widget::to_str(_op2)); else _op2W->set_text("");

    // operation sign
    if(_oper == null)
        _operW->set_text("");
    if(_oper == ADD)
        _operW->set_text("+");
    if(_oper == SUBSTRACT)
        _operW->set_text("-");
    if(_oper == MULTIPLY)
        _operW->set_text("x");
    if(_oper == DIVIDE)
        _operW->set_text("/");
    if(_oper == EQUALS)
        _operW->set_text("=");

    if(_oper == EQUALS || (_oper == null && _op1 != 0)){
        _backspaceW->set_focusable(false);
        _signW->set_focusable(false);
        for(int i = 0; i<10; i++)
            _numberWs[i]->set_focusable(false);
    }else{
        _backspaceW->set_focusable(true);
        _signW->set_focusable(true);
        for(int i = 0; i<10; i++)
            _numberWs[i]->set_focusable(true);
    }

    if(_history_op1.empty())
        _undoW->set_focusable(false);
    else
        _undoW->set_focusable(true);
}

void Calculator::number_pushed(int n){
    _op2 = _op2W->get_number();
    _op2_is_empty = _op2W->is_empty();

    std::string s_op2 = Widget::to_str(_op2);
    if(s_op2[0]!='-' && s_op2.size()   >= log10(_ubound)) return;
    if(s_op2[0]=='-' && s_op2.size()-1 >= log10(_ubound)) return;

    if (0 <= _op2)
        _op2 = 10*_op2 + n;
    else
        _op2 = 10*_op2 - n;

    _op2_is_empty = false;
    update();
}

void Calculator::operation_pushed(Operation new_op){
    // "pull":
    _op2 = _op2W->get_number();
    _op2_is_empty = _op2W->is_empty();
    // for check overflow errors:
    int prev_op1 = _op1;
    int prev_op2 = _op2;
    _history_op1.push_back(_op1);
    if(!_op2_is_empty){
        if(_oper == null && /*not in case of undo:*/!(_oper == null && _op1 != 0 && _op2 == 0)){
            _op1 = _op2;
        }
        if(_oper == ADD){
            _op1 = _op1 + _op2;
            if((0<prev_op1 && 0<prev_op2 && _op1<0) || _ubound<_op1) _error_message = "Overflow Error";
            if((0>prev_op1 && 0>prev_op2 && _op1>0) || _lbound>_op1) _error_message = "Underflow Error";
        }
        if(_oper == SUBSTRACT){
            _op1 = _op1 - _op2;
            if((0<prev_op1 && 0>prev_op2 && _op1<0) || _ubound<_op1) _error_message = "Overflow Error";
            if((0>prev_op1 && 0<prev_op2 && _op1>0) || _lbound>_op1) _error_message = "Underflow Error";
        }
        if(_oper == MULTIPLY){
            _op1 = _op1 * _op2;
            if     ((0<prev_op1 && 0<prev_op2) && _op1/prev_op1!=prev_op2 || _ubound<_op1) _error_message = "Overflow Error";
            else if((0>prev_op1 && 0>prev_op2) && _op1/prev_op1!=prev_op2 || _lbound>_op1) _error_message = "Underflow Error";
            else if((0<prev_op1 && 0>prev_op2) && _op1/prev_op1!=prev_op2 || _lbound>_op1) _error_message = "Underflow Error";
            else if((0>prev_op1 && 0<prev_op2) && _op1/prev_op1!=prev_op2 || _lbound>_op1) _error_message = "Underflow Error";
        }
        if(_oper == DIVIDE){
            if(_op2 == 0){
                _oper = null;
                _error_message = "Math Error";
            }
            else{
                _op1 = _op1 / _op2;
                _error_message = "";
            }
        }
        _op2 = 0;
        _op2_is_empty = true;
    }
    _oper = new_op;
    for(Widget* w : _widgets) w->set_focused(false);
    _op2W->set_focused(true);

    if(_oper == EQUALS){
        _op2 = _op1;
        _op2_is_empty = false;
    }
    update();
    if(_oper == EQUALS){
        _op2 = 0;
        _op2_is_empty = true;
        _op2W->set_focusable(false);
        _newW->set_focused(true);
    }
}

void Calculator::run(int timer){
    gout.open(_XX, _YY);
    gin.timer(timer);
    event ev;
    while(gin >> ev && !_exit){
        if(ev.keycode == '+'){
            operation_pushed(Operation::ADD);
            for(Widget* w : _widgets) w->set_focused(false);
            _op2W->set_focused(true);
        }
        if(ev.keycode == '-'){
            operation_pushed(Operation::SUBSTRACT);
            for(Widget* w : _widgets) w->set_focused(false);
            _op2W->set_focused(true);
        }
        if(ev.keycode == '*'){
            operation_pushed(Operation::MULTIPLY);
            for(Widget* w : _widgets) w->set_focused(false);
            _op2W->set_focused(true);
        }
        if(ev.keycode == '/'){
            operation_pushed(Operation::DIVIDE);
            for(Widget* w : _widgets) w->set_focused(false);
            _op2W->set_focused(true);
        }
        if(ev.keycode == key_enter){
            bool there_is_a_focused_button = false;
            if(!_op2W->is_focused()){
                for(Widget* w : _widgets){
                    if(w->is_focused())
                        there_is_a_focused_button = true;
                }
            }
            if(!there_is_a_focused_button){
                operation_pushed(Operation::EQUALS);
                for(Widget* w : _widgets) w->set_focused(false);
                ev.keycode = 'ß'; //any key but not enter or space
                _newW->set_focused(true);

            }
        }
        //----------------------------------------------------------
        handle__iterate_focused_by_tab__show(ev);
        if(ev.keycode == key_escape)
            _exit = true;
    }
    _exit = false;

}
