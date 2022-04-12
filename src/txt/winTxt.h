#include "../core/Jeu.h"

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

    /**
    @brief Création d'une fenêtre. 
    */
    WinTXT (int dx, int dy);
    
    /**
    @brief Efface le contenu de la fenêtre. 
    */
    void clear (char c=' ');

    /**
    @brief Met le char au coordonées données dans le tableau de charactère. 
    */
    void print (int x, int y, char c);
    
    /**
    @brief Met le char du paddle au coordonées données dans le tableau de charactère. 
    */
    void printPaddle (int x1, int y1, int width, int height, char c);
    

    /**
     * @brief Affiche la fenêtre. 
     */
    void draw (int x=0, int y=0);

    /**
     * @brief Met en pause le système.
     * 
     */
    void pause();

    /**
     * @brief Récupère le char entré dans le terminal.
     * 
     * @return char 
     */
    char getCh();

};

void termClear ();

#endif
