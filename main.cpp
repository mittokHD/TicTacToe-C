#include <iostream>
#include "Map.h"
#include "windows.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    //WhileTrue Arguments
    bool player = true;
    bool computer = true;
    //pos muss deklariert sein
    int pos = 0;
    //Map wird erstellt
    Map Map;
    Map.print();

    //Gameloop
    while (player && computer) {
        //Player spielt loop
        cout << "----------------" << endl
             << "Gib eine Zahl ein" << endl
             << "----------------" << endl;
        cin >> pos;
        Map.setSymbol(pos);
        player = Map.checker(Structures::PLAYER);
        if (!player) {
            Map.print();
            Map.checkWhoWon(player,computer);
            return 0;
        }
        Map.print();

        Sleep(1500);

        //Computer spielt loop
        cout << "----------------" << endl
            << "Der Computer war" << endl
            << "----------------" << endl;
        Map.setSymbol();
        Map.print();
        computer = Map.checker(Structures::COMP);
        if (!computer) {
            Map.print();
            Map.checkWhoWon(player,computer);
            return 0;
        }
    }
}





