//
// Created by Will on 11/21/2024.
//

#ifndef QUEEN_H
#define QUEEN_H
#include "Position.h"

class Queen {
    public:
        Position* position;
        Coordinate location;
        Queen(Position *position, const Coordinate &location);

        void getMoves(Move moves[], int &length);
};

#endif //QUEEN_H
