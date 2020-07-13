#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"
#include "../window.hpp"
#include <sstream>
#include <map>

namespace dowi{

class Window;


/**
 *@brief the Widget base class
 */
class Widget{
protected:
    int _x, _y; ///< the x, y coordinates of the top-left corner of the widget
    int _size_x, _size_y; ///< the width (_size_x) and the hight (_size_y) of the widget
    Window* _window; ///< the window what contains this widget. (not necessary to provide with value to use a widget properly)

    bool _focused; ///< is the widget in focus
    bool _focusable; ///< is the widget focusable
    bool _targeted; ///< It is true if the widget is focusable and the mouse is over it.

    int _fonthight; ///< the fonhight of the fonts used by the widget (if it uses fonts by the visualization)
    std::string __fontfile; ///< The name of the fontfile from witch the fonts readed. It must exist in the project folder with '.ttf' extension
    int __fontsize; ///< The fontsize of the visualized text. (the __fontfile must support this fontsize)

    unsigned char _r, _g, _b; ///< the RGB color values of the widget. The meaning of color - if exists at all - is various by the different widgets.
    unsigned char _bgcol_r, _bgcol_g, _bgcol_b; ///< the base background-color of the widget
    unsigned char _frame_r, _frame_g, _frame_b; ///< the color of the frame of the widget

public:
    Widget(){}
    Widget(int x, int y, int sx, int sy, int fontsize = 14, Window* window = 0);
    Widget(int x, int y, int sx, int sy, unsigned char backgroundcolor_r, unsigned char backgroundcolor_g, unsigned char backgroundcolor_b);
    virtual ~Widget(){}
    bool is_focused();
    void set_focused(bool f);
    bool is_focusable();
    void set_focusable(bool f);
    void set_color(unsigned char r, unsigned char g, unsigned char b){ _r=r; _g=g; _b=b;}
    std::map<char, unsigned char> get_frame_color(){std::map<char, unsigned char> out; out['r']=_frame_r; out['g']=_frame_g; out['b']=_frame_b; return out;};
    void set_frame_color(unsigned char r, unsigned char g, unsigned char b){ _frame_r=r; _frame_g=g; _frame_b=b;}


    bool mouse_above(genv::event ev) const;
    virtual void handle(genv::event ev) = 0;
    /**
     *@brief visualize the widget
     *@param c the genv::canvas type canvas to which you would like to draw the widget. The default gout is the standard graphical output.
     *@warning Do not use visualization in other function. Violation of this rule endanger the thread-safety.
     */
    virtual void show(genv::canvas &c = genv::gout) const = 0;
    void show_frame(genv::canvas &c = genv::gout) const;

    bool focusing_click(genv::event ev) const;
    void focus_by_click(genv::event ev);

    inline bool is_inside(int px, int py, int x1, int x2, int y1, int y2) {return x1<=px && px<=x2 && y1<=py && py<=y2;} //is (px, py) in a rectangle?

    // --------------------CONVERTERS----------------------------------------------------------
    /*
    template <typename T>
    static std::string to_str(T num){
        std::stringstream ss;
        ss<<num;
        std::string s;
        ss>>s;
        return s;
    }

    template <typename T>
    static T to_num(std::string s){
        std::stringstream ss;
        ss<<s;
        T i;
        ss>>i;
        return i;
    }

    template <typename T>
    static char to_char(T num){
        std::stringstream ss;
        ss<<num;
        char ch;
        ss>>ch;
        return ch;
    }
    */

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

    static char to_char(int i){
        std::stringstream ss;
        ss<<i;
        char ch;
        ss>>ch;
        return ch;
    }
/*
    // DOUBLE - STRING CONVERTERS:
    static std::string to_str(double d){
        std::stringstream ss;
        ss<<d;
        std::string s;
        ss>>s;
        return s;
    }

    static double to_double(std::string s){
        std::stringstream ss;
        ss<<s;
        double d;
        ss>>d;
        return d;
    }
*/
};

} // namespace
#endif // WIDGET_HPP
