#include "Terrain.h"
#include <cassert>

Terrain::Terrain()
{
    dimx = 80;
    dimy = 30;
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            if (y == 0 || y == dimy - 1) 
            {
                ter[x][y] = '_';
            }
            else if ((x == 0 && y != 0 && y != dimy-1) || (x == dimx-1 && y != 0 && y != dimy-1) )
            {
                ter[x][y] = '|';
            }
            else 
            {
                ter[x][y] = '.';
            }

            // ter[x][y] = '*';
            
        }
    }
}

int Terrain::getDimX() const
{
    return dimx;
}

int Terrain::getDimY() const
{
    return dimy;
}

char Terrain::getXY(const int x, const int y) const
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < dimx);
    assert(y < dimy);
    return ter[x][y];
}