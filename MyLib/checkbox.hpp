#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include "widget.hpp"


class CheckBox : public Widget
{
private:
    bool _checked;
public:
    CheckBox(int x, int y, int sx, int sy);
    void set_checked(bool ch);
    void toggle();
    void handle(genv::event ev) override;
    void show() override;


};

#endif // CHECKBOX_HPP
