#ifndef PADDLE_H
#define PADDLE_H

#include "Vec2D.h"
#include "Terrain.h"

/**
 * @brief Un rectangle symbolisant le paddle
 * 
 */
struct Rectangle
{
    float x;
    float y;
    int height;
    int width;
    int speed;
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
   @brief  Renvoie la position du rectangle
   @return un rectangle
   */
    const Rectangle &getPosition() const;

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


    void setDimension(const int x, const int y);

    void setSpeed(const int x);
};

#endif