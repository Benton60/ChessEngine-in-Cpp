//
// Created by bento on 11/20/2024.
//

#include "Bishop.h"

#include <iostream>
#include <ostream>

Bishop::Bishop(Position *position, const Coordinate &location): position(position), location(location) {}

void Bishop::getMoves(Move moves[], int &length) {
    // these for loops iterate in a single direction until they hit another piece at which point they will go to the next for loop.
    //positive and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(position->areSameColor(location,endCoordinate)) {
                break;
            }
            if(position->getCoordinate(endCoordinate) != 0){
                moves[length++] = Move(location, endCoordinate);
                break;
            }
            moves[length++] = Move(location, endCoordinate);
        }else {
            break;
        }
    }
    //negative and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(position->areSameColor(location,endCoordinate)) {
                break;
            }
            if(position->getCoordinate(endCoordinate) != 0){
                moves[length++] = Move(location, endCoordinate);
                break;
            }
            moves[length++] = Move(location, endCoordinate);
        }else {
            break;
        }
    }
    //negative and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(position->areSameColor(location,endCoordinate)) {
                break;
            }
            if(position->getCoordinate(endCoordinate) != 0){
                moves[length++] = Move(location, endCoordinate);
                break;
            }
            moves[length++] = Move(location, endCoordinate);
        }else {
            break;
        }
    }
    //positive and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(position->areSameColor(location,endCoordinate)) {
                break;
            }
            if(position->getCoordinate(endCoordinate) != 0){
                moves[length++] = Move(location, endCoordinate);
                break;
            }
            moves[length++] = Move(location, endCoordinate);
        }else {
            break;
        }
    }
}
