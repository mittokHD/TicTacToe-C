//
// Created by marvi on 22.03.2023.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include "Structures.h"

typedef std::vector<std::vector<Structures>> datatype;



class Map {
private:
    datatype map;

public:
    Map();
    void print();


    Structures decoder (int pos);
    std::vector<int> encoder(int pos);

    void setSymbol();
    void setSymbol(int pos);

    bool checker(Structures symbol);
    void checkWhoWon(bool test, bool test1);
};



#endif //UNTITLED_MAP_H
