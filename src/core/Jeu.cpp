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

void Jeu::collisions()
{
    float x = ball.getPosition().getX();
    float y = ball.getPosition().getY();

    float x1 = PlayerOne.getPosition().x;
    float y1 = PlayerOne.getPosition().y;

    float x2 = PlayerTwo.getPosition().x;
    float y2 = PlayerTwo.getPosition().y;

    float a = ball.getVelocity().getX();
    float b = ball.getVelocity().getY();

    float dimx = terrain.getDimX();
    float dimy = terrain.getDimY();

    // collisions avec murs gauche et droite
    if ((x == 1.0) || (x == dimx - 1))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    // collisions avec murs haut et bas
    if ((y == 1.0) || (y == dimy - 1))
    {

        ball.setVelocity(Vec2D(a, -b));
    }

    // collisions avec paddles
    if ((x > x1) && (x < (x1 + 4)) && (y > y1) && (y < (y1 + 5)))
    {
        ball.setVelocity(Vec2D(-a, b));
    }

    if ((x > (dimx - x2 - 5)) && (x < (dimx - x2)) && (y > y2) && (y < (y2 + 5)))
    {
        ball.setVelocity(Vec2D(-a, b));
    }
}

// fonction too long and repetitive. create function to handle both goal sides
void Jeu::perdu()
{
    int WINDOW_WIDTH = terrain.getDimX();
    int WINDOW_HEIGHT = terrain.getDimY();
    float ballPosition = ball.getPosition().getX();

    cout << "Terrain Dim X: " << WINDOW_WIDTH << endl;
    cout << "Terrain Dim Y: " << WINDOW_HEIGHT << endl;
    cout << "Ball Horizontal Position:" << ballPosition << endl;

    float randOne;
    float randTwo;

    // but à gauche
    if (ballPosition == 1.0)
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
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition == WINDOW_WIDTH - 1)
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
