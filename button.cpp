#include "button.h"

using namespace std;
using namespace genv;

Button::Button(int x, int y, int sx, int sy, function <void()>f, string _s) : Widget(x,y,sx,sy),label(_s), fn(f) {
}

void Button::draw() const {

    gout << move_to(pos_x+0.2,pos_y+0.2) << color(100,100,100) << box(size_x-0.4, size_y-0.4);

    if(clicked) {
        gout << move_to(pos_x,pos_y)<< color(100,100,100) << box(size_x,size_y)
             << move_to(pos_x+(size_x/2)-(gout.twidth(label)/2),pos_y+(size_y/2)+((gout.cascent()-gout.cdescent())/2)-15) << color(0,0,0) << text(label);
    } else {
        gout << move_to(pos_x+(size_x/2)-(gout.twidth(label)/2),pos_y+(size_y/2)+((gout.cascent()-gout.cdescent())/2)-15) << color(255,255,255) << text(label);
    }

    if(focused) {
        gout << color(1,1,255) << move_to(pos_x,pos_y) << line(size_x,0) << line(0,size_y) << line(-size_x,0) << line(0,-size_y);
    }
}
void Button::handle(genv::event ev) {

    bool helper = 1;
    if(ev.button == 1 && ev.pos_x > pos_x && ev.pos_x < pos_x+size_x && ev.pos_y > pos_y && ev.pos_y < pos_y+size_y && clicked == 0 && helper){
        clicked = 1;
        helper = 0;
        fn();
    }

    if(ev.button == -1 && clicked && helper){
        clicked = 0;
        helper = 0;
    }
    if (ev.keycode == key_enter && focused) {
        fn();
    }
}

