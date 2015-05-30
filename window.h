#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widget.h"
#include <vector>

class Window {
protected:
    int Width, Height;
    std::vector<Widget*> widgets;
    bool _terminate;

public:
    Window(int _X, int _Y) ;
    void event_loop() ;
    void terminate();
};

#endif
