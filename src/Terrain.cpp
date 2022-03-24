#include "Terrain.h"

Terrain::Terrain()
{
    dimx = 100;
    dimy = 100;
    for(int i = 0; i <dimx; i++)
    {
        for(int j = 0; j <dimy; j++)
        {
            ter[y][x] == ".";
        }
    }
}

Terrain::getDimX()
{
    return dimx;
}

Terrain::getDimY()
{
    return dimy;
}

char Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	return m_ter[x][y];
}