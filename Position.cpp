//
// Created by bento on 11/11/2024.
//

#include "Position.h"

Position::Position(int (&board)[8][8], Move lastMove, int color): board(board), lastMove(lastMove), color(color) {}