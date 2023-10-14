#include <iostream>
#include <vector>
#ifndef ARGUMENTS_H
#define ARGUMENTS_H


class Arguments {
    public:
        Arguments();
        void SetMazeInfo(const char* Height, const char* Width, const char* randSeed);
        int at(int pointer);
    private:
        std::vector<int> mazeInfo;                                                                   // 0 = Height, 1 = Width, 2 = seedNumber
    };

#endif