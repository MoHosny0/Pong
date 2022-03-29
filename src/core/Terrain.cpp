#include "Terrain.h"
#include <cassert>

Terrain::Terrain()
{
    dimx = 30;
    dimy = 100;
    for (int x = 0; x < dimx; x++)
    {
        for (int y = 0; y < dimy; y++)
        {
            ter[x][y] = '.';
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