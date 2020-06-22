#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widget.hpp"
#include <vector>



class Application
{
protected:
    int _XX, _YY; // window size parameters
    std::vector<Widget*> _widgets;
    int _focused; // index of focused widget;
public:
    Application(int window_size_x, int window_size_y);
    ~Application();
    void new_widget(Widget* w);
    void event_loop(int timer);
    virtual void run(int timer = 40) = 0;
};

#endif // APPLICATION_HPP
