#ifndef PADDLE_H
#define PADDLE_H

#include "Vec2D.h"
#include "Terrain.h"

struct Rectangle
{
    float x;
    float y;
};

/**
@brief Un paddle = la position.
*/
class Paddle
{

private:
    Rectangle rect;

public:
    /**
   @brief <B>Construit</B> un objet Paddle.
   Le constructeur definit la position par default du paddle.
   */
    Paddle();

    /**
     @brief <B>Construit</B> un objet Paddle.
     Le constructeur definit la position choisit du paddle.
    @param StartingPosition: position de depart
    */
    Paddle(const Rectangle StartingPosition);

    /**
   @brief  R.
   */
    const Rectangle &getPosition() const;

    void setPositionSize(const Rectangle NewPositionSize);

    /**
    @brief  Modifie la position de l'objet Paddle.
    @param NewPosition: Vec2D position.
    */
    void setPosition(const Vec2D NewPosition);

    /**
    @brief  Modifie la position du Paddle et bouge l'objet Paddle une position vers le haut .
    @param T: Terrain dans lequel Paddle bouge.
    */
    void haut(const Terrain &T);

    /**
   @brief  Modifie la position du Paddle et bouge l'objet Paddle une position vers le bas .
   @param T: Terrain dans lequel Paddle bouge.
   */
    void bas(const Terrain &T);
};

#endif