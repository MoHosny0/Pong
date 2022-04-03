#include "Jeu.h"

Jeu::Jeu() : terrain(), ball(), PlayerOne(), PlayerTwo()
{
}

Terrain &Jeu::getTerrain() { return terrain; }
Paddle &Jeu::getPaddle1() { return PlayerOne; }
Paddle &Jeu::getPaddle2() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }
const Ball &Jeu::getConstBall() const { return ball; }
const Paddle &Jeu::getConstPaddle1() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddle2() const { return PlayerTwo; }

void Jeu::actionsAutomatiques()
{
    ball.bougeAuto(terrain);
}

bool Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'q':
        PlayerOne.haut(terrain);
        break;
    case 'a':
        PlayerOne.bas(terrain);
        break;
    case 'p':
        PlayerTwo.haut(terrain);
        break;
    case 'l':
        PlayerTwo.bas(terrain);
    }
    // if (terrain.getXY(ball.getX(), ball.getY())=='.'){
    //   terrain
}
