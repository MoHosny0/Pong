#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"
#include "Score.h"

class Jeu
{
private:
    Terrain terrain;
    Ball ball;
    Paddle PlayerOne, PlayerTwo;
    Score PlayerOneScore, PlayerTwoScore;

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

    const int getPlayerOneScore() const;
    const int getPlayerTwoScore() const;

    void collisions();

    void actionClavier(const char touche);
    void actionsAutomatiques();
    void perdu();
};

#endif