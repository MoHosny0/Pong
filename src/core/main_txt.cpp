#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "Terrain.h"
#include "txtJeu.h"
#include "Vec2D.h"
#include <ncurses.h>


int main()
{

    // initscr();              // Initialise la structure WINDOW et autres paramètres 
    // printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
    // refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    // getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    // endwin(); 

    Jeu jeu;
    txtClear();
    boucle(jeu);
    txtClear();
    
    // char ch;
    // while (ch != 'a')
    // {
    // ch = getcha();
    // std::cout << ch << std::endl;
    // }

    return 0;
}