#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../../widget.hpp"
#include "graphics.hpp"


class Button : public Widget
{
    std::string _label;
public:
    Button(int x, int y, std::string label, int sx = 100, int sy = 25);

    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) override;

    virtual void action();
};

#endif // BUTTON_HPP
