#include "txtJeu.h"
#include "../core/Terrain.h"
#include "winTxt.h"

#include <cassert>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <time.h>

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

float temps(clock_t time_start)
{
	clock_t t;
	int f;
	t = clock() - time_start;
	return ((float)t) / CLOCKS_PER_SEC * 1000;
}

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

//TODO : test à supprimer
	// const Ball &BallOne = jeu.getConstBallOne();
	// const Ball &BallTwo = jeu.getConstBallTwo();

	Ball &BallOne = jeu.getBallOne();
	Ball &BallTwo = jeu.getBallTwo();


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
	win.print(BallOne.getPosition().getX(), BallOne.getPosition().getY(), '@');
	win.print(BallTwo.getPosition().getX(), BallTwo.getPosition().getY(), '@');

	// cout << "x1 = " << BallOne.getPosition().getX() << " ,y1 = " << BallOne.getPosition().getY() << endl;
	// cout << "x2 = " << BallTwo.getPosition().getX() << " ,y2 = " << BallTwo.getPosition().getY() << endl;


	// char CharScoreOne = '0' + ScoreOne.getScore();
	// char CharScoreTwo = '0' + ScoreTwo.getScore();
// 
	// cout << CharScoreOne << " " << CharScoreTwo << endl;
	// cout << dimx <<

	win.printScore(1, ScoreOne, dimy);
	win.printScore(2, ScoreTwo, dimy);


	// win.print(10, dimy, CharScoreOne);
	// win.print(1, dimy+1	, CharScoreTwo);

	// Affichage des paddles
	win.printPaddle(PaddleOne.getPosition().x, PaddleOne.getPosition().y, PaddleOne.getPosition().width, PaddleOne.getPosition().height, '#');
	win.printPaddle(PaddleTwo.getPosition().x, PaddleTwo.getPosition().y, PaddleTwo.getPosition().width, PaddleTwo.getPosition().height, '#');

	win.draw();
}

void init(Jeu &jeu)
{
	Terrain &Terrain = jeu.getTerrain();

	Ball &BallOne = jeu.getBallOne();
	Ball &BallTwo = jeu.getBallTwo();

	Paddle &PaddleOne = jeu.getPaddleOne();
	Paddle &PaddleTwo = jeu.getPaddleTwo();

	//TODO : test à supprimer
    // cout << "INIT :" << endl;
	// cout << "x1 = " << BallOne.getPosition().getX() << " ,y1 = " << BallOne.getPosition().getY() << endl;
	// cout << "x2 = " << BallTwo.getPosition().getX() << " ,y2 = " << BallTwo.getPosition().getY() << endl;
	// cout << endl;


	Terrain.setDimensions(TERR_WIDTH, TERR_HEIGHT);

	BallOne.setPosition(Vec2D(TERR_WIDTH / 2, TERR_HEIGHT / 2));
	BallTwo.setPosition(Vec2D(TERR_WIDTH / 2, TERR_HEIGHT / 2));
	
	//TODO : test à supprimer
	// cout << "AFTER INIT :" << endl;
	// cout << "x1 = " << BallOne.getPosition().getX() << " ,y1 = " << BallOne.getPosition().getY() << endl;
	// cout << "x2 = " << BallTwo.getPosition().getX() << " ,y2 = " << BallTwo.getPosition().getY() << endl;
	// cout << endl;


	PaddleOne.setPosition(Vec2D(2, (TERR_HEIGHT / 2) - (PADD_HEIGHT / 2)));
	PaddleOne.setDimension(PADD_WIDTH, PADD_HEIGHT);

	PaddleTwo.setPosition(Vec2D(TERR_WIDTH - 2 - PADD_WIDTH, (TERR_HEIGHT / 2) - (PADD_HEIGHT / 2)));
	PaddleTwo.setDimension(PADD_WIDTH, PADD_HEIGHT);

	PaddleOne.setSpeed(PADD_SPEED);
	PaddleTwo.setSpeed(PADD_SPEED);

//TODO : test à supprimer
	    // cout << "END INIT  : ";
	// cout << "x = " << BallOne.getPosition().getX() << " ,y = " << BallOne.getPosition().getY() << endl;

}

void boucle(Jeu &jeu, clock_t time_start)
{

	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());

	init(jeu);

//TODO : test à supprimer
	// Ball &BallOne = jeu.getBallTwo();
	

	// cout << "POST INIT  : ";
	// cout << "x = " << BallOne.getPosition().getX() << " ,y = " << BallOne.getPosition().getY() << endl;


	bool ok = true;
	int c;

	do
	{
		// cout << temps(time_start) << endl;

//TODO : test à supprimer
			// Ball &BallOne = jeu.getBallTwo();

		// cout << "x = " << BallOne.getPosition().getX() << " ,y = " << BallOne.getPosition().getY() << endl;


			// const Score &ScoreOne = jeu.getConstPlayerOneScore();
	// const Score &ScoreTwo = jeu.getConstPlayerTwoScore();
	// char CharScoreOne = '0' + ScoreOne.getScore();
	// char CharScoreTwo = '0' + ScoreTwo.getScore();

	// cout << CharScoreOne << " " << CharScoreTwo << endl;

		affiche(win, jeu);

	#ifdef _WIN32
			Sleep(100);
	#else
			usleep(100000);
	#endif // WIN32
	//TODO : test à supprimer
			// cout << "PRE AUTO : ";
			// cout << "x = " << BallOne.getPosition().getX() << " ,y = " << BallOne.getPosition().getY() << endl;
			// Ball &BallOne = jeu.getBallOne();
			// Ball &BallTwo = jeu.getBallTwo();
			// cout << "PRE AUTO :" << endl;
	// cout << "x1 = " << BallOne.getPosition().getX() << " ,y1 = " << BallOne.getPosition().getY() << endl;
	// cout << "x2 = " << BallTwo.getPosition().getX() << " ,y2 = " << BallTwo.getPosition().getY() << endl;
	// cout << endl;


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
			//free(&win);
			// delete &win;
			ok = false;
			break;
		}

	} while (ok);
}