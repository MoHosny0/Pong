#ifndef SDLJEU_H
#define SDLJEU_H
#include "../core/Jeu.h"
#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>

// //! @brief Pour gerer une image avec SDL2
// class Image
// {

// private:
//     SDL_Surface *m_surface;
//     SDL_Texture *m_texture;
//     bool m_hasChanged;

// public:
//     Image();
//     ~Image();
//     void loadFromFile(const char *filename, SDL_Renderer *renderer);
//     void loadFromCurrentSurface(SDL_Renderer *renderer);
//     void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);
//     SDL_Texture *getTexture() const;
//     void setSurface(SDL_Surface *surf);
// };

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
    // SDL_Rect Balle;
    // SDL_Rect PlayerOne, PlayerTwo;
};

#endif