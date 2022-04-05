#ifndef VEC2D_H
#define VEC2D_H

/**
@brief Un vecteur2D 
*/
class Vec2D
{
private:
    float x, y;

public:

    /**
     @brief
    Initialise un vecteur null.
    */
    Vec2D() : x(0.0f), y(0.0f) {}

    /**
    @brief
    Initialise un vecteur avec X et Y.
    */
    Vec2D(float x, float y) : x(x), y(y) {}

    /**
    @brief
    Opérateur de sommation de 2 vecteurs.
    */
    Vec2D operator+(Vec2D const &V);

    /**
    @brief
    Opérateur d'addition de 2 vecteurs.
    */
    Vec2D &operator+=(Vec2D const &V);

    /**
    @brief
    Opérateur de multiplication d'un vecteur avec une constante.
    */
    Vec2D operator*(float k);

    /**
    @brief  Renvoie l'abs du vecteur.
    */
    float getX() const;

    /**
    @brief  Renvoie l'ordonnée du vecteur.
    */
    float getY() const;

    /**
    @brief  Donne une valeur à l'abscisse du vectur.
    */
    void setX(const float x_);

    /**
    @brief  Donne une valeur à l'ordonnée du vecteur.
    */
    void setY(const float y_);
};
#endif