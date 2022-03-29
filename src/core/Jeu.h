#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"

class jeu
{
private:
    Terrain ter;
    Ball b;
    Paddle p;

public:
    jeu();
};

#endif