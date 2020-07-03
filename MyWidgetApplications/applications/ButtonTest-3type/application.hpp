#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "../widget.hpp"
#include <vector>



class Application
{
protected:
    int _XX, _YY; // window size parameters
    std::vector<Widget*> _widgets;
    int _focused; // index of focused widget;
public:
    Application(int window_size_x, int window_size_y);
    virtual ~Application();

    void iterate_focused_by_tab(genv::event ev);
    void handle__iterate_focused_by_tab__show(genv::event ev);

    virtual void run(int timer = 40);
};

#endif // APPLICATION_HPP
