//
// Created by Will on 11/20/2024.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Position.h"


class Knight {
public:
    Position* position;
    Coordinate location;
    Knight(Position *position, const Coordinate &location);

    void getMoves(Move moves[], int &length);
};



#endif //KNIGHT_H
