#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "sdlJeu.h"
#include "test.h"
using namespace std;

/**
 * @brief Calcule le nombre de secondes depuis le début du programme.
 * @return le temps en secondes
 *
 */
float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC * 1000; // conversion des ms en secondes en divisant par 1000
}

void init(Jeu &jeu)
{

    cout << temps() << endl;
    Terrain &Terrain = jeu.getTerrain();

    Ball &BallOne = jeu.getBallOne();
    Ball &BallTwo = jeu.getBallTwo();

    Paddle &PaddleOne = jeu.getPaddleOne();
    Paddle &PaddleTwo = jeu.getPaddleTwo();

    const Score &ScoreOne = jeu.getConstPlayerOneScore(); // besoin ici?
    const Score &ScoreTwo = jeu.getConstPlayerTwoScore(); // besoin ici?

    Terrain.setDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);

    BallOne.setRadius(BALL_SIZE);
    BallOne.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

    BallTwo.setRadius(BALL_SIZE);
    BallTwo.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));

    PaddleOne.setPosition(Vec2D(10, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2)));
    PaddleOne.setDimension(PADDLE_WIDTH, PADDLE_HEIGHT);
    PaddleOne.setSpeed(PADDLE_SPEED);

    PaddleTwo.setPosition(Vec2D(WINDOW_WIDTH - 10 - 7, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2)));
    PaddleTwo.setDimension(PADDLE_WIDTH, PADDLE_HEIGHT);
    PaddleTwo.setSpeed(PADDLE_SPEED);
}

sdlJeu::sdlJeu()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    cout << "Window is created with dimensions " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << endl;

    // Creation de la fenetre
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

sdlJeu::~sdlJeu()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff(Jeu &jeu)
{
    // Remplir l'écran en blanc
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    // Draw the net
    for (int y = 0; y <= WINDOW_HEIGHT; ++y)
    {
        if (y % 21)
        {
            SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
            SDL_RenderDrawPoint(renderer, (WINDOW_WIDTH / 2) - 1, y);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    const Ball &BallOne = jeu.getConstBallOne();
    const Ball &BallTwo = jeu.getConstBallTwo();

    const Paddle &PaddleOne = jeu.getConstPaddleOne();
    const Paddle &PaddleTwo = jeu.getConstPaddleTwo();

    const Score &ScoreOne = jeu.getConstPlayerOneScore();
    const Score &ScoreTwo = jeu.getConstPlayerTwoScore();

    SDL_Rect Balle1, Balle2, PlayerOne, PlayerTwo;

    // Draw Ball 1
    Balle1.x = BallOne.getPosition().getX();
    Balle1.y = BallOne.getPosition().getY();
    Balle1.w = BallOne.getRadius();
    Balle1.h = BallOne.getRadius();
    SDL_RenderFillRect(renderer, &Balle1);

    // Draw Ball 2
    Balle2.x = BallTwo.getPosition().getX();
    Balle2.y = BallTwo.getPosition().getY();
    Balle2.w = BallTwo.getRadius();
    Balle2.h = BallTwo.getRadius();
    SDL_RenderFillRect(renderer, &Balle2);

    // Draw the Paddles
    PlayerOne.w = PaddleOne.getPosition().width;
    PlayerOne.h = PaddleOne.getPosition().height;
    PlayerOne.x = PaddleOne.getPosition().x;
    PlayerOne.y = PaddleOne.getPosition().y;

    PlayerTwo.w = PaddleTwo.getPosition().width;
    PlayerTwo.h = PaddleTwo.getPosition().height;
    PlayerTwo.x = PaddleTwo.getPosition().x;
    PlayerTwo.y = PaddleTwo.getPosition().y;

    SDL_RenderFillRect(renderer, &PlayerOne);
    SDL_RenderFillRect(renderer, &PlayerTwo);
}

void sdlJeu::sdlBoucle(Jeu &jeu)
{
    init(jeu);
    testRegression(jeu);

    SDL_Event events;
    bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;

    while (!quit)
    {
        nt = SDL_GetTicks();
        if (nt - t > 1)
        {
            jeu.actionsAutomatiques();
            t = nt;
        }

        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                quit = true;
            else if (events.type == SDL_KEYDOWN)
            {
                if (events.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_Q:
                    jeu.actionClavier('q');
                    break;
                case SDL_SCANCODE_A:
                    jeu.actionClavier('a');
                    break;
                case SDL_SCANCODE_P:
                    jeu.actionClavier('p');
                    break;
                case SDL_SCANCODE_L:
                    jeu.actionClavier('l');
                    break;
                default:
                    break;
                }
            }
        }
        sdlAff(jeu);
        SDL_RenderPresent(renderer);
    }
}
