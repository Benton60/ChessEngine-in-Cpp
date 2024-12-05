//
// Created by bento on 11/11/2024.
//


/*
 *this class will hold a full position of the chess board, including the piece location,
 *who's turn it is(color), and the last move that was made.
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

    //outputs the position class in a nice format
    void print();


    //adds all the legal moves to the moves[] array
    int getLegalMoves(Move moves[]);

    //this checks whether the king is in check. It first makes the move it is passed then checks
    bool checkForKingDanger(Move &move);
    //this checks whether the king is in check. It runs on the position as is, without making any moves
    bool checkForKingDanger();

    //returns a double value that represents the evaluation for a position
    double getEvaluation();
    //takes a move and makes it on the board
    void makeMove(Move &move);
    //takes a move and un-makes it
    void unMakeMove(Move &move);

    //used to access coordinates on the chess board
    int getCoordinate(const Coordinate &coordinate);
    void setCoordinate(const Coordinate &coordinate, const int &piece);

    //we use this function to check whether two squares hold the same color piece. It helps when determining whether a move is legal
    bool areSameColor(const Coordinate &first, const Coordinate &second);

    //this is used by the checkForKingDanger functions to find the king position
    Coordinate findKingPosition();

    //this is the Master function if you will. It is what you call on an instance of position to find the best move.
    Move getBestMove(int depth);

    //this is a helper function to the getBestMove. It uses recursion to search to a depth.
    int search(int depth);
};


#endif //POSITION_H
