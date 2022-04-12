#include "txtJeu.h"
#include "../core/Terrain.h"
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

const int TERR_WIDTH = 80;
const int TERR_HEIGHT = 30;

const int PADD_WIDTH = 2;
const int PADD_HEIGHT = 5;

void txtClear()
{

#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void affiche(WinTXT &win, Jeu &jeu)
{

	const Terrain &terrain = jeu.getConstTerrain();
	const Ball &ball = jeu.getConstBall();
	const Paddle &paddle1 = jeu.getConstPaddle1();
	const Paddle &paddle2 = jeu.getConstPaddle2();
	const Score &score1 = jeu.getConstPlayerOneScore();
	const Score &score2 = jeu.getConstPlayerTwoScore();

	
	txtClear();
	int dimx = terrain.getDimX();
	int dimy = terrain.getDimY();

	
	for (int y = 0; y < dimy; y++)
	{
		for (int x = 0; x < dimx; x++)
		{
			win.print(x, y, terrain.getXY(x, y));
		}
	}

	// Affichage de la balle
	win.print(ball.getPosition().getX(), ball.getPosition().getY(), '@');

	char c1 = '0' + score1.getScore();
	char c2 = '0' + score2.getScore();

	win.print(0, 0, c1);
	win.print(1, 0, c2);


	// Affichage des paddles
		win.printPaddle(paddle1.getPosition().x, paddle1.getPosition().y, PADD_WIDTH, PADD_HEIGHT  ,'#');
		win.printPaddle(paddle2.getPosition().x, paddle2.getPosition().y, PADD_WIDTH, PADD_HEIGHT  ,'#');

	win.draw();
}

void init(Jeu &jeu)
{
	Terrain &terrain = jeu.getTerrain();
	Ball &ball = jeu.getBall();
	Paddle &paddle1 = jeu.getPaddle1();
	Paddle &paddle2 = jeu.getPaddle2();

	
	terrain.setDim(TERR_WIDTH, TERR_HEIGHT);
	ball.setPosition(Vec2D(TERR_WIDTH/2, TERR_HEIGHT/2));
	paddle1.setPosition(Vec2D(2, (TERR_HEIGHT/2) - (PADD_HEIGHT/2)));
	paddle2.setPosition(Vec2D(TERR_WIDTH - 2 - PADD_WIDTH, (TERR_HEIGHT/2) - (PADD_HEIGHT/2)));
}

void boucle(Jeu &jeu)
{
	
	
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());

	init(jeu);

	bool ok = true;
	int c;

	do
	{
		affiche(win, jeu);

#ifdef _WIN32
		Sleep(100);
#else
		usleep(100000);
#endif // WIN32

		jeu.actionsAutomatiques();

		c = win.getCh();
		switch (c)
		{
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