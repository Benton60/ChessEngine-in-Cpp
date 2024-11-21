//
// Created by Trine on 11/21/2024.
//

#include "King.h"


King::King(Position* position, const Coordinate &location): position(position), location(location)  {}


void King::getMoves(Move moves[], int &length) {
    Coordinate allEndCoordinates[] = {
        Coordinate(location.file-1, location.rank+1),
        Coordinate(location.file+0, location.rank+1),
        Coordinate(location.file+1, location.rank+1),
        Coordinate(location.file+1, location.rank+0),
        Coordinate(location.file+1, location.rank-1),
        Coordinate(location.file+0, location.rank-1),
        Coordinate(location.file-1, location.rank-1),
        Coordinate(location.file-1, location.rank+0),
    };
    for (int i = 0; i < 8; i++) {
        if (allEndCoordinates[i].inBounds()) {
            position->getCoordinate(location); // current position
            position->getCoordinate(allEndCoordinates[i]); // this is the possible move
            if(!position->areSameColor(location, allEndCoordinates[i])){
                moves[length] = Move(location, allEndCoordinates[i]);
                length++;
            }


        }
    }
}