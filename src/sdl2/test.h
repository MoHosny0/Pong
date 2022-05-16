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
    const Ball &BallTwo = jeu.getConstBallTwo();
    const Paddle &PaddleTwo = jeu.getConstPaddleTwo();
    const Score &ScoreTwo = jeu.getConstPlayerTwoScore();
    const Terrain &Terrain = jeu.getTerrain();

    if (BALL_SIZE == BallOne.getRadius())
        cout << "Ball 1 size ✅ " << endl;
    else
        cout << "Ball 1 size ⛔" << endl;

    if (BALL_SIZE == BallTwo.getRadius())
        cout << "Ball 2 size ✅ " << endl;
    else
        cout << "Ball 2 size ⛔" << endl;

    if (PaddleOne.getPosition().width == PADDLE_WIDTH && PaddleOne.getPosition().height == PADDLE_HEIGHT)
        cout << "Paddle 1 dimensions ✅ " << endl;
    else
        cout << "Paddle 1 dimensions ⛔" << endl;

    if (PaddleTwo.getPosition().width == PADDLE_WIDTH && PaddleTwo.getPosition().height == PADDLE_HEIGHT)
        cout << "Paddle 2 dimensions ✅ " << endl;
    else
        cout << "Paddle 2 dimensions ⛔" << endl;

    if (PaddleOne.getPosition().x == 10 && PaddleOne.getPosition().y == (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2))
        cout << "Paddle 1 positions ✅" << endl;
    else
        cout << "Paddle 1 positions ⛔" << endl;

    if (PaddleTwo.getPosition().x == (WINDOW_WIDTH - 10 - 7) && PaddleTwo.getPosition().y == (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2))
        cout << "Paddle 2 positions ✅" << endl;
    else
        cout << "Paddle 2 positions ⛔" << endl;

    if (Terrain.getDimX() == WINDOW_WIDTH)
        cout << "Terrain Width ✅ " << endl;
    else
        cout << "Terrain Width ⛔" << endl;

    if (Terrain.getDimY() == WINDOW_HEIGHT)
        cout << "Terrain Height ✅ " << endl;
    else
        cout << "Terrain Height ⛔" << endl;
}