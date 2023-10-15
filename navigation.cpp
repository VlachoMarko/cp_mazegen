#include <iostream>
#include <map>
#include "navigation.h"


// 0 - down
std::pair<int,int> moveDown(std::pair<int,int> currentCell){

    currentCell.first = currentCell.first + 1;
    return currentCell;
}
       
// 1 - left  
std::pair<int,int> moveLeft(std::pair<int,int> currentCell){

    currentCell.second = currentCell.second - 1;
    return currentCell;
}

// 2 - up
std::pair<int,int> moveUp(std::pair<int,int> currentCell){

    currentCell.first = currentCell.first - 1;
    return currentCell;
}

// 3 - right
std::pair<int,int> moveRight(std::pair<int,int> currentCell){

    currentCell.second = currentCell.second + 1;
    return currentCell;
}

bool isValidNeighbour(std::pair<int,int> neighbour, std::map<std::pair<int,int>,bool> visited, std::pair<int,int> dimensions){

    if(neighbour.first >= 0 &&  neighbour.second >= 0 && neighbour.first < dimensions.first 
            && neighbour.second < dimensions.second && !visited.at(neighbour)){

        return true;
    }
    return false;
}

