//
// Created by bento on 11/11/2024.
//

#include "Position.h"
#include <iostream>
#include <set>

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
void Position::getLegalMoves(Move moves[]){
    for(int i =0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]*color) { // the absolute value means that our switch case can be half as long we just need to calculate the color in each case then.
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

//this adds up all the piece values on the board in the position.
double Position::getEvaluation() {
    double sum = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            sum += board[i][j];
        }
    }
    return sum;
}

//takes a move and makes it on the board
void Position::makeMove(Move &move) {
    //this line of code saves whatever value is in the end coordinate of the move so that it can be restored if the move is unmade
    move.capturedPiece = getCoordinate(move.end);
    setCoordinate(move.end, getCoordinate(move.start));
    setCoordinate(move.start, 0);
    color*=-1;
}
//takes a move and unmakes it on the board
void Position::unMakeMove(Move &move) {
    setCoordinate(move.start, getCoordinate(move.end));
    setCoordinate(move.end, move.capturedPiece);
    color*=-1;
}


//please use these functions to access coordinates of the board it can be kind of tricky because accessing the array is backwards from how it makes sense in our heads.
int Position::getCoordinate(const Coordinate &coordinate) {
    return board[coordinate.rank][coordinate.file];
}
void Position::setCoordinate(const Coordinate &coordinate, const int &piece) {
    board[coordinate.rank][coordinate.file] = piece;
}
bool Position::areSameColor(const Coordinate &first, const Coordinate &second) {
    if(getCoordinate(first) > 0 && getCoordinate(second) > 0) {
        return true;
    }
    if(getCoordinate(first) < 0 && getCoordinate(second) < 0) {
        return true;
    }
    return false;
}
