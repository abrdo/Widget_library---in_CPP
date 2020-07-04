#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

struct StaticText : public Widget
{
    std::string _text;
    bool _show_frame;

    StaticText(){}
    StaticText(int x, int y, std::string text, unsigned char r = 180, unsigned char g = 180, unsigned char b = 180,
               bool show_frame = false, int size_x = 150, int size_y = 25/*sx, sy is obligatory in this case!!!*/, int fontsize = 14,
               unsigned char frame_r = 210, unsigned char frame_g = 210, unsigned char frame_b = 210);
    void set_rgb(unsigned r, unsigned g, unsigned b){_r=r; _g=g; _b=b;}
    void show(genv::canvas &c = genv::gout) override;
    void handle(genv::event ev) override {}

    void set_text(std::string t){ _text = t; }
    //void set_focusable(bool f) override {}
};

#endif // STATICTEXT_HPP
