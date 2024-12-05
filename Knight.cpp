//
// Created by Will on 11/20/2024.
//

#include "Knight.h"

Knight::Knight(Position* position, const Coordinate &location): position(position), location(location)  {}

void Knight::getMoves(Move moves[], int &length) {

    // this is a predetermined list of all possible knight moves
    Coordinate allEndCoordinates[] = {
        Coordinate(location.file+2, location.rank-1),
        Coordinate(location.file+2, location.rank+1),
        Coordinate(location.file+1, location.rank-2),
        Coordinate(location.file+1, location.rank+2),
        Coordinate(location.file-1, location.rank-2),
        Coordinate(location.file-1, location.rank+2),
        Coordinate(location.file-2, location.rank-1),
        Coordinate(location.file-2, location.rank+1),
    };
    // adds all the moves that are actually legal
    for (int i = 0; i < 8; i++) {
        if (allEndCoordinates[i].inBounds()) {
            if(!position->areSameColor(location, allEndCoordinates[i])){
                moves[length] = Move(location, allEndCoordinates[i]);
                length++;
            }

        }
    }
}


