#include <iostream>
#include <vector>
#ifndef MATRIX_H
#define MATRIX_H

class Matrix 
{
    public:
        Matrix();

        int rows() const;
        int columns() const;

        std::string at ( int row,  int column);
 
        void assignAt ( int row,  int column, const std::string MazeObject);
        
        bool isFull();
        
        void resize(int rows, int columns);
        
        bool isEmptyAt( int rows,  int columns);

        bool isEmpty();

        void pop_back();

        void push_back(std::string Visit);

        int size();

        std::string top();
    
    private:
        std::vector<std::string> MatrixData;
        int height;
        int width;
};

#endif


