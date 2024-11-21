//
// Created by bento on 11/20/2024.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Position.h"


class Bishop {
public:
    Position *position;
    const Coordinate location;
    Bishop(Position *position, const Coordinate &location);

    void getMoves(Move moves[], int &length);
};



#endif //BISHOP_H
