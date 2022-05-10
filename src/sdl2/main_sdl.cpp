#include "sdlJeu.h"
#include <iostream>

int main()
{
    srand(time(NULL));
    Jeu j;
    sdlJeu sj;
    sj.sdlBoucle(j);
}
