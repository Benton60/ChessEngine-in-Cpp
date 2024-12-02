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


    //adds all the legal moves to the moves[] array
    int getLegalMoves(Move moves[]);
    bool checkForKingDanger(Move &move);

    bool checkForKingDanger();

    //returns a double value that represents the evaluation for a position
    double getEvaluation();
    //takes a move and makes it on the board
    void makeMove(Move &move);
    void unMakeMove(Move &move);
    //used to access coordinates on the chess board
    int getCoordinate(const Coordinate &coordinate);
    void setCoordinate(const Coordinate &coordinate, const int &piece);
    bool areSameColor(const Coordinate &first, const Coordinate &second);
    Coordinate findKingPosition();
    Move getBestMove(int depth);

    int search(int depth);

    int search(int depth, int alpha, int beta);
};


#endif //POSITION_H
