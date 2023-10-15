#include <iostream>
#include <vector>
#include <cassert>
#include "matrix.h"


Matrix::Matrix() {};

std::string Matrix::at (int row,  int column)
{
    assert(row < height && column < width);
    return data.at( row * width + column );
}

void Matrix::assign(int row,  int column, const std::string MazeObject)
{
    data.at(row * width + column) = MazeObject;
    return; 
}

void Matrix::resize(int rows, int columns)
{
    assert(rows > 1 && columns > 1);
    
    data.resize(rows*columns);
    height = rows;
    width = columns;

}
