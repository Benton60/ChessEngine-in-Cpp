//
// Created by bento on 11/11/2024.
//

/*
 *This class will be used to pass around potential moves. It stores the start and end coordinates so that they can
 *easily be checked for legality.
 *There are no getters or setters because that requires an extra level of abstraction which slows the engine down.
*/
#ifndef MOVE_H
#define MOVE_H
#include "Coordinate.h"


class Move {
    public:
        //this holds the start square of the move
        Coordinate start;
        //this holds the end square where the piece will end up
        Coordinate end;

        //these are used when the Position::unMakeMove function is called to unmake a move.
        int capturingPiece;
        int capturedPiece;
        //

        Move(Coordinate start, Coordinate end);
        Move();
        //this returns all the variables from the move class in a nice format to be printed
        std::string toString();
        static std::string toString(Move moves[]);
};



#endif //MOVE_H
