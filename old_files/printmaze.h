/*void printMaze (Matrix matrix, int HEIGHT, int WIDTH)
{
    const std::string CORNER = "+";
    const std::string HORIZONTAL = "---";
    const std::string VERTICAL = "|";
    const std::string CENTER = "   ";

    matrix.initialize({ {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER}, 
                        {VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL}, 
                        {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER},
                        {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER}, 
                        {VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL}, 
                        {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER},
                        {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER}, 
                        {VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL, VERTICAL, CENTER, VERTICAL}, 
                        {CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER, CORNER, HORIZONTAL, CORNER}    
                      });


    for (int x=0; x<HEIGHT; x++)
    {
        for (int y=0; y<WIDTH; y++)
        {
            
            if (y == (WIDTH - 1))
            {
                std::cout << matrix.at(x,y) << std::endl;
                break;
            }

            else if ( y != (WIDTH - 1) &&  matrix.at(x,y) == matrix.at(x, (y+1)) )
            {
                continue;
            }
            else 
            {
                std::cout << matrix.at(x, y);
            }

            if ( x != (HEIGHT - 1) && matrix.at(x, y) == matrix.at((x+1), y) )
            {
                x++;
            } 
        }

        if (x == HEIGHT)
        {
            break;
        }
    }
}*/