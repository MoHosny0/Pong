#ifndef SDLJEU_H
#define SDLJEU_H

#include "Jeu.h"
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
    void sdlBoucle();
    void sdlAff();
};

#endif