#include <iostream>
#include <map>
#include "matrix.h"
#include "maze.h"

#ifndef PATHFINDER_H
#define PATHFINDER_H

class PathFinder
{   
    public:
        PathFinder(std::map<std::pair<int,int>,bool> VISITED);
        bool findPath(Maze& Maze, std::pair<int,int> start, std::pair<int,int> end);

    private:
        const std::string VISITED = " . ";
        const std::string UNVISITED = "   "; 
        std::map<std::pair<int,int>,bool> visited;
        std::vector<std::pair<int,int>> getNeighbours(Maze Maze, std::pair<int,int> currentCell);

};

#endif