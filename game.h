// 
// 2048.h
// by Andrew Lin
// 

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "grid.h" 

class Game {
    public: 
        Game();
        void run();

    private:
        bool processCommand();
        bool checkLose();
        void printGrid();
        void printInstructions();
        Grid grid;
} ;

#endif
