//
// Created by bento on 11/21/2024.
//

#ifndef ROOK_H
#define ROOK_H
#include "Position.h"


class Rook {
public:
    Position *position;
    const Coordinate &location;
    Rook(Position *position, const Coordinate &location);

    void getMoves(Move moves[], int &length);
};



#endif //ROOK_H
