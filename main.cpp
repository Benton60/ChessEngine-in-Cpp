#include <iostream>
#include "Coordinate.h"
#include "Position.h"

//
// Created by bento on 11/11/2024.
//


int main() {
    //this board is the start position we can use it to test our move generation functions.
    int board[8][8] = {
        //
        {500,300,350,900,10000,350,300,500},
        {100,100,100,100,100,100,100,100},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {-100, -100,-100,-100,-100,-100,-100,-100},
        {-500,-300,-350,-900,-10000,-350,-300,-500}
    };
    Move moves[50];

    Position position = Position(board, Move(Coordinate(0,0), Coordinate(0,0)), -1);
    position.getLegalMoves(moves);
    std::cout << Move::toString(moves);




}