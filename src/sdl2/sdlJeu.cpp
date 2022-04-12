#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "sdlJeu.h"
using namespace std;

// Dimensions SDL
const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 800;

const int BALL_SIZE = 8;

const int PADDLE_HEIGHT = 40;
const int PADDLE_WIDTH = 8;

float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC; // conversion des ms en secondes en divisant par 1000
}

sdlJeu::init()
{
    const Terrain &terrain = jeu.getTerrain();
    const Ball &ball = jeu.getBall();
    const Paddle &paddle1 = jeu.getPaddle1();
    const Paddle &paddle2 = jeu.getPaddle2();

    terrain.setPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
    ball.setPosition(Vec2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    paddle1.setPosition(Vec2D(10, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2)));
    paddle2.setPosition(Vec2D(WINDOW_WIDTH - 10 - 1, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2)))
}

sdlJeu::sdlJeu() : jeu()
{

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
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

void sdlJeu::sdlAff()
{
    // Remplir l'ecran de blanc
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    int x, y;

    // Draw the net
    for (int y = 0; y < WINDOW_HEIGHT; ++y)
    {
        if (y % 15)
        {
            SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

    // Draw the Ball
    balle.x = ball.getPosition().getX();
    balle.y = ball.getPosition().getY();
    balle.w = BALL_SIZE;
    balle.h = BALL_SIZE;
    SDL_RenderFillRect(renderer, &balle);
    cout << "Drawing ball at coordinates [" << balle.x << "," << balle.y << "]" << endl;

    // Draw the Paddles

    player1.w = PADDLE_WIDTH;
    player1.h = PADDLE_HEIGHT;
    player1.x = paddle1.getPosition().x;
    player1.y = paddle1.getPosition().y;

    player2.w = PADDLE_WIDTH;
    player2.h = PADDLE_HEIGHT;
    player2.x = paddle2.getPosition().x;
    player2.y = paddle2.getPosition().y;

    SDL_RenderFillRect(renderer, &player1);
    SDL_RenderFillRect(renderer, &player2);
    cout << "Drawing Paddle 1 at coordinates [" << player1.x << "," << player1.y << "]" << endl;
    cout << "Drawing Paddle 2 at coordinates [" << player2.x << "," << player2.y << "]" << endl;
}

void sdlJeu::sdlBoucle()
{
    SDL_Event events;
    bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;

    // tant que ce n'est pas la fin ...
    while (!quit)
    {

        nt = SDL_GetTicks();
        if (nt - t > 80)
        {
            jeu.actionsAutomatiques();
            t = nt;
        }

        // tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                quit = true; // Si l'utilisateur a clique sur la croix de fermeture
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
        // on affiche le jeu sur le buffer cach�
        sdlAff();
        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
    }
}