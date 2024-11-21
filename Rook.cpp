//
// Created by bento on 11/21/2024.
//

#include "Rook.h"

Rook::Rook(Position *position, const Coordinate &location): position(position), location(location) {}




void Rook::getMoves(Move moves[], int &length) {
    //rank positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank + i);
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
    //rank negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank - i);
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
    //file positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank);
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
    //file negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank);
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
