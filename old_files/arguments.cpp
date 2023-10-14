#include <iostream>
#include <vector>
#include "arguments.h"

Arguments::Arguments() {}

void Arguments::SetMazeInfo (const char* Height, const char* Width, const char* randSeed)
{

    mazeInfo.resize(3);
    
    mazeInfo.at(0) = std::atoi(Height);
    mazeInfo.at(1) = std::atoi(Width);
   
    if ( randSeed != 0)
    { 
        mazeInfo.at(2) = std::atoi(randSeed);
    }
    else 
    {
        mazeInfo.at(2) = 0;
    }
    return;
}

int Arguments::at (int pointer)
        {
            int result = mazeInfo.at(pointer);
            return result;
        }

