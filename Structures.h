//
// Created by Shirley Luszas on 06.04.2023.
//

#pragma once

#include <ostream>

enum class Structures {
    PLAYER,
    COMP,
    CLEAR
};

std::ostream &operator<<(std::ostream &strm, const Structures &a);

