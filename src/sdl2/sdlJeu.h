#ifndef SDLJEU_H
#define SDLJEU_H
#include "../core/Jeu.h"
#include <SDL2/SDL.h>

class sdlJeu
{
private:
    Jeu jeu;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color font_color;

public:
    sdlJeu();
    ~sdlJeu();
    void sdlBoucle(Jeu &jeu);
    void sdlAff(Jeu &jeu);
    SDL_Rect balle;
    SDL_Rect player1, player2;
};

#endif