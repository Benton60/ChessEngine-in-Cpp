//
// Created by Will on 11/21/2024.
//

#ifndef KING_H
#define KING_H
#include "Position.h"



class King {
public:
    Position* position;
    Coordinate location;
    King(Position *position, const Coordinate &location);

    void getMoves(Move moves[], int &length);
};



#endif //KING_H