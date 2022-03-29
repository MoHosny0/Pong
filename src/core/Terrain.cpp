#include "Terrain.h"
#include <cassert>

Terrain::Terrain()
{
    dimx = 100;
    dimy = 100;
    for(int i = 0; i <dimx; i++)
    {
        for(int j = 0; j <dimy; j++)
        {
            ter[j][i] = '.';
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

char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return ter[x][y];
}