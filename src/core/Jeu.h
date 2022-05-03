#ifndef JEU_H
#define JEU_H

#include "Paddle.h"
#include "Terrain.h"
#include "Ball.h"
#include "Score.h"

/**
@brief Un jeu (de pong) = un terrain, une balle, 2 paddles et 2 Score.
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
    @brief Met en place un terrain, la balle, les paddles et le score des joueurs.
    */
    Jeu();

    /**
    @brief Renvoie un terrain.
    @return le terrain
     */
    Terrain &getTerrain();

    /**
    @brief Renvoie une balle.
    @return la balle 
    */
    Ball &getBall();

    /**
    @brief Renvoie le premier Paddle.
    @return le paddle 1
    */
    Paddle &getPaddleOne();

    /**
    @brief Renvoie le deuxième Paddle.
    @return le paddle 2
    */
    Paddle &getPaddleTwo();

    /**
   @brief Renvoie un terrain.
   @return le terrain
    */
    const Terrain &getConstTerrain() const;

    /**
    @brief Renvoie une balle.
    @return La balle
     */
    const Ball &getConstBall() const;

    /**
   @brief Renvoie le premier Paddle.
   @return Le paddle 1
    */
    const Paddle &getConstPaddleOne() const;

    /**
    @brief Renvoie le deuxième Paddle.
    @return Le paddle 2
     */
    const Paddle &getConstPaddleTwo() const;

    /**
   @brief Renvoie le score du joueur 1.
   @return Le score du joueur 1
   */
    const int getPlayerOneScore() const;

    /**
   @brief Renvoie le score du joueur 2.
   @return Le score du joueur 2
   */
    const int getPlayerTwoScore() const;

    /**
   @brief Renvoie PlayerOneScore.
   @return Le score du joueur 1
   */
    const Score &getConstPlayerOneScore() const;

    /**
   @brief Renvoie PlayerTwoScore.
   @return Le score du joueur 2
   */
    const Score &getConstPlayerTwoScore() const;

    /**
     @brief Modifie la direction de la balle en cas de collision soit avec les murs soit avec les paddles.
     */
    void collisions();

    /**
     @brief Déplace les paddles en haut ou en bas en fonction de la touche du clavier.
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