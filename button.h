#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <functional>

#include "widget.h"

class Button : public Widget {
protected:
    std::string label;
    std::function <void ()> fn;
    bool clicked;
public:
    Button(int x, int y, int sx,int sy, std::function <void ()> f,  std::string _s);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
};

#endif
