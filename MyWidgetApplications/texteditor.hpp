#ifndef TEXTEDITOR_HPP
#define TEXTEDITOR_HPP

#include "widget.hpp"
#include "statictextcomp.hpp"

namespace dowi{

class TextEditor : public Widget{
    std::string _text;
    bool _cursor_visible;
    StaticTextComp _text_if_empty;
public:
    TextEditor(int x, int y, int sx = 140, int sy = 25);
    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) const override;
    std::string get_text(){  return _text; }
};

} // namespace
#endif // TEXTEDITOR_HPP
