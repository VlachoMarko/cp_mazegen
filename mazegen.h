#include <iostream>
#include <set>
#include <cstdlib>
#include "mazebase.h"

#ifndef MAZEGEN_h
#define MAZEGEN_h

class MazeGen
{   
    public:
        MazeGen(int HEIGHT, int WIDTH, int SEED);
        void GenerateMaze(MazeBase& Maze, std::pair<int,int> currentCell);
    private:
        int height;
        int width;
        int seed;
        int movingDirection;

        std::set<std::pair<int,int>> visited;

        const std::string VERTICALSPACE = " ";
        const std::string LEVELSPACE = "   ";

        void removeWall(MazeBase& Maze, std::pair<int,int> currentCell);

        int getDirection();

        std::pair<int,int> moveDown(std::pair<int,int> currentCell);
        std::pair<int,int> moveLeft(std::pair<int,int> currentCell);
        std::pair<int,int> moveUp(std::pair<int,int> currentCell);
        std::pair<int,int> moveRight(std::pair<int,int> currentCell);

        bool isValidNeighbour(std::pair<int,int> neighbour, std::set<std::pair<int,int>> visitedCopy);
        bool hasNeighbour(std::pair<int,int> currentCell);
        std::pair<int,int> chooseNeighbour(std::pair<int,int> currentCell);
};

#endif