//
// Created by marvi on 22.03.2023.
//

#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include "Functions.h"
#include "Structures.h"

typedef std::vector<std::vector<std::string>> datatype;



class Functions {
private:
    datatype map = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};;

public:
    Functions();
    void print();


    std::string decoder (int pos);
    std::vector<int> encoder(int pos);

    datatype setSymbol();
    datatype setSymbol(int pos);

    bool checker(std::string symbol);



};



#endif //UNTITLED_FUNCTIONS_H
