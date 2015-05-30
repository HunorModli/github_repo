#include "statictext.h"
#include <string>

using namespace std;
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, string _s) : Widget(x,y,sx,sy) {
    label=_s;
    r = g = b = 30;
    _size = 16;
}

StaticText::StaticText(int x, int y, int sx,int sy, int r, int g, int b, string _s, int _t) : Widget(x,y,sx,sy) {
    this->r = r;
    this->g = g;
    this->b = b;
    label=_s;
    _size = _t;
}

void StaticText::draw() const {
    genv::gout.load_font("Not Just Groovy.ttf",_size,true);
    gout << color(r,g,b) << move_to(pos_x,pos_y+20) << text(label);
    genv::gout.load_font("Not Just Groovy.ttf",16,true);
}
