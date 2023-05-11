// 
// grid.h
// by Andrew Lin
// 

#ifndef GRID_H
#define GRID_H

#include <string>
#include <set>
#include <algorithm>
#include <iostream>

class Grid {
    public: 
        Grid();
        void printGrid();
        
        bool shiftLeft();
        bool shiftRight();
        bool shiftUp();
        bool shiftDown();
        
        void addNew();
        void checkCells();

        bool checkWin();

    private:
        int score;
        int grid[4][4];

        std::set<int> emptyCells;
} ;

#endif