#include "Functions.h"
#include "Structures.h"
using std::string;
using std::cout;
using std::endl;

Functions::Functions() {
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            map[x][y] = Structures::CLEAR;
        }
    }
}

void Functions::print() {
    for(int x = 0; x<map.size(); x++){
        for(int y = 0; y<map.size(); y++){
            cout << map[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

std::string Functions::decoder(int pos){
    switch (pos) {
        case 1:
            return map.at(0).at(0);
        case 2:
            return map.at(0).at(1);
        case 3:
            return map.at(0).at(2);
        case 4:
            return map.at(1).at(0);
        case 5:
            return map.at(1).at(1);
        case 6:
            return map.at(1).at(2);
        case 7:
            return map.at(2).at(0);
        case 8:
            return map.at(2).at(1);
        case 9:
            return map.at(2).at(2);
        default:
            return "ERROR. Number out of bounce.";
    }
}

std::vector<int> Functions::encoder(int pos){
    switch (pos) {
        case 1:
            return {0,0};
        case 2:
            return {0,1};
        case 3:
            return {0,2};
        case 4:
            return {1,0};
        case 5:
            return {1,1};
        case 6:
            return {1,2};
        case 7:
            return {2,0};
        case 8:
            return {2,1};
        case 9:
            return {2,2};
        default:
            return {};
    }
}

datatype Functions::setSymbol() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1,9);
    int pos = dist(rd);
    while (decoder(pos) == "X" || decoder(pos) == "O"){
         pos = dist(rd);
    }
    std::vector encoded = encoder(pos);
    map[encoded[0]][encoded[1]] = "O";
    return map;
}

datatype Functions::setSymbol(int pos) {
    while (decoder(pos) == "X" || decoder(pos) == "O"){
        cout << "Error. Bereits belegt. Gib ein neues Feld ein";
        std::cin >> pos;
    }
    std::vector encoded = encoder(pos);
    map[encoded[0]][encoded[1]] = "X";
    return map;
}

bool Functions::checker(string symbol) {
    int counter = 0;
    for (int i = 0; i < 3; i++){
        if (map[i][i] == symbol){
            counter = counter + 1;
        }
        if (counter == 3){
            return false;
        }
    }
    counter = 0;
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            if (map[x][y] == symbol){
                counter = counter + 1;
            }
            if (counter == 3){
                return false;
            }
        }
        counter = 0;
    }
    for(int y = 0; y<3; y++){
        for(int x = 0; x<3; x++){
            if (map[x][y] == symbol){
                counter = counter + 1;
            }
            if (counter == 3){
                return false;
            }
        }
        counter = 0;
    }
    return true;
}





