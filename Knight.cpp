//
// Created by Will on 11/20/2024.
//

#include "Knight.h"

Knight::Knight(Position* position, const Coordinate &location): position(position), location(location)  {}


void Knight::getMoves(Move moves[], int &length) {
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
    for (int i = 0; i < 8; i++) {
        if (allEndCoordinates[i].inBounds()) {
            position->getCoordinate(location); // current position
            position->getCoordinate(allEndCoordinates[i]); //this is the possible move
            if(!position->areSameColor(location, allEndCoordinates[i])){
                moves[length] = Move(location, allEndCoordinates[i]);
                length++;
            }


        }
    }
}


