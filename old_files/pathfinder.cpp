#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <set>
#include <sstream>
#include "pathfinder.h"
#include "isvisitedfull.h"
#include "mystack.h"
#include "mazebase.h"

pathFinder::pathFinder(const Matrix& oldhelperMaze, int olddirection) 
{
    helperMaze = oldhelperMaze;
    direction = olddirection;
    helperSize = helperMaze.rows() * helperMaze.columns();
}

void pathFinder::replaceWalls(MyStack movementY, MyStack movementX, int Y, int X, MazeBase& Maze)
{
        int newY = 0;
        int newX = 0;
        int tempIntY;
        int tempIntX;
        const std::string replaceLevel = "   ";
        const std::string replaceVertical = " ";

        if (movementY.isEmpty() == false && movementX.isEmpty() == false)
        {
            tempIntY = movementY.top();
            tempIntX = movementX.top();
            movementY.pop();
            movementX.pop();

            if (movementY.isEmpty() == false && movementX.isEmpty() == false)
            {
               newY = movementY.top();
               newX = movementX.top();
            }
        
            movementY.push(tempIntY);
            movementX.push(tempIntX);
        }
        if ((newY - Y == 1 || newY - Y == -1 ) && newX == X)
        {
            if (newY - Y == 1)
            {
                Maze.assign((Y*2+2), (X*2+1), replaceLevel);                             
            }
            else if (newY - Y  == (-1))
            {
                Maze.assign((Y*2), (X*2+1), replaceLevel);
            }
        }
        else if ((newX - X == 1 || newX - X == -1) && newY == Y)
        {
            if (newX - X == 1)
            {
                Maze.assign((Y*2+1), (X*2+2), replaceVertical);
            }
            else if (newX - X == (-1))
            {
                Maze.assign((Y*2+1), (X*2), replaceVertical);
            }
        }
}




void pathFinder::isNeighbour (const unsigned int& cellNumber, int Y, int X, std::set<int>& visitedNumbers, MyStack& movementY, MyStack& movementX)
{
    std::vector<int> neighbourY;
    std::vector<int> neighbourX;
    
    
    
    Y = movementY.top();
    X = movementX.top();
    
    std::cout << "Y : " << Y << " X : " << X << std::endl;
    std::cout << "Y size: " << movementY.size() << " X size: " << movementX.size() << std::endl;
    std::cout << "visitedNumber size: " << visitedNumbers.size() << "\n" << "\n";

  
    if (visitedNumbers.size() == cellNumber-1)                                                                                         
    {
        return;
    }
    else if (movementY.size() == 1)
    {
        return;
    }

   
   
    if (movementY.size() == visitedNumbers.size())
    {
        srand(time(0));
        direction = rand() % 4;
    }
    else
    {
        direction = 0;
    }
    
 

   switch (direction)
{
       case 0:

       if ( ( X >= 0 ) && ( Y >= 0 ) && ( Y+1 < helperMaze.rows() ) && ( X < helperMaze.columns() ) )
    {
        int tempY1 = Y+1;
        int combination1 = 0;                                           

        if ( tempY1 == 0 && X < 10)
        {
            combination1 = X;
        }
        else if (tempY1 < 10 && X < 10)        
        {
            combination1 = tempY1 * 10 + X;
        }
        //NEW
        else if (tempY1 < 100 && X < 100)
        {
            combination1 = tempY1 * 100 + X;
        }          

        if ( visitedNumbers.count(combination1) == false)
        {
            neighbourY.push_back(tempY1);
            neighbourX.push_back(X);
            goto continue1;

        }
        else if (movementY.size() != visitedNumbers.size())
        {
            neighbourY.push_back(tempY1);
            neighbourX.push_back(X);
            isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);
        }
        else 
        {
            goto continue1;
        }
        
    }
       break;
       
       
       case 1:
    continue1:

       if ( ( X-1 >= 0 ) && ( Y >= 0 ) && (Y < helperMaze.rows()) && (X < helperMaze.columns()) )
    {       
        int tempX1 = X-1;
        int combination2 = 0;                                          

        if ( Y == 0 && tempX1 < 10)
        {
            combination2 = tempX1;
        }
        else if ( (Y < 10 && tempX1 < 10) || (Y < 10 && tempX1 == 0))        
        {
            combination2 = Y * 10 + tempX1;
        }         
        //NEW
        else if (Y < 100 && tempX1 < 100)
        {
            combination2 = Y * 100 + tempX1;
        }                                                              


        if (visitedNumbers.count(combination2) == false)
        {
            neighbourY.push_back(Y);
            neighbourX.push_back(tempX1);
            goto continue2;
        }
        else if (movementY.size() != visitedNumbers.size())
        {
            neighbourY.push_back(Y);
            neighbourX.push_back(tempX1);
            isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);
        }
        else 
        {
            goto continue2;
        }
    }
       break;

       

       case 2:
    
    continue2:
       if ( ( X >= 0 ) && ( Y >= 0 ) && (Y < helperMaze.rows()) && (X+1 < helperMaze.columns()) )
    {
    
        int tempX2 = X+1;
        int combination3 = 0;                                          

        if ( Y == 0 && tempX2 < 10)
        {
            combination3 = tempX2;
        }
        else if (Y < 10 && tempX2 < 10)       
        {
            combination3 = Y * 10 + tempX2;
        }   
        //NEW
        else if (Y < 100 && tempX2 < 100)
        {
            combination3 = Y * 100 + tempX2;
        }                                                            


        if (visitedNumbers.count(combination3) == false)
        {
            neighbourY.push_back(Y);
            neighbourX.push_back(tempX2);
            goto continue3;
            
        }
        else if (movementY.size() != visitedNumbers.size())
        {
            neighbourY.push_back(Y);
            neighbourX.push_back(tempX2);
            isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);
        }
        else 
        {
            goto continue3;
        }

    }
       break;

      
       case 3:
        continue3:
        if ( ( X >= 0 ) && ( Y-1 >= 0 ) && ( Y < helperMaze.rows() ) && ( X < helperMaze.columns() ) )
    {
        int tempY2 = Y-1;
        int combination4 = 0;                                          

        if ( tempY2 == 0 && X < 10)
        {
            combination4 = X;
        }
        else if ( (tempY2 < 10 && X < 10) || (tempY2 < 10 && X == 0) )
        {
            combination4 = tempY2 * 10 + X;
        }   
        //NEW
        else if (tempY2 < 100 && X < 100)
        {
            combination4 = tempY2 * 100 + X;
        }   
                                                                 


        if (visitedNumbers.count(combination4) == false)
        {
            neighbourY.push_back(tempY2);
            neighbourX.push_back(X);
        }
        else if (visitedNumbers.size() != movementY.size())
        {
            neighbourY.push_back(tempY2);
            neighbourX.push_back(X);
            isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);
        }
    }
        break;
      
}

 

    if (neighbourY.size() == 0 && neighbourX.size() == 0)
    {
        if (movementY.isEmpty() == false && movementX.isEmpty() == false)
        {
            movementY.pop(); 
            movementX.pop();                                                                
            isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);

            return;
        }
        else 
        {
            std::cout << "assert Y : " << Y << " assert X : " << X << std::endl;
            assert(movementY.isEmpty() == false && movementX.isEmpty() == false);
        }
    }
    else if (neighbourY.size() == 1 && neighbourX.size() == 1)
    {
        int moveY1;
        int moveX1;
        moveY1 = neighbourY.at(0);
        moveX1 = neighbourX.at(0);

        movementY.push(moveY1);
        movementX.push(moveX1);
                                                                                           
        return;
    }
    else if (neighbourY.size() == 2 && neighbourX.size() == 2)
    {
        int randomNumber;
        int moveY2;
        int moveX2;

        //srand(time(0));                                                 
        randomNumber = rand() % 2;

        moveY2 = neighbourY.at(randomNumber);
        moveX2 = neighbourX.at(randomNumber);

        movementY.push(moveY2);
        movementX.push(moveX2);

        return;
    }
    else if (neighbourY.size() == 3 && neighbourX.size() == 3)
    {
        int randomNumber;
        int moveY3;
        int moveX3;

        
        //srand(time(0));                                                 
        randomNumber = rand() % 3;

        moveY3 = neighbourY.at(randomNumber);
        moveX3 = neighbourX.at(randomNumber);

        movementY.push(moveY3);
        movementX.push(moveX3);

        return;
    }
    else if (neighbourY.size() == 4 && neighbourX.size() == 4)
    {
        int randomNumber;
        int moveY4;
        int moveX4;

        
        //srand(time(0));                                                 
        randomNumber = rand() % 3;

        moveY4 = neighbourY.at(randomNumber);
        moveX4 = neighbourX.at(randomNumber);

        movementY.push(moveY4);
        movementX.push(moveX4);

        return;
    }
   
        
    
}



void pathFinder::MazeFinder(const unsigned int cellNumber, MazeBase& Maze, std::set<int>& visitedNumbers,
                            MyStack& movementY, MyStack& movementX, std::string recursion, int Y, int X)
{
    
    const std::string visit = " . ";
    int numberToSet;

    isNeighbour(cellNumber, Y, X, visitedNumbers, movementY, movementX);
    assert (movementY.top() >= 0 && movementX.top() >= 0);
    

    if (movementY.isEmpty() == false && movementX.isEmpty() == false)
    {
        Y = movementY.top();
        X = movementX.top();
        
        //std::cout << "visited: Y:" << Y << " X: " << X << std::endl;

        if (Y == 0 && X < 10)
        {
            numberToSet = X;
        }
        else if (Y < 10 && X < 10)
        {
            numberToSet = Y * 10 + X;
        }
        else if (Y < 100 && X < 100)
        {
            numberToSet = Y * 100 + X;
        }
    }

    if (movementY.isEmpty() == false && movementX.isEmpty() == false)
    {
        replaceWalls(movementY, movementX, Y, X, Maze);
        //std::cout << "direction : " << direction << std::endl;
        //Maze.GetMazeBase();
    }
    
   
    
    if (visitedNumbers.size() == cellNumber-1)                                                                                         
    {
        return;
    }
    else 
    {
        assert (( X >= 0 ) && ( Y >= 0 ) && Y < 1000 && X < 1000 );
        
        visitedNumbers.emplace(numberToSet);

        MazeFinder(cellNumber, Maze, visitedNumbers, movementY, movementX, recursion, Y, X);                       

        return;

    }
}

 
