#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "matrix.h"
#include "isvisitedfull.h"
#ifndef MAZEFINDER_h
#define MAZEFINDER_h

void MazeFinder(Matrix Maze, Matrix& stack, Matrix visited, long long& LEVEL,  long long& HORIZONTAL, int& direction)
{
    const std::string V = "visited";
    std::string index1, index2;

    if (stack.isEmpty() == true)
    {
        std::cout << LEVEL << "\n" << HORIZONTAL << "\n" << direction << std::endl;
        assert(LEVEL < visited.rows() && HORIZONTAL < visited.columns());
        visited.assignAt(LEVEL, HORIZONTAL, V);
        
        index1 = std::to_string(LEVEL);
        index2 = std::to_string(HORIZONTAL);
        stack.push_back(index1+index2);

        assert(visited.at(LEVEL, HORIZONTAL) == V && index1 == "0" && index2 == "0" && stack.top() == "00");
    }
    else if(isVisitedFull(visited) == true)
    {
        std::cout << "end" << std::endl;
    }

}

#endif