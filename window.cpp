#include "window.h"

using namespace genv;

Window::Window(int _X, int _Y) :
    Width(_X),Height(_Y) {
    gout.open(Width,Height);
    _terminate = false;
}

void Window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape && !_terminate) {
        if (ev.keycode == key_tab) {
            if(focus!=-1) {
                widgets[focus]->unfocus();
            }
            do {
                focus++;
                if (focus>=widgets.size()) focus = 0;
            } while (!widgets[focus]->focusable());
            widgets[focus]->focus();
        }
        if (ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && widgets[i]->focusable()) {
                        if (focus!=-1) widgets[focus]->unfocus();
                        focus = i;
                        widgets[focus]->focus();
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        gout << move_to(0,0) << color(180,180,180) << box(Width, Height);

        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }

        gout << refresh;
    }
}

void Window::terminate() {
    _terminate = true;
}
