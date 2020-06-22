#ifndef NUMBEREDITOR_HPP
#define NUMBEREDITOR_HPP

#include "widget.hpp"

class NumberEditor : public Widget{
    std::string _snum;
    const int _ubound, _lbound; // upper bound, lower bound
    bool _cursor_visible;
public:
    bool _is_bounded;
    bool is_in_range(int i);
    NumberEditor(int x, int y, bool is_bounded = false, int lower_bound_ = -2147483638, int upper_bound_ = 2147483637); // size_y = 30;
    void handle(genv::event ev) override;
    void show() override;
};

#endif // NUMBEREDITOR_HPP
