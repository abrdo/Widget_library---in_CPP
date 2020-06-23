#ifndef FUNCBUTTON_HPP_INCLUDED
#define FUNCBUTTON_HPP_INCLUDED

#include "widget.hpp"

#include <functional>


class FuncButton : public Widget {
protected:
    std::function<void()> _f; //std::function<void(funcbutton*)> f;
    std::string _label;

public:
    FuncButton(int x, int y, std::string label, /*std::function<void()> func,*/ int sx = 100, int sy = 25);
    void call();
    std::string get_data();

    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) override;

};

#endif // FUNCBUTTON_HPP_INCLUDED
