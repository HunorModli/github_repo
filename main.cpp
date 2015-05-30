#include "graphics.hpp"
#include "widget.h"
#include "window.h"
#include "button.h"
#include "statictext.h"
#include "connect_four.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace genv;
using namespace std;

class MyWindow : public Window {

public:

    Connect_Four * game_board;
    Button * btn_column_1;
    Button * btn_column_2;
    Button * btn_column_3;
    Button * btn_column_4;
    Button * btn_column_5;
    Button * btn_column_6;
    Button * btn_column_7;
    Button * btn_new;
    Button *button_escape;
    StaticText * text_1;
    StaticText * text_2;
    StaticText * text_3;

    MyWindow(int X, int Y) : Window(X,Y) {

    game_board = new Connect_Four(20, 150, 80, 80);
    btn_column_1 = new Button(20, 100,80,50,[&](){game_board->drop_peg(1);},"column 1");
    btn_column_2 = new Button(100,100,80,50,[&](){game_board->drop_peg(2);},"column 2");
    btn_column_3 = new Button(180,100,80,50,[&](){game_board->drop_peg(3);},"column 3");
    btn_column_4 = new Button(260,100,80,50,[&](){game_board->drop_peg(4);},"column 4");
    btn_column_5 = new Button(340,100,80,50,[&](){game_board->drop_peg(5);},"column 5");
    btn_column_6 = new Button(420,100,80,50,[&](){game_board->drop_peg(6);},"column 6");
    btn_column_7 = new Button(500,100,80,50,[&](){game_board->drop_peg(7);},"column 7");
    button_escape = new Button(850,0,50,30,[&](){this->terminate();},"ESC");

    btn_new = new Button(750,200,100,60,[&](){game_board->start_game();},"NEW GAME");

    text_1 = new StaticText(20,6,0,0,255,255,255,"Player turn:",16);
    text_2 = new StaticText(400,0,0,0,30,0,255,"4 in a ROW",30);
    text_3 = new StaticText(600,200,0,0,30,0,255,"Start a new game: ",16);


    widgets.push_back(btn_column_1);
    widgets.push_back(btn_column_2);
    widgets.push_back(btn_column_3);
    widgets.push_back(btn_column_4);
    widgets.push_back(btn_column_5);
    widgets.push_back(btn_column_6);
    widgets.push_back(btn_column_7);
    widgets.push_back(button_escape);
    widgets.push_back(btn_new);
    widgets.push_back(text_1);
    widgets.push_back(text_2);
    widgets.push_back(text_3);
    widgets.push_back(game_board);
    }
};


int main() {
    MyWindow *mywindow = new MyWindow(900,650);
    mywindow->event_loop();
    return 0;
}
