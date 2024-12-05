//
// Created by bento on 11/11/2024.
//

/*
this class will hold our coordinate for a piece. anytime you want to specify a square on the chess
board you use this class. Normally we would use getter and setter functions to access the rank and file variables
in the class, but that adds one extra layer of abstraction. Because we will need to access these thousands of times
a second that will slow the engine down. That's why there aren't any getters or setters.
*/

#ifndef COORDINATE_H
#define COORDINATE_H
#include <string>

class Coordinate {
public:
    int rank;
    int file;
    Coordinate(int file, int rank);
    Coordinate();
    //this gives a representation like this "(R,F)" to make it easier to print the contents of a coordinate.
    std::string toString() const;
    //checks whether the coordinate falls within the eight by eight chessboard
    bool inBounds() const;
};



#endif //COORDINATE_H
