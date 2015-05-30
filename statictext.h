#ifndef STATICTEXT_H_INCLUDED
#define STATICTEXT_H_INCLUDED

#include <string>
#include "widget.h"

class StaticText : public Widget {
protected:
    std::string label;
    int r,g,b,_size;
public:
    StaticText(int x, int y, int sx, int sy, std::string _s);
    StaticText(int x, int y, int sx, int sy, int r, int g, int b, std::string _s, int _t);
    virtual void draw() const ;
    bool focusable() const {return false;}
    void setText(std::string s) {label=s;}
};


#endif
