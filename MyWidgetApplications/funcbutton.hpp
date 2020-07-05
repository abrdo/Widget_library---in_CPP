#ifndef FUNCBUTTON_HPP_INCLUDED
#define FUNCBUTTON_HPP_INCLUDED

#include "widget.hpp"

#include <functional>


class FuncButton : public Widget {
protected:
    std::function<void()> _f; //std::function<void(funcbutton*)> f;
    std::string _label;
    bool _pushed;

public:
    FuncButton(int x, int y, std::string label, std::function<void()> func, int sx = 100, int sy = 25);

    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) const override;

};

#endif // FUNCBUTTON_HPP_INCLUDED
