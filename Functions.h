//
// Created by marvi on 22.03.2023.
//

#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <random>

typedef std::vector<std::vector<std::string>> datatype;

class Functions {
public:
    Functions();
    datatype map;
    void toString();
    datatype createMap();
    std::string decoder (int pos);
    std::vector<int> encoder(int pos);
    datatype setSymbol();
    datatype setSymbol(int pos);
    bool checker(std::string symbol);
};

#endif //UNTITLED_FUNCTIONS_H
