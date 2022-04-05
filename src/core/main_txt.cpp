#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "Terrain.h"
#include "txtJeu.h"
#include "Vec2D.h"
#include <ncurses.h>


int main()
{

    
    Jeu jeu;
    txtClear();
    boucle(jeu);
    txtClear();
    

    return 0;
}