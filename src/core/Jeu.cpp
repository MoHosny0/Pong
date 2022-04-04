#include "Jeu.h"
#include <iostream>
using namespace std;

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

void Jeu::collisions()
{
    float x = ball.getPosition().getX();
    float y = ball.getPosition().getY();

    float x1 = PlayerOne.getPosition().x;
    float y1 = PlayerOne.getPosition().y;

    float x2 = PlayerTwo.getPosition().x;
    float y2 = PlayerTwo.getPosition().y;

   
    float a = ball.getVelocity().getX();
    float b = ball.getVelocity().getY();

    float dimx = terrain.getDimX();
    float dimy = terrain.getDimY();

    if ( (x == 1.0) || (x == dimx-1) )
    {
        ball.setVelocity(Vec2D(-a, b));
    }
    
        

    if ( (y == 1.0) || (y == dimy-1) )
    {
        
        ball.setVelocity(Vec2D(a, -b));
    }
    

    if( (x > x1) && (x < (x1+4) ) && (y > y1) && (y < (y1+5) ))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    if( (x > (dimx - x2 - 5)) && (x < (dimx - x2 ) ) && (y > y2) && (y < (y2+5) ))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    
}

void Jeu::actionsAutomatiques()
{
    ball.bougeAuto();
    
    collisions();
}

void Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'a':
        PlayerOne.haut(terrain);
        break;

    case 'q':
        PlayerOne.bas(terrain);
        break;

    case 'p':
        PlayerTwo.haut(terrain);
        break;

    case 'l':
        PlayerTwo.bas(terrain);
        break;
    }
    
}
