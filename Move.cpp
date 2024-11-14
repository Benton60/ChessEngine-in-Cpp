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
Move::Move(): start(0,0), end(0,0) {
}


std::string Move::toString() {
    return start.toString() + " " + end.toString();
}

std::string Move::toString(Move moves[]) {
    std::string result = "";
    for(int i = 0; i < 50; i++) {
        result += moves[i].toString() + "\n";
    }
    return result;
}
