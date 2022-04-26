#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : terrain(), ball(), PlayerOne(), PlayerTwo(), PlayerOneScore(), PlayerTwoScore()
{
}

Terrain &Jeu::getTerrain() { return terrain; }
Ball &Jeu::getBall() { return ball; }
Paddle &Jeu::getPaddleOne() { return PlayerOne; }
Paddle &Jeu::getPaddleTwo() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }
const Ball &Jeu::getConstBall() const { return ball; }
const Paddle &Jeu::getConstPaddleOne() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddleTwo() const { return PlayerTwo; }
const Score &Jeu::getConstPlayerOneScore() const { return PlayerOneScore; }
const Score &Jeu::getConstPlayerTwoScore() const { return PlayerTwoScore; }

void Jeu::collisions() // accourcir les nom de variables, lignes trop longues.
{
    float ballHorizontal = ball.getPosition().getX();
    float ballVertical = ball.getPosition().getY();

    float paddleOneHorizontal = PlayerOne.getPosition().x;
    float paddleOneVertical = PlayerOne.getPosition().y;
    float paddleOneHeight = PlayerOne.getPosition().height;
    float paddleOneWidth = PlayerOne.getPosition().width;

    float paddleTwoHorizontal = PlayerTwo.getPosition().x;
    float paddleTwoVertical = PlayerTwo.getPosition().y;
    float paddleTwoHeight = PlayerTwo.getPosition().height;
    float paddleTwoWidth = PlayerTwo.getPosition().width;

    float ballVectorX = ball.getVelocity().getX();
    float ballVectorY = ball.getVelocity().getY();

    float WINDOW_WIDTH = terrain.getDimX();
    float WINDOW_HEIGHT = terrain.getDimY();

    // collisions avec murs gauche et droite
    if ((ballHorizontal <= 1.0) || (ballHorizontal >= WINDOW_WIDTH - 1))
    {
        // std::cout << "Ball touched wall at " << ballHorizontal << std::endl;
        ball.setVelocity(Vec2D(-ballVectorX, ballVectorY));
    }

    // collisions avec murs haut et bas
    if ((ballVertical <= 1.0) || (ballVertical >= WINDOW_HEIGHT - 1))
    {

        ball.setVelocity(Vec2D(ballVectorX, -ballVectorY));
    }

    // collisions avec paddles
    if ((ballHorizontal > paddleOneHorizontal) && (ballHorizontal < (paddleOneHorizontal + paddleOneWidth)) && (ballVertical > paddleOneVertical) && (ballVertical < (paddleOneVertical + paddleOneHeight)))
    {
        ball.setVelocity(Vec2D(-ballVectorX, ballVectorY));
    }

    if ((ballHorizontal > (WINDOW_WIDTH - paddleTwoHorizontal - paddleTwoWidth)) && (ballHorizontal < (WINDOW_WIDTH - paddleTwoHorizontal)) && (ballVertical > paddleTwoVertical) && (ballVertical < (paddleTwoVertical + paddleTwoHeight)))
    {
        ball.setVelocity(Vec2D(-ballVectorX, ballVectorY));
    }
}

// fonction too long and repetitive. create function to handle both goal sides
void Jeu::perdu()
{
    int WINDOW_WIDTH = terrain.getDimX();
    int WINDOW_HEIGHT = terrain.getDimY();
    float ballPosition = ball.getPosition().getX();

    // cout << "Terrain Dim X: " << WINDOW_WIDTH << endl;
    // cout << "Terrain Dim Y: " << WINDOW_HEIGHT << endl;
    // cout << "Ball Horizontal Position:" << ballPosition << endl;

    float randOne;
    float randTwo;

    // but à gauche
    if (ballPosition <= 1.0)
    {
        ball.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)); // Devrait etre WINDOW_HEIGHT ET WIDTH COMME SDLJEU.CPP

        do
        {
            randOne = ((rand()) / ((RAND_MAX / 3)) - 1);
            if (randOne < 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = ((rand()) / ((RAND_MAX / 3)) - 1);
        } while (randTwo == 0);

        ball.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition >= WINDOW_WIDTH - 1)
    {
        ball.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        do
        {
            randOne = ((rand()) / ((RAND_MAX / 3)) - 1);
            if (randOne > 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = ((rand()) / ((RAND_MAX / 3)) - 1);
        } while (randTwo == 0);

        ball.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerOneScore.setScore();
    }
}

// void Jeu::buts() {} // handle goals and reposition ball

void Jeu::actionsAutomatiques()
{
    ball.bougeAuto();
    collisions();
    perdu();
}

void Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'q':
        PlayerOne.haut(terrain);
        break;

    case 'a':
        PlayerOne.bas(terrain);
        break;

    case 'p':
        PlayerTwo.haut(terrain);
        break;

    case 'l':
        PlayerTwo.bas(terrain);
        break;
    }
}
