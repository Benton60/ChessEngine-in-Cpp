//
// Created by bento on 11/11/2024.
//

#include "Position.h"
#include <iostream>
#include <set>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

Position::Position(int (&board)[8][8], Move lastMove, int color): board(board), lastMove(lastMove), color(color) {}


void Position::print() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            std::cout << board[rank][file] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "Color = " << color << ", LastMove = " << lastMove.toString() << std::endl;
}

//this will get all the possible moves for the position
//this should only return legal moves
int Position::getLegalMoves(Move moves[]){
    Move allLegalMoves[50];
    int length = 0, finalLength = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]*color) { // the absolute value means that our switch case can be half as long we just need to calculate the color in each case then.
                case 100: //pawn
                    Pawn(this, Coordinate(j,i)).getMoves(allLegalMoves, length);
                    break;
                case 300: //Knight
                    Knight(this, Coordinate(j, i)).getMoves(allLegalMoves, length);
                    break;
                case 350: //bishop
                    Bishop(this, Coordinate(j, i)).getMoves(allLegalMoves, length);
                    break;
                case 500: //rook
                    Rook(this, Coordinate(j, i)).getMoves(allLegalMoves, length);
                    break;
                case 900: //queen
                    Queen(this, Coordinate(j, i)).getMoves(allLegalMoves, length);
                    break;
                case 10000: //king
                    King(this, Coordinate(j, i)).getMoves(allLegalMoves, length);
                    break;
                default: //empty square
                    break;
            }
        }
    }

    for(int i = 0; i < length; i++) {
        if(!checkForKingDanger(allLegalMoves[i])) {
            moves[finalLength++] = allLegalMoves[i];
        }
    }
    return finalLength;
}
//this checks whether the king can be captured after the move is made
bool Position::checkForKingDanger(Move &move) {

    makeMove(move);
    Coordinate location = findKingPosition();

    //KNIGHT
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
        if (allEndCoordinates[i].inBounds() && getCoordinate(allEndCoordinates[i]) == 300*color) {
            unMakeMove(move);
            return true;
        }
    }

    //ROOK AND QUEEN
    //rank positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //rank negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //file positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //file negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }

    //BISHOP AND QUEEN
    //positive and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //negative and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //negative and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }
    //positive and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                unMakeMove(move);
                return true;
            }
        }else {
            break;
        }
    }

    unMakeMove(move);
    return false;
}
//this checks if the current position can be captured
bool Position::checkForKingDanger() {
    Coordinate location = findKingPosition();
    //KNIGHT
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
        if (allEndCoordinates[i].inBounds() && getCoordinate(allEndCoordinates[i]) == 300*color) {
            return true;
        }
    }

    //ROOK AND QUEEN
    //rank positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //rank negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //file positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //file negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 500*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }

    //BISHOP AND QUEEN
    //positive and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //negative and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //negative and positive
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file - i, location.rank + i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    //positive and negative
    for(int i = 1; i < 7; i++) {
        Coordinate endCoordinate = Coordinate(location.file + i, location.rank - i);
        if(endCoordinate.inBounds()) {
            if(areSameColor(location,endCoordinate)) {
                break;
            }
            if(getCoordinate(endCoordinate) == 350*color || getCoordinate(endCoordinate) == 900*color)  {
                return true;
            }
        }else {
            break;
        }
    }
    return false;
}
//this adds up all the piece values on the board in the position.
double Position::getEvaluation() {
    double sum = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            sum += board[i][j];
        }
    }
    return sum;
}
//takes a move and makes it on the board
void Position::makeMove(Move &move) {
    //this line of code saves whatever value is in the end coordinate of the move so that it can be restored if the move is unmade
    move.capturedPiece = getCoordinate(move.end);
    move.capturingPiece = getCoordinate(move.start);
    setCoordinate(move.end, move.capturingPiece);
    setCoordinate(move.start, 0);
    this->lastMove = move;

    //this is the promotion for white
    if(move.end.rank == 7 && getCoordinate(move.end) == 100) {
        setCoordinate(move.end, 900);
    }
    //this is the promotion for white
    if(move.end.rank == 0 && getCoordinate(move.end) == -100) {
        setCoordinate(move.end, -900);
    }
    color*=-1;
}
//takes a move and unmakes it on the board
void Position::unMakeMove(Move &move) {
    setCoordinate(move.start, move.capturingPiece);
    setCoordinate(move.end, move.capturedPiece);
    color*=-1;
}
//please use these functions to access coordinates of the board it can be kind of tricky because accessing the array is backwards from how it makes sense in our heads.
int Position::getCoordinate(const Coordinate &coordinate) {
    return board[coordinate.rank][coordinate.file];
}
void Position::setCoordinate(const Coordinate &coordinate, const int &piece) {
    board[coordinate.rank][coordinate.file] = piece;
}
//simple function to determine whether two squares hold pieces of the same color
bool Position::areSameColor(const Coordinate &first, const Coordinate &second) {
    if(getCoordinate(first) > 0 && getCoordinate(second) > 0) {
        return true;
    }
    if(getCoordinate(first) < 0 && getCoordinate(second) < 0) {
        return true;
    }
    return false;
}
Coordinate Position::findKingPosition() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == -10000*color) {
                return Coordinate(j,i);
            }
        }
    }
    return Coordinate();
}
Move Position::getBestMove(int depth) {
    Move moves[50];
    Move bestMove;
    int bestMoveEvaluation = -100000000;
    int length = this->getLegalMoves(moves);
    for(int i = 0; i < length; i++) {

        this->makeMove(moves[i]);
        int currentEval = this->search(depth-1);
        //this keeps track of the best move that has been found so far.
        if (currentEval > bestMoveEvaluation) {
            bestMoveEvaluation = currentEval;
            bestMove = moves[i];
        }
        this->unMakeMove(moves[i]);
    }
    return bestMove;
}

//this is the vanilla search evaluation function without any extra optimization.
int Position::search(int depth) {
    //if we have reached the end of our depth then we return the static evaluation.
    if (depth <= 0) {
        return this->getEvaluation();
    }
    //otherwise we get the moves in the position.
    Move moves[50];
    int length = this->getLegalMoves(moves);
    //check that there are available moves
    if (length <= 0) {
        //if there aren't any and the king is in danger then it is checkmate
        this->color *= -1; //this line switches the color to check the opposing kings danger not our own
        if (checkForKingDanger()) {
            this->color *= -1; //this line switches the color to check the opposing kings danger not our own
            return 1000000;
        }
        this->color *= -1; //this line switches the color to check the opposing kings danger not our own
        //otherwise it is stalemate which evaluates to 0
        return 0;
    }

    int worstMoveEvaluation = 100000000;
    for(int i = 0; i < length; i++) {
        this->makeMove(moves[i]);
        //this negative sign is very important because it flips the eval for black and white
        int currentEval = -this->search(depth-1);

        //we pick the evaluation that is closest to zero because that is what the opponent will always choose.
        if (currentEval < worstMoveEvaluation) {
            worstMoveEvaluation = currentEval;
        }
        this->unMakeMove(moves[i]);
    }
    return worstMoveEvaluation;
}

