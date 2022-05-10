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
const int PADD_SPEED = 1;

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

	const Terrain &Terrain = jeu.getConstTerrain();

	const Ball &Ball1 = jeu.getConstBall1();
	const Ball &Ball2 = jeu.getConstBall2();
	
	const Paddle &PaddleOne = jeu.getConstPaddleOne();
	const Paddle &PaddleTwo = jeu.getConstPaddleTwo();
	
	const Score &ScoreOne = jeu.getConstPlayerOneScore();
	const Score &ScoreTwo = jeu.getConstPlayerTwoScore();

	txtClear();
	int dimx = Terrain.getDimX();
	int dimy = Terrain.getDimY();

	for (int y = 0; y < dimy; y++)
	{
		for (int x = 0; x < dimx; x++)
		{
			win.print(x, y, Terrain.getXY(x, y));
		}
	}

	// Affichage de la balle
	win.print(Ball1.getPosition().getX(), Ball1.getPosition().getY(), '@');
	win.print(Ball2.getPosition().getX(), Ball1.getPosition().getY(), '@');

	char CharScoreOne = '0' + ScoreOne.getScore();
	char CharScoreTwo = '0' + ScoreTwo.getScore();

	win.print(0, 0, CharScoreOne);
	win.print(1, 0, CharScoreTwo);

	// Affichage des paddles
	win.printPaddle(PaddleOne.getPosition().x, PaddleOne.getPosition().y, PaddleOne.getPosition().width, PaddleOne.getPosition().height, '#');
	win.printPaddle(PaddleTwo.getPosition().x, PaddleTwo.getPosition().y, PaddleTwo.getPosition().width, PaddleTwo.getPosition().height, '#');

	win.draw();
}

void init(Jeu &jeu)
{
	Terrain &Terrain = jeu.getTerrain();
	
	Ball &Ball1 = jeu.getBall1();
	Ball &Ball2 = jeu.getBall1();
	
	Paddle &PaddleOne = jeu.getPaddleOne();
	Paddle &PaddleTwo = jeu.getPaddleTwo();

	Terrain.setDimensions(TERR_WIDTH, TERR_HEIGHT);
	
	Ball1.setPosition(Vec2D(TERR_WIDTH / 2, TERR_HEIGHT / 2));
	Ball2.setPosition(Vec2D(TERR_WIDTH / 2, TERR_HEIGHT / 2));
	
	PaddleOne.setPosition(Vec2D(2, (TERR_HEIGHT / 2) - (PADD_HEIGHT / 2)));
	PaddleOne.setDimension(PADD_WIDTH, PADD_HEIGHT);

	PaddleTwo.setPosition(Vec2D(TERR_WIDTH - 2 - PADD_WIDTH, (TERR_HEIGHT / 2) - (PADD_HEIGHT / 2)));
	PaddleTwo.setDimension(PADD_WIDTH, PADD_HEIGHT);

	PaddleOne.setSpeed(PADD_SPEED);
	PaddleTwo.setSpeed(PADD_SPEED);
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