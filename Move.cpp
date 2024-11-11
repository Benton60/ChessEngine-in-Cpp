//
// Created by bento on 11/11/2024.
//

/*
 *This class will be used to pass around potential moves. It stores the start and end coordinates so that they can
 *easily be checked for legality.
 *There are no getters or setters because that requires an extra level of abstraction which slows the engine down.
*/
#include "Move.h"

Move::Move(Coordinate start, Coordinate end): start(-1,-1), end(-1,-1) {
    this->start = start;
    this->end = end;
}
