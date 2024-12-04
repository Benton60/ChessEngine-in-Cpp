#include <iostream>
#include "Coordinate.h"
#include "Position.h"

//
// Created by bento on 11/11/2024.
//


int main() {
    //this board is the start position we can use it to test our move generation functions.
    int board2[8][8] = {
        //
        {500,300,350,900,10000,350,300,500},
        {100,100,100,100,100,100,100,100},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {-100, -100,-100,-100,-100,-100,-100,-100},
        {-500,-300,-350,-900,-10000,-350,-300,-500}
    };
    int board[8][8] = {
        {0,0,0,10000,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,-300,0,0,0,0,0,0},
        {0,-350,-350,0,-350,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

    Move moves[50];
    Position position = Position(board2, Move(Coordinate(0,0), Coordinate(0,0)), 1);



    // initial message/directions
    std::cout << "WELCOME TO CHESS ENGINE!!!\n";
    std::cout << "--------------------------\n";
    std::cout << "Enter your chessboard by entering values for each position.\n";
    std::cout << "--> pawns = 100, knights = 300, bishops = 350, rooks = 500, queens = 900, and kings = 10000\n";
    std::cout << "--> NEGATIVE values represent black's pieces & POSITIVE numbers represent white's pieces\n";
    std::cout << "--> Enter 0 for empty squares\n";
    std::cout << "--> Coordinate (0,0) is the upper left-hand corner of the board & (7,7) is the lower right-hand corner.\n\n";

    // loop to let user to enter values for each position
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            std::cout << "Enter value for position (" << rank << ", " << file << "): ";
            std::cin >> board[rank][file];
        }
    }

    // display the updated board to the user
    std::cout << "\nThank you for entering your board!\n";
    std::cout << "This is what it looks like...\n";
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            std::cout << board[rank][file] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nWhich color's turn is it? (enter -1 for black and 1 for white) : \n";
    std::cin >> position.color;
    std::cout << "\nThe best possible move given this board is" << position.getBestMove(6).toString() << std::endl;

    return 0;

}

