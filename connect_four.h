#ifndef CONNECT_FOUR_H_INCLUDED
#define CONNECT_FOUR_H_INCLUDED
#include "widget.h"
#include <vector>
#include <cstdlib>
#include <iostream>


class Connect_Four : public Widget {
protected:
    int pegs[7][6]; /// value is 0,1,or 2;
    bool game_is_on, already_won;
    int turn_of_player; /// Value is 1, or 2.
    int winner;
    bool _draw;

public:
    Connect_Four(int x, int y, int sx, int sy) : Widget(x, y, sx, sy) {
        for (int i=0;i<7;i++) {
            for (int j=0;j<6;j++) {
                pegs[i][j] = 0;
            }
        }
        turn_of_player = 1;
        game_is_on = false;
        already_won = false;
        _draw = false;
        genv::gout.load_font("Not Just Groovy.ttf",16,true);
    }

    void draw()const;
    void handle(genv::event ev);
    bool focusable() const {return false;}
    void drop_peg(int i); /// i:column number.
    void start_game();
    bool check_for_win(int a, int b);
    bool is_on() const {return game_is_on;}
};


#endif // CONNECT_FOUR_H_INCLUDED
