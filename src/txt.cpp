
#include "txt.h"
#include "Terrain.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void txtClear()
{
    system("clear");
}

void affiche(Terrain terr)
{
    int dimx = terr.getDimX();
    int dimy = terr.getDimY();
    for(int x = 0; x < dimx; x++)
    {
        for(int y = 0; y < dimy; y++)
        {
            cout << terr.getXY(x,y);
        }
        cout << endl;
    }
}