###
### Makefile for 2048
### CalcYouLater is an RPN calculator
###
### Author:  Andrew Lin

MAKEFLAGS += -L

CXX      = g++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

Game.o: game.cpp game.h
	${CXX} ${CXXFLAGS} -c game.cpp
	
Grid.o: grid.cpp grid.h
	${CXX} ${CXXFLAGS} -c grid.cpp

2048: main.cpp Game.o Grid.o
	${CXX} ${CXXFLAGS} -o 2048 $^

clean:
	rm Game.o