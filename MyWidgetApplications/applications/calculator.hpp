#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "../window.hpp"
#include "../numbereditor.hpp"
#include "../funcbutton.hpp"
#include "../statictext.hpp"

#include <vector>

enum Operation {null, ADD, SUBSTRACT, MULTIPLY, DIVIDE, EQUALS};

class Calculator : public Window
{
   // Model ----
    int _op1, _op2; //op2 - current operand under editing; op1 - previous operand
    int _ubound, _lbound;
    Operation _oper;
    std::string _error_message;
    std::vector<int> _history_op1;
    bool _op2_is_empty;

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
    void pop();
    void undo();
    void reset();
    void update();
    void number_pushed(int number);
    void operation_pushed(Operation op);
    void run(int timer = 40) override;
};

#endif // CALCULATOR_HPP
