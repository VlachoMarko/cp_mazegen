#include <iostream>
#include <map>
#include <cstdlib>

#ifndef NAVIGATION_H
#define NAVIGATION_H

    std::pair<int,int> moveDown(std::pair<int,int> currentCell);
    std::pair<int,int> moveLeft(std::pair<int,int> currentCell);
    std::pair<int,int> moveUp(std::pair<int,int> currentCell);
    std::pair<int,int> moveRight(std::pair<int,int> currentCell);

    bool isValidNeighbour(std::pair<int,int> neighbour, std::map<std::pair<int,int>,bool> visitedCopy, std::pair<int,int> dimensions);


#endif