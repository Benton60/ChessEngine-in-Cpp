//
// Created by bento on 11/20/2024.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Position.h"

//the bishop class holds our bishop's getMove Function
class Bishop {
public:
    //this stores the position from which the bishop class is created. We use this so we can access the board from inside the bishop class
    Position *position;
    //this coordinate is the coordinate of the bishop we are getting moves for
    const Coordinate location;
    Bishop(Position *position, const Coordinate &location);

    void getMoves(Move moves[], int &length);
};



#endif //BISHOP_H
