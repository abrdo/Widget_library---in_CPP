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
    std::string __fontfile;
    int __fontsize;
    unsigned char _r, _g, _b;

public:
    Widget(){}
    Widget(int x, int y, int sx, int sy);
    virtual ~Widget(){}

    int get_x(){return _x;}
    void set_x(int x){_x = x;}
    int get_y(){return _y;}
    void set_y(int y){_y = y;}
    int get_size_x(){return _size_x;}
    void set_size_x(int sx){_size_x = sx;}
    int get_size_y(){return _size_y;}
    void set_size_y(int sy){_size_y = sy;}
    bool is_focused();
    void set_focused(bool f);
    bool is_focusable();
    void set_focusable(bool f);


    bool mouse_above(genv::event ev);
    virtual void handle(genv::event ev) = 0;


    virtual void show(genv::canvas &c = genv::gout) = 0;
    void show_frame(genv::canvas &c = genv::gout);

    bool focusing_click(genv::event ev);
    void focus_by_click(genv::event ev);





    static std::string to_str(int i){
        std::stringstream ss;
        ss<<i;
        std::string s;
        ss>>s;
        return s;
    }

    static int to_int(std::string s){
        std::stringstream ss;
        ss<<s;
        int i;
        ss>>i;
        return i;
    }

    inline bool is_inside(int px, int py, int x1, int x2, int y1, int y2){ //is (px, py) in a rectangle?
        return x1<=px && px<=x2 && y1<=py && py<=y2;
    }

};

#endif // WIDGET_HPP
