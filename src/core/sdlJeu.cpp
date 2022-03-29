#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC; // conversion des ms en secondes en divisant par 1000
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

    WINDOW_WIDTH = jeu.getConstTerrain().getDimX();
    WINDOW_HEIGHT = jeu.getConstTerrain().getDimY();
    WINDOW_WIDTH *= TAILLE_SPRITE;
    WINDOW_HEIGHT *= TAILLE_SPRITE;

    cout << "Window is created with dimensions " << WINDOW_WIDTH << " and " << WINDOW_HEIGHT << endl;

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
    const Terrain &terrain = jeu.getConstTerrain();
    const Ball &ball = jeu.getConstBall();
    const Paddle &paddle1 = jeu.getConstPaddle1();
    const Paddle &paddle2 = jeu.getConstPaddle2();

    // Draw the net
    for (int y = 0; y < WINDOW_HEIGHT; ++y)
    {
        if (y % 20)
        {
            SDL_RenderDrawPoint(renderer, WINDOW_WIDTH, y);
        }
    }
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
            }
        }
        // on affiche le jeu sur le buffer cach�
        sdlAff();
        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
    }
}
