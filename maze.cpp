#include <iostream>
// #include <cassert>
#include <cstdlib>
// #include "arguments.h"
#include "matrix.h"
#include "setmazeinfo.h"
#include "setinputinfo.h"
// #include "pathfinder.h"
#include "mazebase.h"
#include "mazegen.h"



int main(int argc, char* argv[])
{
    int HEIGHT, WIDTH, SEED = 0;
    int direction = 0;                                                              // 0 == down, 1 == left, 2 == up, 3 == right
    std::string recursion = "  " ;
    
    std::vector<int> inputInfo(3);

    if (argc == 3)
    {
        SetInputInfo(inputInfo, argv[1], argv[2]);
    }
    else if (argc == 4)
    {
        SetInputInfo(inputInfo, argv[1], argv[2], argv[3]);
    }

    SetMazeInfo(inputInfo, HEIGHT, WIDTH, SEED);   
    // Matrix helperMaze;
    
    if(SEED < 0){
        SEED = SEED * (-1);
    }

    MazeBase Maze(HEIGHT, WIDTH, SEED);
    Maze.SetMazeBase();
    srand(SEED);   
    // Maze.SetHelperData(helperMaze, HEIGHT, WIDTH);
    
    
    int Y = 0;
    int X = 0;
    
    // const unsigned int cellNumber = helperMaze.rows() * helperMaze.columns();
    // pathFinder Path(helperMaze, direction);
    

    MazeGen Generator(HEIGHT, WIDTH, SEED);
    Generator.GenerateMaze(Maze, std::make_pair(0,0));
    
    



    // Path.MazeFinder(cellNumber, Maze, visitedNumbers, movementY, movementX, recursion, Y, X);
    Maze.GetMazeBase();



    return 0;
}



