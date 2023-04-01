#include <iostream>
#include <string>
#include "Functions.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {
    Functions Map;
    bool test = true;
    bool test1 = true;
    int pos = 0;
    Map.toString();

    while(test && test1){
        cout << "----------------" << endl
        << "Gib ein Feld ein"<< endl
        << "----------------" << endl;
        cin >> pos;
        Map.setSymbol(pos);
        test1 = Map.checker("X");

        Map.toString();
        Map.setSymbol();
        Map.toString();
        test = Map.checker("O");
    }
    if (!test){
        cout << "Der Computer hat gewonnen";
    }
    else{
        cout << "Du hast gewonnen";
    }
    return 0;
}
