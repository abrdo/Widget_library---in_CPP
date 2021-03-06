#ifndef WIDGETTESTERAPP_HPP
#define WIDGETTESTERAPP_HPP

#include "../window.hpp"

#include "../checkbox.hpp"
#include "../statictext.hpp"
#include "../numbereditor.hpp"
#include "../texteditor.hpp"
#include "../selectorlist.hpp"
#include "../funcbutton.hpp"


class WidgetTesterApp : public dowi::Window{
    dowi::SelectorList* _sl;
    dowi::FuncButton* _b;
public:
    WidgetTesterApp(int XX = 800, int YY = 400);
};

#endif // WIDGETTESTERAPP_HPP
