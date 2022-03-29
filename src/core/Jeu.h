#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"

class Jeu
{
private:
    Terrain ter;
    Ball b;
    Paddle p;
    int player1_score, player2_score;
    Paddle player1, player2;

public:
    Jeu();

    Terrain &getTerrain();
    Paddle &getPaddle();

    const Terrain &getConstTerrain() const;
    const Ball &getConstBall() const;
    const Paddle &getConstPaddle() const;
};

#endif