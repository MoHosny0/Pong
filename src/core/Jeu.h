#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"

class Jeu
{
private:
    Terrain terrain;
    Ball ball;
    Paddle playerOne, playerTwo;
    int playerOneScore, playerTwoScore;

public:
    Jeu();

    Terrain &getTerrain();
    Ball &getBall();
    Paddle &getPaddle1();
    Paddle &getPaddle2();

    const Terrain &getConstTerrain() const;
    const Ball &getConstBall() const;
    const Paddle &getConstPaddle1() const;
    const Paddle &getConstPaddle2() const;
};

#endif