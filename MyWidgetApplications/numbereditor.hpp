#ifndef NUMBEREDITOR_HPP
#define NUMBEREDITOR_HPP

#include "widget.hpp"

class NumberEditor : public Widget{
    std::string _snum;
    const int _ubound, _lbound; // upper bound, lower bound
    bool _set_to_bound; // set_to_bound_if_out_of_range = false /*if false, user can't continue typinf to out of range
    bool _cursor_visible;
public:
    bool _is_bounded;
    bool is_in_range(int i);
    NumberEditor(int x, int y, bool is_bounded = false, int lower_bound_ = -2147483638, int upper_bound_ = 2147483637, bool _set_to_bound_if_out_of_range = false/*if false, user can't continue typinf to out of range*/); // size_y =25;
    NumberEditor(int x, int y, int sx, int sy = 25, bool is_bounded = false, int lower_bound_ = -2147483638, int upper_bound_ = 214748363, bool _set_to_bound_if_out_of_range = false, int fontsize = 14, int background_r = -1, int background_g = -1, int background_b = -1);
    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) const override;

    void set_number(int num){ _snum = Widget::to_str(num); }
    void set_text(std::string snum){ _snum = snum; }
    int get_number(){ if(is_empty()) return 0; else return Widget::to_int(_snum); }
    bool is_empty(){ return _snum == ""; }

};

#endif // NUMBEREDITOR_HPP
