#include "Jeu.h"

Jeu::Jeu()
{
    
}

Terrain &Jeu::getTerrain() { return terrain; }
Ball &Jeu::getBall() { return ball; }
Paddle &Jeu::getPaddle1() { return playerOne; }
Paddle &Jeu::getPaddle2() { return playerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }
const Ball &Jeu::getConstBall() const { return ball; }
const Paddle &Jeu::getConstPaddle1() const { return playerOne; }
const Paddle &Jeu::getConstPaddle2() const { return playerTwo; }
