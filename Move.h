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
        Coordinate start;
        Coordinate end;

        Move(Coordinate start, Coordinate end);
        Move();
        std::string toString();

};



#endif //MOVE_H
