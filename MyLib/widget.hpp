#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"
#include <sstream>

class Widget{
private:
    bool _focused;
    bool _focusable;
protected:
    int _x, _y, _size_x, _size_y;
    int _fonthight;
    unsigned char _r, _g, _b;

public:
    Widget(){}
    Widget(int x, int y, int sx, int sy);
    void set_focused(bool f);
    bool is_focused();
    void set_focusable(bool f);
    bool is_focusable();

    bool mouse_above(int mouse_x, int mouse_y);
    virtual void handle(genv::event ev);
    virtual void show() = 0;

    void show_frame();
    void focus_by_click(genv::event ev);

    int get_size_y(){return _size_y;}


};

inline std::string to_str(int i){
    std::stringstream ss;
    ss<<i;
    std::string s;
    ss>>s;
    return s;
}

inline int to_int(std::string s){
    std::stringstream ss;
    ss<<s;
    int i;
    ss>>i;
    return i;
}

inline bool is_inside(int px, int py, int x1, int x2, int y1, int y2){ //is (px, py) in a rectangle?
    return x1<=px && px<=x2 && y1<=py && py<=y2;
}

#endif // WIDGET_HPP
