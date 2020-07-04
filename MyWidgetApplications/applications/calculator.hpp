#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "application.hpp"
#include "../numbereditor.hpp"
#include "../funcbutton.hpp"
#include "../statictext.hpp"

#include <vector>

enum Operation {null, ADD, SUBSTRACT, MULTIPLY, DIVIDE, EQUALS};

class Calculator : public Application
{
   // Model ----
    int _op1, _op2; //op2 - current operand under editing; op1 - previous operand
    int _ubound, _lbound;
    Operation _oper;
    std::string _error_message;
    std::vector<int> _history_op1;
    int yshift; // used just for displaying

   // View ----
    // display
    StaticText* _op1W;
    NumberEditor* _op2W;
    StaticText* _operW;

    // buttons
    FuncButton* _numberWs[10];

    FuncButton* _signW;

    FuncButton* _addW;
    FuncButton* _substractW;
    FuncButton* _multiplyW;
    FuncButton* _divideW;
    FuncButton* _equalsW;

    FuncButton* _backspaceW;
    FuncButton* _undoW;
    FuncButton* _newW;




public:
    Calculator(int window_size_x = 305, int window_size_y = 350);
    void undo();
    void reset();
    void update();
    void number_pushed(int number);
    void operation_pushed(Operation op);

    static void change(Calculator* pcalc){
        pcalc->shot_down();
        //iterator it = pcalc.history.end()--;
        //*it
        Calculator csit(900,250); //egyel korábbi app;
        *pcalc = csit;
        pcalc->run();

        //Calculator a(700,700);
        //Calculator c = a;
        //c.run();


        //c = *this;
        //*this = c;
    }
};

#endif // CALCULATOR_HPP
