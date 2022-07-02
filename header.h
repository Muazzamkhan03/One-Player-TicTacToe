#ifndef HEADER
#define HEADER

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define Player 1
#define Computer 2

class XO{
    int board[3][3];
    int turn;
    int isGameover;
    void playGame();


    public:
        void startGame();
        void drawBoard();
        int compMove();
        void checkWin();
        void Move(int);
        void gameLoop();


};

#endif