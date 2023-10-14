#include <iostream>
#include <cassert>
#include <set>
#include "mazebase.h"
#include "mazegen.h"
    
MazeGen::MazeGen(int HEIGHT, int WIDTH, int SEED){

    assert (HEIGHT >= 2 && WIDTH >= 2);

    height = HEIGHT;
    width = WIDTH;
    seed = SEED;
    movingDirection = 0;

}

void MazeGen::GenerateMaze(MazeBase& Maze, std::pair<int,int> currentCell){

    visited.emplace(currentCell);
    // Maze.GetMazeBase();

    while(hasNeighbour(currentCell)){

        std::pair<int,int> chosenNeighbour = chooseNeighbour(currentCell);
        removeWall(Maze, currentCell);
        // Maze.GetMazeBase();

        GenerateMaze(Maze, chosenNeighbour);

    }


    
    // Maze.assign(currentCell.first, currentCell.second, "   ");


    return;
}


void MazeGen::removeWall(MazeBase& Maze, std::pair<int,int> currentCell){

    int RowCoordinate = currentCell.first * 2 + 1;
    int ColumnCoordinate = currentCell.second * 2 + 1;
    
        switch (movingDirection){
                
            case 0:
               // std::cout << "move down to " << RowCoordinate+1 << ", " << ColumnCoordinate << std::endl;
                Maze.assign(RowCoordinate+1, ColumnCoordinate, LEVELSPACE);
                break;
            
            case 1:
                // std::cout << "move left to " << RowCoordinate << ", " << ColumnCoordinate-1 << std::endl;
                Maze.assign(RowCoordinate, ColumnCoordinate-1, VERTICALSPACE);
                break;
            
            case 2:
                // std::cout << "move up to " << RowCoordinate-1 << ", " << ColumnCoordinate << std::endl;
                Maze.assign(RowCoordinate-1, ColumnCoordinate, LEVELSPACE);
                break;
            
            case 3:
                // std::cout << "move right to " << RowCoordinate << ", " << ColumnCoordinate+1 << std::endl;
                Maze.assign(RowCoordinate, ColumnCoordinate+1, VERTICALSPACE);
                break;
            
        default:
            // std::cout << "something went wrong in removeWall" << std::endl;
            break;
        }

    return;
}

std::pair<int,int> MazeGen::chooseNeighbour(std::pair<int,int> currentCell){

    std::pair<int,int> temp;
    int i = 0;

    int direction = getDirection();
    
    while(true){

        // // std::cout << "direction: " << direction << std::endl;
        

        if(direction <= 3){
            // std::cout << "custom\n";
            direction = (seed + i) % 4;
        }
        else {
            
            direction = getDirection();
            direction = direction % 4;
        }

        // // std::cout << "after direction: " << direction << std::endl;
        
        switch (direction){
                
            case 0:
                temp = moveDown(currentCell);
                
                if (isValidNeighbour(temp, visited)) {
                    // std::cout << "chosen down" << std::endl;    
                    movingDirection = 0;
                    return temp;
                }
                break;
            
            case 1:
                temp = moveLeft(currentCell);
                
                if (isValidNeighbour(temp, visited)) {
                    // std::cout << "chosen left" << std::endl;
                    movingDirection = 1;
                    return temp;
                }
                break;
            
            case 2:
                temp = moveUp(currentCell);
                if (isValidNeighbour(temp, visited)) {
                    // std::cout << "chosen up" << std::endl;
                    movingDirection = 2;
                    return temp;
                }
                break;
            
            case 3:
                
                temp = moveRight(currentCell);
                
                if (isValidNeighbour(temp, visited)) {
                    // std::cout << "chosen right" << std::endl;
                    movingDirection = 3;
                    return temp;
                }
                break;
            
        default:
            // std::cout << "something went wrong in chooseNeighbour" << std::endl;
            break;
        }
        i++;
    }

    // std::cout << "return the same" << "\n";
    return currentCell;
}

bool MazeGen::hasNeighbour(std::pair<int,int> currentCell){    

    if(isValidNeighbour(moveDown(currentCell), visited)){
        return true;
    }
    
    if(isValidNeighbour(moveLeft(currentCell), visited)){
        return true;
    }
        
    if(isValidNeighbour(moveUp(currentCell), visited)){
        return true;
    }
    
    if(isValidNeighbour(moveRight(currentCell), visited)){
        return true;
    }

    return false;
}
    

// 0 - down
std::pair<int,int> MazeGen::moveDown(std::pair<int,int> currentCell){

    currentCell.first = currentCell.first + 1;
    return currentCell;
}
       
// 1 - left  
std::pair<int,int> MazeGen::moveLeft(std::pair<int,int> currentCell){

    currentCell.second = currentCell.second - 1;
    return currentCell;
}

// 2 - up
std::pair<int,int> MazeGen::moveUp(std::pair<int,int> currentCell){

    currentCell.first = currentCell.first - 1;
    return currentCell;
}

// 3 - right
std::pair<int,int> MazeGen::moveRight(std::pair<int,int> currentCell){

    currentCell.second = currentCell.second + 1;
    return currentCell;
}

bool MazeGen::isValidNeighbour(std::pair<int,int> neighbour, std::set<std::pair<int,int>> visitedCopy){

    if(visitedCopy.emplace(neighbour).second && neighbour.first >= 0 &&  neighbour.second >= 0 && neighbour.first < height && neighbour.second < width){
        return true;
    }
    return false;

}

int MazeGen::getDirection()
{              
    if (seed == 0 || seed == 1 || seed == 2 || seed == 3){                
        // // std::cout << "custom seed" << std::endl;
        return seed;                                           
    }
    else{
        // // std::cout << "random seed" << std::endl;                                                
        return rand();                                   
    }
}


    
