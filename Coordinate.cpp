//
// Created by bento on 11/11/2024.
//
/*
this class will hold our coordinate for a piece. anytime you want to specify a square on the chess
board you use this class. Normally we would use getter and setter functions to access the rank and file variables
in the class, but that adds one extra layer of abstraction. Because we will need to access these thousands of times
a second that will slow the engine down. That's why there aren't any getters or setters.
*/
#include "Coordinate.h"

Coordinate::Coordinate(const int file, const int rank) {
    this->rank = rank;
    this->file = file;
}

std::string Coordinate::toString() const {
    return "(" + std::to_string(rank) + "," + std::to_string(file) + ")";
}

bool Coordinate::inBounds() const {
    return (rank >= 0 && rank < 8 && file >= 0 && file < 8);
}
