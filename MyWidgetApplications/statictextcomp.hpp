#ifndef STATICTEXTCOMP_HPP
#define STATICTEXTCOMP_HPP

#include "widget.hpp"

struct StaticTextComp : public Widget
{
    std::string _text;

    StaticTextComp(){}
    void set_rgb(unsigned r, unsigned g, unsigned b){_r=r; _g=g; _b=b;}
    StaticTextComp(int x, int y, std::string text, unsigned char r = 180, unsigned char g = 180, unsigned char = 180 );
    void show(genv::canvas &c = genv::gout) override;
    void handle(genv::event ev) override {}
};

#endif // STATICTEXTCOMP_HPP

