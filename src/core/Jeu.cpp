#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : terrain(), BallOne(), BallTwo(), PlayerOne(), PlayerTwo(), PlayerOneScore(), PlayerTwoScore()
{
}

Terrain &Jeu::getTerrain() { return terrain; }

Ball &Jeu::getBallOne() { return BallOne; }
Ball &Jeu::getBallTwo() { return BallTwo; }

Paddle &Jeu::getPaddleOne() { return PlayerOne; }
Paddle &Jeu::getPaddleTwo() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }

const Ball &Jeu::getConstBallOne() const { return BallOne; }
const Ball &Jeu::getConstBallTwo() const { return BallTwo; }

const Paddle &Jeu::getConstPaddleOne() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddleTwo() const { return PlayerTwo; }

const Score &Jeu::getConstPlayerOneScore() const { return PlayerOneScore; }
const Score &Jeu::getConstPlayerTwoScore() const { return PlayerTwoScore; }

void Jeu::collisions() 
{
    float ballOneHorizontal = BallOne.getPosition().getX();
    float ballOneVertical = BallOne.getPosition().getY();

    float ballTwoHorizontal = BallTwo.getPosition().getX();
    float ballTwoVertical = BallTwo.getPosition().getY();

    float paddleOneHorizontal = PlayerOne.getPosition().x;
    float paddleOneVertical = PlayerOne.getPosition().y;
    float paddleOneHeight = PlayerOne.getPosition().height;
    float paddleOneWidth = PlayerOne.getPosition().width;

    float paddleTwoHorizontal = PlayerTwo.getPosition().x;
    float paddleTwoVertical = PlayerTwo.getPosition().y;
    float paddleTwoHeight = PlayerTwo.getPosition().height;
    float paddleTwoWidth = PlayerTwo.getPosition().width;

    float ballOneVectorX = BallOne.getVelocity().getX();
    float ball1VectorY = BallOne.getVelocity().getY();

    float ballTwoVectorX = BallTwo.getVelocity().getX();
    float ball2VectorY = BallTwo.getVelocity().getY();

    float WINDOW_WIDTH = terrain.getDimX();
    float WINDOW_HEIGHT = terrain.getDimY();

    // collisions avec murs haut et bas
    if ((ballOneVertical <= 1.0) || (ballOneVertical >= WINDOW_HEIGHT - 1))
    {

        BallOne.setVelocity(Vec2D(ballOneVectorX, -ball1VectorY));
    }

    // collisions avec paddles
    if ((ballOneHorizontal > paddleOneHorizontal) && (ballOneHorizontal < (paddleOneHorizontal + paddleOneWidth)) && (ballOneVertical > paddleOneVertical) && (ballOneVertical < (paddleOneVertical + paddleOneHeight)))
    {
        BallOne.setVelocity(Vec2D(-ballOneVectorX, ball1VectorY));
    }

    if ((ballOneHorizontal > (paddleTwoHorizontal - 1)) && (ballOneHorizontal < (paddleTwoHorizontal + paddleTwoWidth)) && (ballOneVertical > paddleTwoVertical) && (ballOneVertical < (paddleTwoVertical + paddleTwoHeight)))
    {
        BallOne.setVelocity(Vec2D(-ballOneVectorX, ball1VectorY));
    }

    /*COLLISIONS BALL2*/
    // collisions avec murs haut et bas
    if ((ballTwoVertical <= 1.0) || (ballTwoVertical >= WINDOW_HEIGHT - 1))
    {
        BallTwo.setVelocity(Vec2D(ballTwoVectorX, -ball2VectorY));
    }

    // collisions avec paddles
    if ((ballTwoHorizontal > paddleOneHorizontal) && (ballTwoHorizontal < (paddleOneHorizontal + paddleOneWidth)) && (ballTwoVertical > paddleOneVertical) && (ballTwoVertical < (paddleOneVertical + paddleOneHeight)))
    {
        BallTwo.setVelocity(Vec2D(-ballTwoVectorX, ball2VectorY));
    }

    if ((ballTwoHorizontal > (paddleTwoHorizontal - 1)) && (ballTwoHorizontal < (paddleTwoHorizontal + paddleTwoWidth)) && (ballTwoVertical > paddleTwoVertical) && (ballTwoVertical < (paddleTwoVertical + paddleTwoHeight)))
    {
        BallTwo.setVelocity(Vec2D(-ballTwoVectorX, ball2VectorY));
    }
}

void Jeu::perdu()
{
    int WINDOW_WIDTH = terrain.getDimX();
    int WINDOW_HEIGHT = terrain.getDimY();
    float ballPosition = BallOne.getPosition().getX();
    float ballPosition2 = BallTwo.getPosition().getX();

    int FLOAT_MIN = -1;
    int FLOAT_MAX = 1;

    float randOne;
    float randTwo;

    /*BALL1*/
    // but à gauche
    if (ballPosition <= 1.0)
    {
        BallOne.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)); // Devrait etre WINDOW_HEIGHT ET WIDTH COMME SDLJEU.CPP

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
            if (randOne < 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        BallOne.setVelocity(Vec2D(randOne, randTwo));
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition >= WINDOW_WIDTH - 1)
    {
        BallOne.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
            if (randOne > 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        BallOne.setVelocity(Vec2D(randOne, randTwo));
        PlayerOneScore.setScore();
    }

    /*BALL2*/
    // but à gauche
    if (ballPosition2 <= 1.0)
    {
        BallTwo.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)); // Devrait etre WINDOW_HEIGHT ET WIDTH COMME SDLJEU.CPP

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
            if (randOne < 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        BallTwo.setVelocity(Vec2D(randOne, randTwo));
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition2 >= WINDOW_WIDTH - 1)
    {
        BallTwo.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
            if (randOne > 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        BallTwo.setVelocity(Vec2D(randOne, randTwo));
        PlayerOneScore.setScore();
    }
}


void Jeu::actionsAutomatiques()
{
    BallOne.bougeAuto();
    BallTwo.bougeAuto();
    collisions();
    perdu();
}

void Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'q':
        PlayerOne.bas(terrain);
        break;

    case 'a':
        PlayerOne.haut(terrain);
        break;

    case 'p':
        PlayerTwo.haut(terrain);
        break;

    case 'l':
        PlayerTwo.bas(terrain);
        break;
    }
}
