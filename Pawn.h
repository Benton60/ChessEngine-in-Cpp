//
// Created by bento on 11/21/2024.
//

#ifndef PAWN_H
#define PAWN_H
#include "Position.h"


class Pawn {
public:
    Position *position;
    const Coordinate &location;
    Pawn(Position *position, const Coordinate &location);


    void getMoves(Move moves[], int &length);

};



#endif //PAWN_H
