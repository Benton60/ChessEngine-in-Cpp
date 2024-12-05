//
// Created by bento on 11/21/2024.
//

#ifndef ROOK_H
#define ROOK_H
#include "Position.h"

//this class holds all our Rook piece logic
class Rook {
public:
    //this allows us to access the chessboard from within the Rook class
    Position *position;
    //stores the rooks location on the board
    const Coordinate &location;
    Rook(Position *position, const Coordinate &location);

    //adds all the rooks legal moves to moves[]
    void getMoves(Move moves[], int &length);
};



#endif //ROOK_H
