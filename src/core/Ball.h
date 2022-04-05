#include "Vec2D.h"
#include "Terrain.h"
#ifndef BALL_H
#define BALL_H

/**
@brief Une balle = sa position, sa vitesse et sa taille.
*/
class Ball
{
private:
    Vec2D position;
    Vec2D velocity;
    float radius;

public:
    /**
    @brief <B>Construit</B> un objet Ball.
    */
    Ball();

    /**
    @brief <B>Construit</B> un objet Ball et l'initialise avec une position, une vitesse et une taille.
    */
    Ball(const Vec2D &InitialPosition, const float BallRadius);

    /**
    @brief  Renvoie un vec2D contenent la position de l'objet Ball.
    */
    const Vec2D &getPosition() const;

    /**
    @brief  Renvoie un vec2D contenent la vitesse de l'objet Ball.
    */
    const Vec2D &getVelocity() const;

    /**
    @brief  Renvoie le rayon de l'objet Ball.
    */
    const float &getRadius() const;

    /**
    @brief  Modifie la position de l'objet Ball.
    @param NewPosition: Vec2D position.
    */
    void setPosition(const Vec2D &NewPosition);

    /**
    @brief  Modifie la vitesse de l'objet Ball.
    @param NewVelocity: Vec2D vitesse.
    */
    void setVelocity(const Vec2D &NewVelocity);

    /**
    @brief  Modifie le rayon de l'objet Ball.
    @param NewRadius: longueur du rayon.
    */
    void setRadius(const float NewRadius);

    /**
    @brief fait bouger la balle automatiquement.
    */
    void bougeAuto(/*const Terrain &t*/);
};
#endif