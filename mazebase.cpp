#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "mazebase.h"


MazeBase::MazeBase(int HEIGHT,  int WIDTH, int SEED)
{
    assert (HEIGHT >= 2 && WIDTH >= 2);

    height = HEIGHT * 2 + 1;
    width = WIDTH * 2 + 1;
    // heightInCells = HEIGHT;
    // widthInCells = WIDTH;
    seed = SEED;
    numberOfCells = HEIGHT * WIDTH;
    MazeData.resize(height, width);
}

void MazeBase::SetMazeBase()
{
    for (  int row = 0; row<height; row++)
           {
               for ( int column=0; column<width; column++)
               {                                                                                
                   if (row % 2 == 0 && column % 2 == 0)
                    {
                        MazeData.assignAt(row, column, CORNER);
                    }
                    else if (row % 2 == 0 && column % 2 == 1)
                    {
                        MazeData.assignAt(row, column, LEVEL); 
                    }
                    else if (row % 2 == 1 && column % 2 == 0)
                    {
                        MazeData.assignAt(row, column, VERTICAL);
                    }
                    else if (row % 2 == 1 && column % 2 == 1)
                    {
                        MazeData.assignAt(row, column, SPACE);
                    }
                    else 
                    {
                        std::cout << "DEBUG: SOMETHING WENT WRONG AT" << " ROW: " << row << " COLUMN: " << column << std::endl;
                    }


                }
           }
    
    return;

}
  
void MazeBase::GetMazeBase()
{
    for (  int row = 0; row<height; row++)
    {
        for ( int column = 0; column<width; column++)
        {
            if (column == width-1)
            {
                std::cout << MazeData.at(row, column) << std::endl;
            }
            
            else 
            {
                std::cout << MazeData.at(row, column);
            }
        }
       
    }
    
    std::cout << std::endl;
    return;
}


void MazeBase::SetHelperData(Matrix& helperMaze, int HEIGHT, int WIDTH)
{
    helperMaze.resize(HEIGHT, WIDTH);
}


Matrix MazeBase::GetMazeData() const
{
    return MazeData;
}

void MazeBase::assign(int row, int column, std::string MazeObject)
{
    MazeData.assignAt(row, column, MazeObject);
}

int MazeBase::rows() const
{
    return height;
}

int MazeBase::columns() const
{
    return width;
}

// int MazeBase::getHeightInCells() const
// {
//     return heightInCells;
// }

// int MazeBase::getWidthInCells() const
// {
//     return widthInCells;
// }

int MazeBase::getNumberOfCells() const {
    return numberOfCells;
}

/*bool MazeBase::at(int fromY, int fromX)
{
    
}

bool MazeBase::PathFinder(MazeBase& Maze, Matrix helperMaze)
{
    std::vector<int> movement1;
    std::vector<int> movement2;
    bool returnBool;

    int fromY = 0;
    int fromX = 0;
    int toY = helperMaze.rows()-1;
    int toX = helperMaze.columns()-1;


    
    if (fromY == toY && fromX == toX)
    {
        return true;
    }
    
// TO DO

}*/ 