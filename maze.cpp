#include <iostream>
#include <vector>
#include <cassert>
#include "maze.h"


Maze::Maze(int HEIGHT,  int WIDTH, int SEED)
{
    assert (HEIGHT >= 2 && WIDTH >= 2);

    dimensions = std::make_pair(HEIGHT,WIDTH);
    height = HEIGHT * 2 + 1;
    width = WIDTH * 2 + 1;
    seed = SEED;

    MazeData.resize(height, width);
}

void Maze::setMaze()
{
    for (  int row = 0; row<height; row++)
           {
               for ( int column=0; column<width; column++)
               {                                                                                
                   if (row % 2 == 0 && column % 2 == 0)
                    {
                        MazeData.assign(row, column, CORNER);
                    }
                    else if (row % 2 == 0 && column % 2 == 1)
                    {
                        MazeData.assign(row, column, LEVEL); 
                    }
                    else if (row % 2 == 1 && column % 2 == 0)
                    {
                        MazeData.assign(row, column, VERTICAL);
                    }
                    else if (row % 2 == 1 && column % 2 == 1)
                    {
                        MazeData.assign(row, column, SPACE);
                    }
                    else 
                    {
                       throw std::runtime_error("something went wrong in setMazeBase");
                    }


                }
           }
    
    return;

}
  
void Maze::getMaze()
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

Matrix Maze::getMazeData() const
{
    return MazeData;
}

void Maze::assign(int row, int column, std::string MazeObject)
{
    MazeData.assign(row, column, MazeObject);
}

int Maze::rows() const
{
    return height;
}

int Maze::columns() const
{
    return width;
}

std::pair<int,int> Maze::getDimensions() const{
    return dimensions;
}

bool Maze::notWall(int row, int column){
    
    if(MazeData.at(row, column) == VERTICAL || MazeData.at(row, column) == LEVEL){
        return false;
    }
    return true;
}
