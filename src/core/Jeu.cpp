#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() : terrain(), ball1(), ball2(), PlayerOne(), PlayerTwo(), PlayerOneScore(), PlayerTwoScore()
{
}

Terrain &Jeu::getTerrain() { return terrain; }

Ball &Jeu::getBall1() { return ball1; }
Ball &Jeu::getBall2() { return ball2; }

Paddle &Jeu::getPaddleOne() { return PlayerOne; }
Paddle &Jeu::getPaddleTwo() { return PlayerTwo; }

const Terrain &Jeu::getConstTerrain() const { return terrain; }

const Ball &Jeu::getConstBall1() const { return ball1; }
const Ball &Jeu::getConstBall2() const { return ball2; }

const Paddle &Jeu::getConstPaddleOne() const { return PlayerOne; }
const Paddle &Jeu::getConstPaddleTwo() const { return PlayerTwo; }

const Score &Jeu::getConstPlayerOneScore() const { return PlayerOneScore; }
const Score &Jeu::getConstPlayerTwoScore() const { return PlayerTwoScore; }

void Jeu::collisions() // accourcir les nom de variables, lignes trop longues.
{
    float ball1Horizontal = ball1.getPosition().getX();
    float ball1Vertical = ball1.getPosition().getY();

    float ball2Horizontal = ball2.getPosition().getX();
    float ball2Vertical = ball2.getPosition().getY();

    float paddleOneHorizontal = PlayerOne.getPosition().x;
    float paddleOneVertical = PlayerOne.getPosition().y;
    float paddleOneHeight = PlayerOne.getPosition().height;
    float paddleOneWidth = PlayerOne.getPosition().width;

    float paddleTwoHorizontal = PlayerTwo.getPosition().x;
    float paddleTwoVertical = PlayerTwo.getPosition().y;
    float paddleTwoHeight = PlayerTwo.getPosition().height;
    float paddleTwoWidth = PlayerTwo.getPosition().width;

    float ball1VectorX = ball1.getVelocity().getX();
    float ball1VectorY = ball1.getVelocity().getY();

    float ball2VectorX = ball2.getVelocity().getX();
    float ball2VectorY = ball2.getVelocity().getY();

    float WINDOW_WIDTH = terrain.getDimX();
    float WINDOW_HEIGHT = terrain.getDimY();
    

    // collisions avec murs haut et bas
    if ((ball1Vertical <= 1.0) || (ball1Vertical >= WINDOW_HEIGHT - 1))
    {

        ball1.setVelocity(Vec2D(ball1VectorX, -ball1VectorY));
    }

    // collisions avec paddles
    if ((ball1Horizontal > paddleOneHorizontal) && (ball1Horizontal < (paddleOneHorizontal + paddleOneWidth)) 
    && (ball1Vertical > paddleOneVertical) && (ball1Vertical < (paddleOneVertical + paddleOneHeight)))
    {
        ball1.setVelocity(Vec2D(-ball1VectorX, ball1VectorY));
        // cout << "x = " << paddleOneHorizontal << " y = " << paddleOneVertical << " width = " << paddleOneWidth << " height = " << paddleOneHeight << endl;
    }

    if ((ball1Horizontal > (paddleTwoHorizontal-1)) && (ball1Horizontal < (paddleTwoHorizontal+paddleTwoWidth)) 
    && (ball1Vertical > paddleTwoVertical) && (ball1Vertical < (paddleTwoVertical + paddleTwoHeight)))
    {
        // cout << "x = " << paddleTwoHorizontal << " y = " << paddleTwoVertical << " width = " << paddleTwoWidth << " height = " << paddleTwoHeight << endl;
        ball1.setVelocity(Vec2D(-ball1VectorX, ball1VectorY));
    }

    /*COLLISIONS BALL2*/
    // collisions avec murs haut et bas
    if ((ball2Vertical <= 1.0) || (ball2Vertical >= WINDOW_HEIGHT - 1))
    {
        ball2.setVelocity(Vec2D(ball2VectorX, -ball2VectorY));
    }

    // collisions avec paddles
    if ((ball2Horizontal > paddleOneHorizontal) && (ball2Horizontal < (paddleOneHorizontal + paddleOneWidth)) 
    && (ball2Vertical > paddleOneVertical) && (ball2Vertical < (paddleOneVertical + paddleOneHeight)))
    {
        ball2.setVelocity(Vec2D(-ball2VectorX, ball2VectorY));
        // cout << "x = " << paddleOneHorizontal << " y = " << paddleOneVertical << " width = " << paddleOneWidth << " height = " << paddleOneHeight << endl;
    }

    if ((ball2Horizontal > (paddleTwoHorizontal-1)) && (ball2Horizontal < (paddleTwoHorizontal+paddleTwoWidth)) 
    && (ball2Vertical > paddleTwoVertical) && (ball2Vertical < (paddleTwoVertical + paddleTwoHeight)))
    {
        // cout << "x = " << paddleTwoHorizontal << " y = " << paddleTwoVertical << " width = " << paddleTwoWidth << " height = " << paddleTwoHeight << endl;
        ball2.setVelocity(Vec2D(-ball2VectorX, ball2VectorY));
    }
}

// fonction too long and repetitive. create function to handle both goal sides
void Jeu::perdu()
{
    int WINDOW_WIDTH = terrain.getDimX();
    int WINDOW_HEIGHT = terrain.getDimY();
    float ballPosition = ball1.getPosition().getX();
    float ballPosition2 = ball2.getPosition().getX();

    int FLOAT_MIN = -1;
    int FLOAT_MAX = 1;

    float randOne;
    float randTwo;

    /*BALL1*/
    // but à gauche
    if (ballPosition <= 1.0)
    {
        ball1.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)); // Devrait etre WINDOW_HEIGHT ET WIDTH COMME SDLJEU.CPP

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
            if (randOne < 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        ball1.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition >= WINDOW_WIDTH - 1)
    {
        ball1.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
            if (randOne > 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        ball1.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerOneScore.setScore();
    }

    /*BALL2*/
    // but à gauche
    if (ballPosition2 <= 1.0)
    {
        ball2.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)); // Devrait etre WINDOW_HEIGHT ET WIDTH COMME SDLJEU.CPP

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
            if (randOne < 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        ball2.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerTwoScore.setScore();
    }

    // collisions avec murs droite
    else if (ballPosition2 >= WINDOW_WIDTH - 1)
    {
        ball2.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

        do
        {
            randOne = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
            if (randOne > 0)
                randOne = -randOne;

        } while (randOne == 0);

        do
        {
            randTwo = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        } while (randTwo == 0);

        ball2.setVelocity(Vec2D(randOne, randTwo));
        // cout << "Ball vector set randomly at: Vec2D(" << randOne << "," << randTwo << ")" << endl;
        PlayerOneScore.setScore();
    }

}

// void Jeu::buts() {} // handle goals and reposition ball

void Jeu::actionsAutomatiques()
{
    ball1.bougeAuto();
    ball2.bougeAuto();
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
