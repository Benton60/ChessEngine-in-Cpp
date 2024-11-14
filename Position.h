//
// Created by bento on 11/11/2024.
//


/*
 *this class will hold a full position of the chess board, including the piece location,
 *who's turn it is(color), and the last move that was made.
 *
 *
 *
*/
#ifndef POSITION_H
#define POSITION_H
#include "Move.h"


class Position {
  public:
    int (&board)[8][8];
    //should be -1 for black,and 1 for white
    int color = 0;
    //the lastMove is needed for en-pessant-ing pawns
    Move lastMove;
    Position(int (&board)[8][8], Move lastMove, int color);
    void print();

};


#endif //POSITION_H
