#include <iostream>
#include <vector>
#include <cassert>
#include "matrix.h"


Matrix::Matrix() {};

int Matrix::rows() const
{ 
    return height; 
}

int Matrix::columns() const 
{ 
    return width; 
}

std::string Matrix::at ( int row,  int column)
{
    assert(row < height && column < width);
    return MatrixData.at( row * width + column );
}

void Matrix::assignAt (int row,  int column, const std::string MazeObject)
{
    MatrixData.at(row * width + column) = MazeObject;
    return; 
}


bool Matrix::isFull()
{
    bool returnBool;

            for ( int row=0; row<height; row++)
            {
                for ( int column=0; column<width; column++ )
                {
                    if (MatrixData.at(row * width + column) == " . ")
                    {
                        returnBool = true;
                    }
                    else 
                    {
                        returnBool = false;
                        return returnBool;
                    }
                }
            }

    return returnBool;
}

void Matrix::resize(int rows, int columns)
{
    assert(rows > 1 && columns > 1);
    
    MatrixData.resize(rows*columns);
    height = rows;
    width = columns;

}

bool Matrix::isEmptyAt( int rows,  int columns)
{
    if ( MatrixData.at( rows * width + columns) != "")
    {
        return false;
    }
    else 
    {
        return true;
    }
}

bool Matrix::isEmpty()
{
    if ( MatrixData.size() == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


void Matrix::pop_back()
{
    MatrixData.pop_back();
}

void Matrix::push_back(std::string Visit)
{
    MatrixData.push_back(Visit);
}

int Matrix::size()
{
    int size = height * width;

    return size;
}

std::string Matrix::top()
{
    int lastindex  = MatrixData.size()-1; 
    std::string returnData = MatrixData.at(lastindex);

    return returnData;
}

