//
// Created by bento on 11/21/2024.
//

#include "Pawn.h"

#include <iostream>


Pawn::Pawn(Position *position, const Coordinate &location): position(position), location(location) {}

void Pawn::getMoves(Move moves[], int &length) {

    //if the pawn is white it has different moves that the black pawns
    if (position->getCoordinate(location) > 0) { //white pawns
        Coordinate upOne = Coordinate(location.file,location.rank + 1);
        Coordinate upTwo = Coordinate(location.file,location.rank + 2);
        Coordinate captureLeft = Coordinate(location.file -1,location.rank + 1);
        Coordinate captureRight = Coordinate(location.file + 1,location.rank + 1);
        if(upOne.inBounds() && position->getCoordinate(upOne) == 0) {
            moves[length++] = Move(location, upOne);
            if(upTwo.inBounds() && position->getCoordinate(upTwo) == 0 && location.rank == 1) {
                moves[length++] = Move(location, upTwo);
            }
        }
        if(captureLeft.inBounds() && position->getCoordinate(captureLeft) < 0) {
            moves[length++] = Move(location, captureLeft);
        }
        if(captureRight.inBounds() && position->getCoordinate(captureRight) < 0) {
            moves[length++] = Move(location, captureRight);
        }


        //En-pessant

        if(position->getCoordinate(position->lastMove.end) == -100 //Checks whether the last move was a black pawn
            && position->lastMove.end.rank - position->lastMove.start.rank == -2 //checks that the pawn moved two spaces
            && abs(position->lastMove.end.file - location.file) == 1 //checks that it is on either side of the current pawn
            && position->lastMove.end.rank == location.rank) {
            moves[length++] = Move(location, Coordinate(position->lastMove.end.file, position->lastMove.end.rank+1));
        }

    //we're finished with white pawn logic now it is black pawns turn
    }else { //black pawns
        //these are the predetermined available moves for pawns
        Coordinate upOne = Coordinate(location.file,location.rank - 1);
        Coordinate upTwo = Coordinate(location.file,location.rank - 2);
        Coordinate captureLeft = Coordinate(location.file -1,location.rank - 1);
        Coordinate captureRight = Coordinate(location.file + 1,location.rank - 1);
        //

        //checks all the moves to see if they apply to this board.
        if(upOne.inBounds() && position->getCoordinate(upOne) == 0) {
            moves[length++] = Move(location, upOne);
            if(upTwo.inBounds() && position->getCoordinate(upTwo) == 0 && location.rank == 6) {
                moves[length++] = Move(location, upTwo);
            }
        }
        if(captureLeft.inBounds() && position->getCoordinate(captureLeft) > 0) {
            moves[length++] = Move(location, captureLeft);
        }
        if(captureRight.inBounds() && position->getCoordinate(captureRight) > 0) {
            moves[length++] = Move(location, captureRight);
        }



        //En-pessant
        if(position->getCoordinate(position->lastMove.end) == 100 //Checks whether the last move was a black pawn
            && position->lastMove.end.rank - position->lastMove.start.rank == 2 //checks that the pawn moved two spaces
            && abs(position->lastMove.end.file - location.file) == 1 //checks that it is on either side of the current pawn
             && position->lastMove.end.rank == location.rank
             ) {
            moves[length++] = Move(location, Coordinate(position->lastMove.end.file, position->lastMove.end.rank-1));
            }
    }
}

