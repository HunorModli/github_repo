#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    bool focused;
    int pos_x, pos_y, size_x, size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const =0;
    virtual void handle(genv::event ev);
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
};

#endif
