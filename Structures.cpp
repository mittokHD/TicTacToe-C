//
// Created by Shirley Luszas on 06.04.2023.
//

#include "Structures.h"

std::ostream &operator<<(std::ostream &strm, const Structures &a)
{
    switch (a)
    {
        case Structures::PLAYER:
            return strm << "O";
        case Structures::COMP:
            return strm << "X";
        case Structures::CLEAR:
            return strm << "";
        default:
            return strm << "EMPTY";
    }
}