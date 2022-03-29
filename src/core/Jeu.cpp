#include "Jeu.h"

Jeu::Jeu()
{
}

Terrain &Jeu::getTerrain() { return ter; }
Paddle &Jeu::getPaddle1() { return player1; }
Paddle &Jeu::getPaddle2() { return player2; }

const Terrain &Jeu::getConstTerrain() const { return ter; }
const Ball &Jeu::getConstBall() const { return b; }
const Paddle &Jeu::getConstPaddle1() const { return player1; }
const Paddle &Jeu::getConstPaddle2() const { return player2; }
