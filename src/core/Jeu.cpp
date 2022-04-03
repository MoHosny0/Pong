#include "Jeu.h"

Jeu::Jeu() : terrain(), ball(), PlayerOne(), PlayerTwo()
{
}

Terrain &Jeu::getTerrain() { return ter; }
Paddle &Jeu::getPaddle1() { return player1; }
Paddle &Jeu::getPaddle2() { return player2; }

const Terrain &Jeu::getConstTerrain() const { return ter; }
const Ball &Jeu::getConstBall() const { return b; }
const Paddle &Jeu::getConstPaddle1() const { return player1; }
const Paddle &Jeu::getConstPaddle2() const { return player2; }

void Jeu::actionsAutomatiques()
{
    ball.bougeAuto(terrain);
}

bool Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'z':
        PlayerOne.haut(terrain);
        break;
    case 's':
        PlayerOne.bas(terrain);
        break;
    case 'o':
        PlayerTwo.haut(terrain);
        break;
    case 'l':
        PlayerTwo.bas(terrain);
    }
    // if (terrain.getXY(ball.getX(), ball.getY())=='.'){
    //   terrain
}
}