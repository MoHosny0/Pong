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
    Paddle player1, player2;
    int player1_score, player2_score;

public:
    Jeu();

    Terrain &getTerrain();
    Paddle &getPaddle1();
    Paddle &getPaddle2();

    const Terrain &getConstTerrain() const;
    const Ball &getConstBall() const;
    const Paddle &getConstPaddle1() const;
    const Paddle &getConstPaddle2() const;
};

#endif