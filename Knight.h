//
// Created by Will on 11/20/2024.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Position.h"

//holds all our logic used for interacting with knight pieces
class Knight {
public:
    //this lets us access the board from the position where the knight was created
    Position* position;
    //this holds the location of the knight on the chess board
    Coordinate location;
    Knight(Position *position, const Coordinate &location);
    //adds all the legal knight moves to moves[] and adjusts length accordingly
    void getMoves(Move moves[], int &length);
};



#endif //KNIGHT_H
