#include "Jeu.h"

Jeu::Jeu()
{
}

Terrain &Jeu::getTerrain() { return ter; }
Paddle &Jeu::getPaddle() { return p; }

const Terrain &Jeu::getConstTerrain() const { return ter; }
const Ball &Jeu::getConstBall() const { return b; }
const Paddle &Jeu::getConstPaddle() const { return p; }
