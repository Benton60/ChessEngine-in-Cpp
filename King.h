//
// Created by Will on 11/21/2024.
//

#ifndef KING_H
#define KING_H
#include "Position.h"


//this holds all our king logic
class King {
public:
    //stores the position class from which the King is created. it lets us access the board from within the king class
    Position* position;
    //holds the kings location
    Coordinate location;
    King(Position *position, const Coordinate &location);
    //adds all the kings moves to the moves[] and increases length accordingly
    void getMoves(Move moves[], int &length);
};



#endif //KING_H