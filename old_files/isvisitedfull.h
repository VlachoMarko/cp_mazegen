#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cstdlib>
#include "matrix.h"
#ifndef ISVISITEDFULL_h
#define ISVISITEDFULL_h

bool isVisitedFull (Matrix visited)
{
     int newheight = visited.rows();
     int newwidth = visited.columns();

    for ( int rows=0; rows<newheight; rows++)
    {
        for ( int columns=0; columns<newwidth; columns++)
        {
            assert(rows < newheight && columns < newwidth);

            if (visited.isEmptyAt(rows, columns) == false)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    return true;   
}

#endif
