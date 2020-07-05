#ifndef STATICTEXTCOMP_HPP
#define STATICTEXTCOMP_HPP

#include "widget.hpp"


/// StaticText as a component for building into widgets it is more practical to use this static text than the original StaticText

struct StaticTextComp : public Widget
{
    std::string _text;

    StaticTextComp(){}
    void set_rgb(unsigned r, unsigned g, unsigned b){_r=r; _g=g; _b=b;}
    StaticTextComp(int x, int y, std::string text, unsigned char r = 180, unsigned char g = 180, unsigned char = 180 );
    void show(genv::canvas &c = genv::gout) const override;
    void handle(genv::event ev) override {}

    int get_x(){return _x;}
    void set_x(int x){_x = x;}
    int get_y(){return _y;}
    void set_y(int y){_y = y;}
    int get_size_x(){return _size_x;}
    void set_size_x(int sx){_size_x = sx;}
    int get_size_y(){return _size_y;}
    void set_size_y(int sy){_size_y = sy;}
};

#endif // STATICTEXTCOMP_HPP

