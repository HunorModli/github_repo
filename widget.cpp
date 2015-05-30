#include "widget.h"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) {
    pos_x=x;
    pos_y=y;
    size_x = sx;
    size_y=sy;
    focused=false;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const {
    return ( mouse_x>pos_x && mouse_x<pos_x+size_x && mouse_y>pos_y && mouse_y<pos_y+size_y );
}


void Widget::handle(event ev) {
}

bool Widget::focusable() const {
    return true;
}

void Widget::focus() {
    focused = true;
}

void Widget::unfocus() {
    focused = false;
}


