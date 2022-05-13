#include <iostream>
using namespace std;

// Dimensions SDL
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

// Dimensions objets
const int BALL_SIZE = 8;
const int PADDLE_WIDTH = 8;
const int PADDLE_HEIGHT = 81;
const int PADDLE_SPEED = 3;

void testRegression(Jeu &jeu)
{
    const Ball &BallOne = jeu.getConstBallOne();
    const Paddle &PaddleOne = jeu.getConstPaddleOne();
    const Score &ScoreOne = jeu.getConstPlayerOneScore();

    if (BALL_SIZE == BallOne.getRadius())
        cout << "Ball size ✅ " << endl;
    else
        cout << "Ball size ⛔" << endl;

    if (PaddleOne.getPosition().width == PADDLE_WIDTH && PaddleOne.getPosition().height == PADDLE_HEIGHT)
        cout << "Paddle dimensions ✅ " << endl;
    else
        cout << "Paddle dimensions ⛔" << endl;

    if (PaddleOne.getPosition().x == 10 && PaddleOne.getPosition().y == (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2))
        cout << "Paddle positions ✅" << endl;
    else
        cout << "Paddle positions ⛔" << endl;
}