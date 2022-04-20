#ifndef SDLJEU_H
#define SDLJEU_H
#include "../core/Jeu.h"
#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>

class sdlJeu
{
private:
    Jeu jeu;
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDL_Color font_color;

public:
    sdlJeu();
    ~sdlJeu();
    void sdlBoucle(Jeu &jeu);
    void sdlAff(Jeu &jeu);
    SDL_Rect Balle;
    SDL_Rect PlayerOne, PlayerTwo;
};

#endif