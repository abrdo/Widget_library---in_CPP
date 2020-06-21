#ifndef TEXTEDITOR_HPP
#define TEXTEDITOR_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include "statictext.hpp"

class TextEditor : public Widget{
    std::string _text;
    bool _cursor_visible;
    StaticText _text_if_empty;
public:
    TextEditor(int x, int y, int sx, int sy = genv::gout.cascent()+genv::gout.cdescent()+7);
    void handle(genv::event ev) override;
    void show() override;
};

#endif // TEXTEDITOR_HPP
