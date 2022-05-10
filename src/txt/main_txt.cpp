#include <iostream>
#include "txtJeu.h"

int main()
{
    srand(time(NULL));
    Jeu jeu;
    txtClear();
    boucle(jeu);
    txtClear();

    return 0;
}