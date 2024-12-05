//
// Created by bento on 11/21/2024.
//

#ifndef PAWN_H
#define PAWN_H
#include "Position.h"

//this class holds all our Pawn logic
class Pawn {
public:
    //this allows us to access the chessboard from within the Pawn class
    Position *position;
    //This holds the location of the pawn
    const Coordinate &location;

    Pawn(Position *position, const Coordinate &location);

    //adds the pawns legal moves to moves[] and adjusts length accordingly
    void getMoves(Move moves[], int &length);

};



#endif //PAWN_H
