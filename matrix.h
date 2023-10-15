#include <iostream>
#include <vector>
#ifndef MATRIX_H
#define MATRIX_H

class Matrix 
{
    public:
        Matrix();

        std::string at (int row,  int column);
        void assign (int row,  int column, const std::string MazeObject);        
        void resize(int rows, int columns);
        
    private:
        std::vector<std::string> data;
        int height;
        int width;
};

#endif


