#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : terrain(), ball(), PlayerOne(), PlayerTwo(), PlayerOneScore(), PlayerTwoScore()
{
}



Terrain &Jeu::getTerrain() { return terrain; }
Ball &Jeu::getBall() { return ball; }
Paddle &Jeu::getPaddle1() { return PlayerOne; }
Paddle &Jeu::getPaddle2() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }
const Ball &Jeu::getConstBall() const { return ball; }
const Paddle &Jeu::getConstPaddle1() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddle2() const { return PlayerTwo; }
const Score &Jeu::getConstPlayerOneScore() const { return PlayerOneScore; }
const Score &Jeu::getConstPlayerTwoScore() const { return PlayerTwoScore; }


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

    //collisions avec murs gauche et droite
    if ( (x == 1.0) || (x == dimx-1) )
    {
        ball.setVelocity(Vec2D(-a, b));
    }
    
        
    //collisions avec murs haut et bas
    if ( (y == 1.0) || (y == dimy-1) )
    {
        
        ball.setVelocity(Vec2D(a, -b));
    }
    

    //collisions avec paddles
    if( (x > x1) && (x < (x1+4) ) && (y > y1) && (y < (y1+5) ))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    if( (x > (dimx - x2 - 5)) && (x < (dimx - x2 ) ) && (y > y2) && (y < (y2+5) ))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    
}

void Jeu::perdu()
{
    float dimx = terrain.getDimX();
    float x = ball.getPosition().getX();
    
    float r1;
    float r2;

    //collisions avec murs gauche 
    if ( x == 1.0 )
    {
        ball.setPosition(Vec2D(40,15));

        do
        {
            r1 = ((rand()) / ((RAND_MAX/3)) - 1 );
            if(r1 < 0) r1 = -r1;


        } while (r1 == 0);
    
        do
        {
            r2 = ((rand()) / ((RAND_MAX/3)) - 1 );
        } while (r2 == 0);

        ball.setVelocity(Vec2D(r1, r2));
        PlayerTwoScore.setScore();
    }

    //collisions avec murs droite
    else if ( x == dimx-1 )
    {
        ball.setPosition(Vec2D(40,15));

        do
        {
            r1 = ((rand()) / ((RAND_MAX/3)) - 1 );
            if(r1 > 0) r1 = -r1;

        } while (r1 == 0);
    
        do
        {
            r2 = ((rand()) / ((RAND_MAX/3)) - 1 );
        } while (r2 == 0);

        ball.setVelocity(Vec2D(r1, r2));
        PlayerOneScore.setScore();
    }
}

void Jeu::actionsAutomatiques()
{
    ball.bougeAuto();
    
    collisions();
    perdu();

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
