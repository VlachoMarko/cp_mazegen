#include <iostream>
#include <cstdlib>
#include "matrix.h"
#ifndef MAZEBASE_H
#define MAZEBASE_H

class MazeBase
{   
    public:
        MazeBase(int HEIGHT,  int WIDTH, int SEED);
        void SetMazeBase();
        void GetMazeBase(); 
        void SetHelperData(Matrix& visited, int HEIGHT, int WIDTH);
        void assign(int row, int column, std::string MazeObject);
        // int getDirection();
        int rows() const;
        int columns() const;
        // int getHeightInCells() const;
        // int getWidthInCells() const;
        int getNumberOfCells() const;
        int randomNumber();
        
        Matrix GetMazeData() const;

    private:
        int height;
        int width;   
        int seed;                                    // 1 == down, 2 == left, 3 == up, 4 == right, 0 == starter
        // int heightInCells;
        // int widthInCells;
        int numberOfCells;

        const std::string CORNER = "+";
        const std::string LEVEL = "---";
        const std::string VERTICAL = "|";
        const std::string SPACE = "   ";
        const std::string DOT = " . ";
        const std::string V = "visited";
        Matrix MazeData;
      
};

#endif