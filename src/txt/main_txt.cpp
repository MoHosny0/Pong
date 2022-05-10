#include <iostream>
#include "txtJeu.h"
#include <time.h>

int main()
{
    clock_t time_start = clock();
    srand(time(NULL));
    Jeu jeu;
    txtClear();
    boucle(jeu, time_start);
    txtClear();

    return 0;
}