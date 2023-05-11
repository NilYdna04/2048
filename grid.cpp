// 
// grid.cpp
// by Andrew Lin
// 

#include "grid.h"

Grid::Grid() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            grid[i][j] = 0;
        }
    }
    score = 0;
}

void Grid::printGrid() {
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool Grid::shiftLeft() {
    int local;
    bool loop;
    bool worked = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            local = j;
            loop = true;
            while(not (local <= 0) and loop and not(grid[i][local] == 0)) {
                if(grid[i][local-1] == grid[i][local]) {
                    grid[i][local] = 0;
                    grid[i][local-1] = grid[i][local-1] * 2;
                    score = score + grid[i][local-1];
                    worked = true;
                }
                else if(grid[i][local-1] == 0) {
                    grid[i][local-1] = grid[i][local];
                    grid[i][local] = 0;
                    worked = true;
                }
                else
                    loop = false;
                local--;
            }
        }
    }
    return worked;
}

bool Grid::shiftRight() {
    int local;
    bool loop;
    bool worked = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 3; j > -1; j--) {
            local = j;
            loop = true;
            while(not (local >= 3) and loop and not(grid[i][local] == 0)) {
                if(grid[i][local + 1] == grid[i][local]) {
                    grid[i][local] = 0;
                    grid[i][local+1] = grid[i][local+1] * 2;
                    score = score + grid[i][local+1];
                    worked = true;
                }
                else if(grid[i][local+1] == 0) {
                    grid[i][local+1] = grid[i][local];
                    grid[i][local] = 0;
                    worked = true;
                }
                else
                    loop = false;
                local++;
            }
        }
    }
    return worked;
}

bool Grid::shiftUp() {
    int local;
    bool loop;
    bool worked = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            local = j;
            loop = true;
            while(not (local <= 0) and loop and not(grid[local][i] == 0)) {
                if(grid[local-1][i] == grid[local][i]) {
                    grid[local][i] = 0;
                    grid[local-1][i] = grid[local-1][i] * 2;
                    score = score + grid[local-1][i];
                    worked = true;
                }
                else if(grid[local-1][i] == 0) {
                    grid[local-1][i] = grid[local][i];
                    grid[local][i] = 0;
                    worked = true;
                }
                else
                    loop = false;
                local--;
            }
        }
    }
    return worked;
}

bool Grid::shiftDown() {
    int local;
    bool loop;
    bool worked = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 3; j > -1; j--) {
            local = j;
            loop = true;
            while(not (local >= 3) and loop and not(grid[local][i] == 0)) {
                if(grid[local + 1][i] == grid[local][i]) {
                    grid[local][i] = 0;
                    grid[local+1][i] = grid[local+1][i] * 2;
                    score = score + grid[local+1][i];
                    worked = true;
                }
                else if(grid[local+1][i] == 0) {
                    grid[local+1][i] = grid[local][i];
                    grid[local][i] = 0;
                    worked = true;
                }
                else
                    loop = false;
                local++;
            }
        }
    }
    return worked;
}

void Grid::addNew() {
   int value = rand() % 2;
   if(value == 0) {
        value = 2; 
   } 
   else if (value == 1){
        value = 4;
   }
    checkCells();
    int random = rand() % emptyCells.size();
    auto it = std::begin(emptyCells);
    std::advance(it, random);
    int place = *it;
    int i = place / 4;
    int j = place % 4;
    grid[i][j] = value;
}

void Grid::checkCells() {
    emptyCells.clear();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                emptyCells.insert(i*4 + j);
            } 
        }
    }
}



bool Grid::checkWin() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (grid[i][j] == 2048) {
                std::cout << "Congragutlations! You won!" << std::endl;
                return false;
            } 
        }
    }
    return true;
}
