#include <iostream>
#include "Coordinate.h"
#include "Position.h"

//
// Created by bento on 11/11/2024.
//


int main() {

    // empty board
    int board[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

    // initializing instance of position class
    Position position = Position(board, Move(Coordinate(0,0), Coordinate(0,0)), 1);

    //beginning of User Interface
    // initial message/directions
    std::cout << "WELCOME TO CHESS ENGINE!!!\n";
    std::cout << "--------------------------\n";
    std::cout << "Enter your chessboard by entering values for each position.\n";
    std::cout << "--> pawns = 100, knights = 300, bishops = 350, rooks = 500, queens = 900, and kings = 10000\n";
    std::cout << "--> NEGATIVE values represent black's pieces & POSITIVE values represent white's pieces\n";
    std::cout << "--> Enter 0 for empty squares\n";
    std::cout << "--> Coordinate (0,0) is the upper left-hand corner of the board & (7,7) is the lower right-hand corner.\n\n";

    // loop to let user enter values for each position
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            std::cout << "Enter value for position (" << rank << ", " << file << "): ";
            std::cin >> board[rank][file];
        }
    }

    // display the updated board to the user
    std::cout << "\n\nThank you for entering your board!\n";
    std::cout << "This is what it looks like:\n";
    std::cout << "------------------------------------------------------------\n";
    position.print();
    std::cout << "------------------------------------------------------------\n";

    // ask for who's turn it is and what depth level to search at
    std::cout << "\nWhich color's turn is it? (enter -1 for black and 1 for white) : ";
    std::cin >> position.color;
    std::cout << "\n";
    std::cout << "How deep do you want to search? (Recommended >= 3)";
    int depth;
    std::cin >> depth;

    // output the best possible move
    std::cout << "\nThe best possible move given this board is:\n";
    std::cout << "------------------------------------------------------------\n";
    Move bestMove = position.getBestMove(depth);
    position.makeMove(bestMove);
    position.print();
    std::cout << "------------------------------------------------------------\n";

    // thank you message
    std::cout << "\nThank you for using our chess engine!\n";

    return 0;

}

//Example Position 1 - Mate in One
//Best Move - (2,3) - (0,3)
//Position - 0 0 0 0 0 -10000 0 0 0 0 0 0 0 0 0 0 0 0 0 500 0 10000 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//Color - 1
//Depth - 3

//Example Position 2 - Mate in Four
//Best Move - (1,3) - (0,3)
//Position - 0 0 0 0 0 -300 -10000 0 0 0 0 500 0 0 0 0 0 0 0 0 0 10000 0 0 0 0 0 0 0 0 0 0 0 0 -100 0 0 0 0 0 0 0 100 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//Color - 1
//Depth - 5