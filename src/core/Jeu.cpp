#include "Jeu.h"

Jeu::Jeu() {}

Terrain &Jeu::getTerrain() { return terrain; }
Ball &Jeu::getBall() { return ball; }
Paddle &Jeu::getPaddle1() { return PlayerOne; }
Paddle &Jeu::getPaddle2() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }
const Ball &Jeu::getConstBall() const { return ball; }
const Paddle &Jeu::getConstPaddle1() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddle2() const { return PlayerTwo; }
