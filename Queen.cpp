//
// Created by Will on 11/21/2024.
//

#include "Queen.h"
Queen::Queen(Position *position, const Coordinate &location): position(position), location(location) {}

// this is a predetermined list of all possible queen moves... basically just a combination of rook and bishop
void Queen::getMoves(Move moves[], int &length) {
    //see rook/bishop classes to see how these for loops work
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
