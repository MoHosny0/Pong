#include "Terrain.h"
#include <cassert>
#include <iostream>

Terrain::Terrain()
{
    dimX = 80;
    dimY = 30;
    for (int y = 0; y < dimY; y++) // peut on effectuer le dessin TXT hors de la classe Terrain??
    {
        for (int x = 0; x < dimX; x++)
        {
            if (y == 0 || y == dimY - 1)
            {
                ter[x][y] = '_';
            }
            else if ((x == 0 && y != 0 && y != dimY - 1) || (x == dimX - 1 && y != 0 && y != dimY - 1))
            {
                ter[x][y] = '|';
            }
            else
            {
                ter[x][y] = '.';
            }
        }
    }
}

bool Terrain::posEstValide(const int x, const int y) const
{
    return (x >= 0 && x < dimX && y >= 0 && y < dimY);
}

int Terrain::getDimX() const
{
    return dimX;
}

int Terrain::getDimY() const
{
    return dimY;
}

char Terrain::getXY(const int x, const int y) const
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < dimX);
    assert(y < dimX);
    return ter[x][y];
}

void Terrain::setDimensions(const int x, const int y)
{
    dimX = x;
    dimY = y;
}
