#include <iostream>
#include <map>
#include "pathfinder.h"
#include "navigation.h"
#include "mazegen.h"
#include "maze.h"

PathFinder::PathFinder(std::map<std::pair<int,int>,bool> VISITED){
    visited = VISITED;
};


bool PathFinder::findPath(Maze& Maze, std::pair<int,int> from, std::pair<int,int> to){

    std::vector<std::pair<int,int>> neighbours;
    
    Maze.assign(from.first*2+1, from.second*2+1, VISITED);
    visited.at(from) = true;

    if(from.first == to.first && from.second == to.second) return true;

    neighbours = getNeighbours(Maze, from);

    for(int i=0; i<neighbours.size(); i++){

        if(!visited.at(neighbours.at(i))){
            
            if(findPath(Maze, neighbours.at(i), to)) return true;
        }
    }

    Maze.assign(from.first*2+1, from.second*2+1, UNVISITED);
    visited.at(from) = false;

    return false;
};



std::vector<std::pair<int,int>> PathFinder::getNeighbours(Maze Maze, std::pair<int,int> currentCell){

    std::vector<std::pair<int,int>> neighbours;

    if(isValidNeighbour(moveDown(currentCell), visited, Maze.getDimensions()) &&
            Maze.notWall(currentCell.first*2+2, currentCell.second*2+1)){
        
        neighbours.push_back(moveDown(currentCell));
    }
    
    if(isValidNeighbour(moveLeft(currentCell), visited, Maze.getDimensions()) &&
            Maze.notWall(currentCell.first*2+1, currentCell.second*2)) {

        neighbours.push_back(moveLeft(currentCell));
    } 
    
    if(isValidNeighbour(moveUp(currentCell), visited, Maze.getDimensions()) &&
            Maze.notWall(currentCell.first*2, currentCell.second*2+1)){

        neighbours.push_back(moveUp(currentCell));
    }
    
    if(isValidNeighbour(moveRight(currentCell), visited, Maze.getDimensions()) &&
            Maze.notWall(currentCell.first*2+1, currentCell.second*2+2)){

        neighbours.push_back(moveRight(currentCell));
    }


    return neighbours;
}



