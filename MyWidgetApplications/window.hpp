#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../widget.hpp"
#include <vector>

namespace dowi{

class Widget;

/**
 *@brief the application base class. Create applications via deriving from this class.
 */
class Window
{
protected:
    int _XX, _YY; ///< window size parameters
    unsigned char _bgcol_r, _bgcol_g, _bgcol_b; ///< background color
    std::vector<Widget*> _widgets;
    int _focused; ///< index of focused widget
    bool _exit;
public:
    Window(int window_size_x, int window_size_y);
    virtual ~Window();

    void iterate_focused_by_tab(genv::event ev);
    void handle__iterate_focused_by_tab__show(genv::event ev);

    virtual void run(int timer = 40);

    void shot_down(){_exit = true;}
};

} // namespace
#endif // WINDOW_HPP
