#include "txtJeu.h"
#include "../core/Terrain.h"
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
    cout << dimx << " " << dimy << endl;
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            cout << terr.getXY(x, y);
            // cout << "[" << x << "," << y << "]";

        }
        cout << endl;
    }
}
void boucle(Terrain terr)
{
    bool ok = true;
    do
    {

    } while (ok);
}