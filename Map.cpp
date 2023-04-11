#include "Map.h"
using std::cout;
using std::endl;

Map::Map() {
    map.resize(3);
    for(int x=0; x<3; x++){
        map.at(x).resize(3);
        for(int y=0; y<3; y++){
            map.at(x).at(y) = Structures::CLEAR;
        }
    }
}

void Map::print() {
    int counter = 1;
    for(int x = 0; x<map.size(); x++){
        for(int y = 0; y<map.size(); y++){
            if(map.at(x).at(y) == Structures::CLEAR){
                cout << counter;
                counter++;
                continue;
            }
            if(map.at(x).at(y) == Structures::PLAYER){
                counter++;
                cout << "";
            }
            if(map.at(x).at(y) == Structures::COMP){
                cout << "";
                counter++;
            }

            cout << map.at(x).at(y);
        }
        cout << endl;
    }
    cout << endl;
}

Structures Map::decoder(int pos){
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
            cout << "ERROR. Number out of bounce.";
            return Structures::CLEAR;
    }
}

std::vector<int> Map::encoder(int pos){
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

void Map::setSymbol() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1,9);
    int pos = dist(rd);
    while (decoder(pos) != Structures::CLEAR){
         pos = dist(rd);
    }
    std::vector encoded = encoder(pos);
    map.at(encoded[0]).at(encoded[1]) = Structures::COMP;
}

void Map::setSymbol(int pos) {
    while (decoder(pos) != Structures::CLEAR){
        cout << "Error. Bereits belegt. Gib ein neues Feld ein";
        std::cin >> pos;
    }
    std::vector encoded = encoder(pos);
    map.at(encoded[0]).at(encoded[1]) = Structures::PLAYER;
}

bool Map::checker(Structures symbol) {
    int counter = 0;
    for (int i = 0; i < 3; i++){
        if (map.at(i).at(i) == symbol){
            counter = counter + 1;
        }
        if (counter == 3){
            return false;
        }
    }
    counter = 0;
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            if (map.at(x).at(y) == symbol){
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
            if (map.at(x).at(y) == symbol){
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

void Map::checkWhoWon(bool test, bool test1){
    if (!test) {
        cout << "Du hast gewonnen" << endl;
        return;
    }
    if (!test1) {
        cout << "Der Computer hat gewonnen" << endl;
        return;
    }
}





