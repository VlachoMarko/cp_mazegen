#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <stack>
#include <set>
#include "mazebase.h"
#include "matrix.h"
#include "mystack.h"
#ifndef PATHFINDER_H
#define PATHFINDER_H

class pathFinder
{
    public: 
        pathFinder(const Matrix& oldhelperMaze, int olddirection);

        void MazeFinder(const unsigned int cellNumber, MazeBase& Maze, std::set<int>& visitedNumbers,
        MyStack& movementY, MyStack& movementX, std::string recursion, int Y, int X);

        void isNeighbour(const unsigned int& cellNumber, int Y, int X,  std::set<int>& visitedNumbers, MyStack& movementY, MyStack& movementX);

        void replaceWalls(MyStack movementY, MyStack movementX, int Y, int X, MazeBase& Maze);

    private:
        Matrix helperMaze;
        int direction; 
        unsigned int visitedCells = 0;
        unsigned int helperSize;
        
};

#endif