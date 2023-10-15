#include <iostream>
#include <map>
#include "matrix.h"
#include "pathfinder.h"
#include "maze.h"
#include "mazegen.h"

void handleInput(std::vector<int>& inputInfo, const char* inputHeight, const char* inputWidth, const char* inputSeed = "a");
void initVariables(std::vector<int> inputInfo, int& HEIGHT, int& WIDTH, int& SEED);
void initVisited(std::map<std::pair<int,int>,bool>& visited, int height, int width);


int main(int argc, char* argv[])
{
    try {

        int HEIGHT, WIDTH, SEED;
        std::vector<int> inputInfo(3);
        std::map<std::pair<int,int>, bool> visited;

        if (argc == 3)
        {
            handleInput(inputInfo, argv[1], argv[2]);
        }
        else if (argc == 4)
        {
            handleInput(inputInfo, argv[1], argv[2], argv[3]);
        }

        
        initVariables(inputInfo, HEIGHT, WIDTH, SEED);   
        initVisited(visited, HEIGHT, WIDTH);

        if(SEED < 0){
            SEED = SEED * (-1);
        }

        std::pair<int,int> from = std::make_pair(0,0);
        std::pair<int,int> to = std::make_pair(HEIGHT-1, WIDTH-1);

       
        Maze Maze(HEIGHT, WIDTH, SEED);
        Maze.setMaze();
        srand(SEED);   

        MazeGen Generator(HEIGHT, WIDTH, SEED, visited);
        Generator.GenerateMaze(Maze, from);
        PathFinder Pathfinder(visited);
        
        if(!Pathfinder.findPath(Maze, from, to)){
           throw std::runtime_error("did not find path");
        }

        Maze.getMaze();
    }
    catch (std::runtime_error& excpt)  {
    
        std::cout << "An error occurred: ";
        std::cout << excpt.what() << std::endl; 
    }

    return 0;
}




void handleInput(std::vector<int>& inputInfo, const char* inputHeight, const char* inputWidth, const char* inputSeed){
    
    inputInfo.at(0) = std::atoi(inputHeight);
    inputInfo.at(1) = std::atoi(inputWidth);

    if ( inputSeed == "a")
    {
        inputInfo.at(2) = time(0);
    }
    else 
    {
        inputInfo.at(2) = std::atoi(inputSeed);
    }
       
    return;
}

void initVariables(std::vector<int> inputInfo, int& HEIGHT, int& WIDTH, int& SEED) {
    HEIGHT = inputInfo.at(0);
    WIDTH = inputInfo.at(1);
    SEED = inputInfo.at(2);
}

void initVisited(std::map<std::pair<int,int>,bool>& visited, int height, int width){

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            visited.emplace(std::make_pair(i,j), false);
        }    
    }
}
