#include "connect_four.h"
#include "graphics.hpp"
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;

void Connect_Four::draw()const {
    if (game_is_on) {
        gout << move_to(pos_x,pos_y)
             << color(70,30,10)
             << box(7*size_x,6*size_y)
             << color(160,160,160);
        for (int i=0;i<7;i++) {
            for (int j=0;j<6;j++) {
                gout << move_to(pos_x+i*size_x,pos_y)
                     << line_to(pos_x+i*size_x,pos_y+6*size_y)
                     << move_to(pos_x,pos_y+j*size_y)
                     << line_to(pos_x+(i+1)*size_x,pos_y+j*size_y);
            }
        }
        for (size_t k=0;k<7;k++) {
            for (size_t l =0;l<6;l++) {
                for(int i=0; i<70; i++) {
                    for(int j=0; j<70; j++) {
                        if((i-35)*(i-35)+(j-35)*(j-35)<35*35) {
                            if (pegs[k][l] == 0) {gout << color(70,30,10);}
                            if (pegs[k][l] == 1) {gout << color(255,255,0);}
                            if (pegs[k][l] == 2) {gout << color(255,0,0);}
                            gout << move_to(25+i+k*size_x, 155+j+l*size_y)
                                 << dot;
                        }
                    }
                }
            }
        }

        if (!game_is_on && !already_won) {
            gout << color(180,180,180);
        } else if (turn_of_player==1) {
            gout << color(255,255,0);
        } else {
            gout << color(255,0,0);
        }
        for(int i=0; i<50; i++) {
            for(int j=0; j<50; j++) {
                if((i-25)*(i-25)+(j-25)*(j-25)<25*25) {
                    gout << move_to(i+120,j+10)
                         << dot;
                }
            }
        }
        if (already_won) {
            if (_draw) {
                gout.load_font("Not Just Groovy.ttf",40,true);
                gout << move_to(400,50)
                     << color(0,0,0)
                     << text("Result: Draw");
                gout.load_font("Not Just Groovy.ttf",16,true);
            } else {
                string s;
                stringstream SS;
                SS << winner;
                SS >> s;
                if (winner == 1) {gout << color(255,255,0);}
                if (winner == 2) {gout << color(255,0,0);}
                gout.load_font("Not Just Groovy.ttf",40,true);
                gout << move_to(300,50)
                     << text("The winner is: Player "+s);
                gout.load_font("Not Just Groovy.ttf",16,true);
            }
        }
    }
}

void Connect_Four::handle(event ev) {
}

void Connect_Four::drop_peg(int i) {
    int minimum=7;
    ///     Dropping peg
    if (!already_won) {
        for (size_t k=0;k<6;k++) {
            if (pegs[i-1][k] == 0) {
                minimum = k;
            }
        }
        if (minimum<6) {
            pegs[i-1][minimum] = turn_of_player;
            turn_of_player==1?turn_of_player=2:turn_of_player=1;
        }
    }
    ///     Check for draw
    _draw = true;
    for (size_t u=7;u>0;u--) {
        for (size_t v=6;v>0;v--) {
            if (pegs[u][v] == 0) {
                _draw = false;
            }
        }
    }

    ///     Check for win

        cout << i-1 << "|" << minimum << endl;
    if (this->check_for_win(i-1,minimum) && !_draw) {
        cout << i-1 << "|" << minimum << endl;
        if (!already_won) {
            already_won = true;
            winner = pegs[i-1][minimum];
        }
    }

    if (_draw) {
        already_won = true;
    }
}


void Connect_Four::start_game() {
    for (int i=0;i<7;i++) {
        for (int j=0;j<6;j++) {
            pegs[i][j] = 0;
        }
    }
    turn_of_player = 1;
    game_is_on = true;
    already_won = false;
}

bool Connect_Four::check_for_win(int a, int b) {
    int vertical = 1;       /// (|)
    int horizontal = 1;     /// (-)
    int diagonal1 = 1;      /// (\)
    int diagonal2 = 1;      /// (/)
    int player = pegs[a][b];
    int v;
    int h;
    for(v = a + 1;pegs[v][b] == player && v <= 5;v++,vertical++);
    for(v = a - 1;pegs[v][b] == player && v >= 0;v--,vertical++);
    if(vertical >= 4)return true;
    for(h = b - 1;pegs[a][h] == player && h >= 0;h--,horizontal++);
    for(h = b + 1;pegs[a][h] == player && h <= 6;h++,horizontal++);
    if(horizontal >= 4) return true;
    for(v = a - 1, h= b -1;pegs[v][h] == player && v>=0 && h >=0; diagonal1 ++, v --, h --);
    for(v = a + 1, h = b+1;pegs[v][h] == player && v<=5 && h <=6;diagonal1 ++, v ++, h ++);
    if(diagonal1 >= 4) return true;
    for(v = a - 1, h= b +1;pegs[v][h] == player && v>=0 && h <= 6; diagonal2 ++, v --, h ++);
    for(v = a + 1, h= b -1;pegs[v][h] == player && v<=5 && h >=0; diagonal2 ++, v ++, h --);
    if(diagonal2 >= 4) return true;

    return false;
}
