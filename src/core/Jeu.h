#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"
#include "Score.h"

/**
@brief Un jeu (de pong) = un terrain, une balle et 2 paddles.
*/
class Jeu
{
private:
    Terrain terrain;
    Ball ball;
    Paddle PlayerOne, PlayerTwo;
    Score PlayerOneScore, PlayerTwoScore;

public:
    /**
    @brief Met en place un terrain, la balle, les  paddles et le score des joueurs.
    */
    Jeu();

    /**
    @brief Renvoie un terrain.
     */
    Terrain &getTerrain();

    /**
    @brief Renvoie une balle.
     */
    Ball &getBall();

    /**
    @brief Renvoie le premier Paddle.
     */
    Paddle &getPaddle1();

    /**
    @brief Renvoie le deuxième Paddle.
     */
    Paddle &getPaddle2();

    /**
   @brief Renvoie un terrain.
    */
    const Terrain &getConstTerrain() const;

    /**
    @brief Renvoie une balle.
     */
    const Ball &getConstBall() const;

    /**
   @brief Renvoie le premier Paddle.
    */
    const Paddle &getConstPaddle1() const;

    /**
    @brief Renvoie le deuxième Paddle.
     */
    const Paddle &getConstPaddle2() const;

    /**
   @brief Renvoie le score du joueur 1.
   */
    const int getPlayerOneScore() const;

    /**
   @brief Renvoie le score du joueur 2.
   */
    const int getPlayerTwoScore() const;

    /**
     @brief Modifie la direction de la balle en cas de collision soit avec les murs soit avec les paddles.
     */
    void collisions();

    /**
     @brief Déplace les paddles en haut ou enbas en fonction de al touche du clavier.
     @param touche: touche du clavier.
    */
    void actionClavier(const char touche);

    /**
     @brief Met en action le mouvement de la balle, la fonction colision, et la fonction perdu.
     */
    void actionsAutomatiques();

    /**
    @brief Teste si la balle dépasse l'un des cotés (droite ou gauche) du terrain. Si la balle dépasse ça redémarre le jeu et modifie le score.
    */
    void perdu();
};

#endif