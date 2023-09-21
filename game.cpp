// 
// game.cpp
// by Andrew Lin
// 

#include "game.h"

Game::Game() {
    
}

void Game::run() {
    printInstructions();
    bool quit = true;
    bool winOrLose;
    while(quit) {
        grid.addNew();
        grid.printGrid();
        winOrLose = grid.checkWin();
        winOrLose = checkLose();
        if(winOrLose == false)
            break;
        quit = processCommand();
    }
    std::cout << "Thank you for playing 2048!" << std::endl;
}

bool Game::processCommand() {
    bool valid = false;
    while(!valid) {
        std::cout << "Enter your command: ";
        char command;
        std::cin >> command;

        if(command == 'w')
            valid = grid.shiftUp();
        else if(command == 'a'){
            valid = grid.shiftLeft();
        }
        else if(command == 's')
            valid = grid.shiftDown();
        else if(command == 'd')
            valid = grid.shiftRight();
        else if(command == 'q')
            return false;

        if(valid == false)
            std::cout << " Command Invalid." << std::endl;
    }
    return true;
}

bool Game::checkLose() {
    Grid newGrid = grid;
    bool valid = newGrid.shiftLeft();
    if(valid == true)
        return true;
    valid = newGrid.shiftRight();
    if(valid == true) 
        return true;
    valid = newGrid.shiftUp();
    if(valid == true) 
        return true;
    valid = newGrid.shiftDown();
    if(valid == true) 
        return true;
    // grid.printGrid();
    std::cout << "Oh no! You've Lost!" << std::endl;
    return false;
}

void Game::printInstructions() {
    std::cout << "Welcome to 2048" << std::endl << std::endl;
    std::cout << "Controls" << std::endl;
    std::cout << "w: shifts up" << std::endl;
    std::cout << "a: shifts left" << std::endl;
    std::cout << "s: shifts down" << std::endl;
    std::cout << "d: shifts right" << std::endl;
    std::cout << "q: quits the program" << std::endl;
}