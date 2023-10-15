#include <iostream>
#include "matrix.h"
#ifndef MAZE_H
#define MAZE_H

class Maze
{   
    public:
        Maze(int HEIGHT,  int WIDTH, int SEED);
        
        void assign(int row, int column, std::string MazeObject);
        bool notWall(int row, int column);
        
        std::pair<int,int> getDimensions() const;
        Matrix getMazeData() const;
        int rows() const;
        int columns() const;
        void getMaze();  
        void setMaze();
        
    private:
        std::pair<int,int> dimensions;
        int height;
        int width;   
        int seed;                                    // 0 == down, 1 == left, 2 == up, 3 == right

        const std::string CORNER = "+";
        const std::string LEVEL = "---";
        const std::string VERTICAL = "|";
        const std::string SPACE = "   ";
        Matrix MazeData;
};

#endif