#include <iostream>
#include "Coordinate.h"
#include "Position.h"

//
// Created by bento on 11/11/2024.
//


int main() {
    //this board is the start position we can use it to test our move generation functions.
    int board2[8][8] = {
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
    int board[8][8] = {
        {0,0,0,10000,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,-300,0,0,0,0,0,0},
        {0,-350,-350,0,-350,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };
    int startTime = time(NULL);
    Move moves[50];
    Position position = Position(board2, Move(Coordinate(0,0), Coordinate(0,0)), 1);

    position.getBestMove(6);



    // int length = position.getLegalMoves(moves);
    // int totalLength = 0;
    // for (int i = 0; i < length; i++) {
    //     Move subMoves[50];
    //     position.makeMove(moves[i]);
    //     int currlength = position.getLegalMoves(subMoves);
    //     for(int j = 0; j < currlength; j++) {
    //         Move subsubMoves[50];
    //         position.makeMove(subMoves[j]);
    //         int currcurrLength = position.getLegalMoves(subsubMoves);
    //         totalLength += currcurrLength;
    //         position.unMakeMove(subMoves[j]);
    //     }
    //     //std::cout << moves[i].toString() << " : " << totalLength << " : " <<  currlength << " : " << position.color << std::endl;
    //     position.unMakeMove(moves[i]);
    //
    // }
    // //std::cout << Move::toString(moves);
    // int endTime = time(NULL);
    // std::cout << "Total Moves: " << totalLength << " : " << endTime - startTime << " milliseconds" << std::endl;

    //right now it should ouput 8902 for totalPositions
}