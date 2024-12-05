//
// Created by Will on 11/21/2024.
//

#ifndef QUEEN_H
#define QUEEN_H
#include "Position.h"
//this class holds all our Queen logic
class Queen {
    public:
        //this allows us to access the chessboard from within the Queen class
        Position* position;
        //holds this queens position
        Coordinate location;
        Queen(Position *position, const Coordinate &location);

        //adds all the moves the queen can make to moves[] and adjusts length accordingly
        void getMoves(Move moves[], int &length);
};

#endif //QUEEN_H
