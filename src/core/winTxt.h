#include "Jeu.h"

#ifndef WINTXT_H
#define WINTXT_H

//! \brief une fen�tre texte est un tableau 2D de caract�res
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D
    Jeu jeu;

public:

    WinTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void printPaddle (int x1, int x2, int y1, int y2, char c);
    //void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif