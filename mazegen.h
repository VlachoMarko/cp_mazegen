#include <iostream>
#include <map>
#include "maze.h"

#ifndef MAZEGEN_H
#define MAZEGEN_H

class MazeGen
{   
    public:
        MazeGen(int HEIGHT, int WIDTH, int SEED, std::map<std::pair<int,int>, bool> VISITED);
        void GenerateMaze(Maze& Maze, std::pair<int,int> currentCell);
    
    private:
        int seed;
        int movingDirection;
        
        std::pair<int,int> dimensions;
        std::map<std::pair<int,int>, bool> visited;

        const std::string LEVELSPACE = "   ";
        const std::string VERTICALSPACE = " ";

        int getDirection();
        bool hasNeighbour(std::pair<int,int> currentCell);
        void removeWall(Maze& Maze, std::pair<int,int> currentCell);
        std::pair<int,int> chooseNeighbour(std::pair<int,int> currentCell);

};

#endif