cmake_minimum_required(VERSION 3.29)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessEngine
    main.cpp
        Coordinate.h
        Coordinate.cpp
        Position.h
        Position.cpp
        Move.h
        Move.cpp
        Bishop.h
        Bishop.cpp
        Knight.cpp
        Knight.h
        King.cpp
        King.h
        Rook.h
        Rook.cpp
        Queen.cpp
        Queen.h
        Pawn.h
        Pawn.cpp
)
