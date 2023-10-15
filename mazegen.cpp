#include <iostream>
#include <cassert>
#include <map>
#include "maze.h"
#include "mazegen.h"
#include "navigation.h"
    
MazeGen::MazeGen(int HEIGHT, int WIDTH, int SEED, std::map<std::pair<int,int>,bool> VISITED){

    assert (HEIGHT >= 2 && WIDTH >= 2);

    dimensions = std::make_pair(HEIGHT, WIDTH);
    movingDirection = 0;
    visited = VISITED;
    seed = SEED;
}

void MazeGen::GenerateMaze(Maze& Maze, std::pair<int,int> currentCell){

    visited.at(currentCell) = true;
    // Maze.GetMazeBase();
    
    while(hasNeighbour(currentCell)){

        std::pair<int,int> chosenNeighbour = chooseNeighbour(currentCell);
        removeWall(Maze, currentCell);
        // Maze.GetMazeBase();

        GenerateMaze(Maze, chosenNeighbour);

    }

    return;
}


void MazeGen::removeWall(Maze& Maze, std::pair<int,int> currentCell){

    int RowCoordinate = currentCell.first * 2 + 1;
    int ColumnCoordinate = currentCell.second * 2 + 1;
    
        switch (movingDirection){
                
            case 0:
                Maze.assign(RowCoordinate+1, ColumnCoordinate, LEVELSPACE);
                break;
            
            case 1:
                Maze.assign(RowCoordinate, ColumnCoordinate-1, VERTICALSPACE);
                break;
            
            case 2:
                Maze.assign(RowCoordinate-1, ColumnCoordinate, LEVELSPACE);
                break;
            
            case 3:
                Maze.assign(RowCoordinate, ColumnCoordinate+1, VERTICALSPACE);
                break;
            
        default:
            throw std::runtime_error("something went wrong in removeWall");
            break;
        }

    return;
}

std::pair<int,int> MazeGen::chooseNeighbour(std::pair<int,int> currentCell){

    std::pair<int,int> next;
    int i = 0;

    int direction = getDirection();
    
    while(true){

        if(direction <= 3){
            direction = (seed + i) % 4;
        }
        else {            
            direction = getDirection();
            direction = direction % 4;
        }

        // // std::cout << "after direction: " << direction << std::endl;
        
        switch (direction){
                
            case 0:
                next = moveDown(currentCell);
                
                if (isValidNeighbour(next, visited, dimensions)) {
                    movingDirection = 0;
                    return next;
                }
                break;
            
            case 1:
                next = moveLeft(currentCell);
                
                if (isValidNeighbour(next, visited, dimensions)) {
                    movingDirection = 1;
                    return next;
                }
                break;
            
            case 2:
                next = moveUp(currentCell);
                if (isValidNeighbour(next, visited, dimensions)) {
                    movingDirection = 2;
                    return next;
                }
                break;
            
            case 3:
                
                next = moveRight(currentCell);
                
                if (isValidNeighbour(next, visited, dimensions)) {
                    movingDirection = 3;
                    return next;
                }
                break;
            
            default:
                throw std::runtime_error("something went wrong in chooseNeighbour");
            }

        i++;
    }

    throw std::runtime_error("something went wrong in chooseNeighbour 2.0");
}

bool MazeGen::hasNeighbour(std::pair<int,int> currentCell){    

    if(isValidNeighbour(moveDown(currentCell), visited, dimensions) || isValidNeighbour(moveLeft(currentCell), visited, dimensions) || 
            isValidNeighbour(moveUp(currentCell), visited, dimensions) || isValidNeighbour(moveRight(currentCell), visited, dimensions)){

        return true;
    }
    return false;
}


int MazeGen::getDirection()
{              
    if (seed == 0 || seed == 1 || seed == 2 || seed == 3){                
        return seed;                                           
    }
    else{
        return rand();                                   
    }
}


    
