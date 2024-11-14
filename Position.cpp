//
// Created by bento on 11/11/2024.
//

#include "Position.h"

#include <iostream>

Position::Position(int (&board)[8][8], Move lastMove, int color): board(board), lastMove(lastMove), color(color) {}


void Position::print() {
    for (const auto & i : board) {
        for (const int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
//this will get all the possible moves for the position
//this should only return legal moves
void Position::getLegalMoves(Move moves[]) {

    for(int i =0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            switch(abs(board[i][j])) { // the absolute value means that our switch case can be half as long we just need to calculate the color in each case then.
                case 100: //pawn
                    //TODO -- implement the pawn's getMoves
                    break;
                case 300: //Knight
                    //TODO -- implement the Knight's getMoves function
                    break;
                case 350: //bishop
                    //TODO -- implement the bishop's getMoves function
                    break;
                case 500: //rook
                    //TODO -- implement the rook's getMoves function
                    break;
                case 900: //queen
                    //TODO -- implement the queen's getMoves function
                    break;
                case 10000: //king
                    //TODO -- implement the king's getMoves function
                    break;
                default: //empty square
                    break;
            }
        }
    }
}
