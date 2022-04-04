#include "txtJeu.h"
#include "Terrain.h"
#include "winTxt.h"



#include <cassert>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>

#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif
using namespace std;

void txtClear()
{
    system("clear");
}

void affiche(WinTXT & win, Jeu & jeu)
{
    
    
    const Terrain &terrain = jeu.getConstTerrain();
    const Ball &ball = jeu.getConstBall();
    const Paddle &paddle1 = jeu.getConstPaddle1();
    const Paddle &paddle2 = jeu.getConstPaddle2();

    int dimx = terrain.getDimX();
    int dimy = terrain.getDimY();

    
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            win.print(x,y,terrain.getXY(x,y));
             
        }
        
    }
    
    // Affichage de la balle
	win.print(ball.getPosition().getX() , ball.getPosition().getY(), '@');
	
    // Affichage des paddles
	win.printPaddle(paddle1.getPosition().x,3,  paddle1.getPosition().y, 12, '#');
    win.printPaddle(paddle2.getPosition().x,dimx-5, paddle2.getPosition().y, 12 , '#');

	win.draw();
}




void boucle(Jeu & jeu)
{
    // Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    affiche(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'a':
				jeu.actionClavier('a');
				break;
			case 'q':
				jeu.actionClavier('q');
				break;
			case 'p':
				jeu.actionClavier('p');
				break;
			case 'l':
				jeu.actionClavier('l');
				break;
			case 'w':
				ok = false;
				break;
		}

	} while (ok);
}