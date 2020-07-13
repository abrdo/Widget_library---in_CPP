#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "../window.hpp"
#include "../numbereditor.hpp"
#include "../funcbutton.hpp"
#include "../statictext.hpp"

#include <vector>
#include <map>

enum Operation {null, ADD, SUBSTRACT, MULTIPLY, DIVIDE, EQUALS};

class Calculator : public dowi::Window
{
   // Model ----
    int _op1, _op2; //op2 - current operand under editing; op1 - previous operand
    int _ubound, _lbound;
    Operation _oper;
    std::string _error_message;
    std::vector<int> _history_op1;
    bool _op2_is_empty;
    std::map<char, unsigned char> _default_button_frame_color;

   // View ----
    // display
    dowi::StaticText* _op1W;
    dowi::NumberEditor* _op2W;
    dowi::StaticText* _operW;

    // buttons
    dowi::FuncButton* _numberWs[10];

    dowi::FuncButton* _signW;

    dowi::FuncButton* _addW;
    dowi::FuncButton* _substractW;
    dowi::FuncButton* _multiplyW;
    dowi::FuncButton* _divideW;
    dowi::FuncButton* _equalsW;

    dowi::FuncButton* _backspaceW;
    dowi::FuncButton* _undoW;
    dowi::FuncButton* _newW;




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
