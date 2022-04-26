#ifndef TXT_H
#define TXT_H
#include "../core/Terrain.h"
#include "winTxt.h"

/**
@brief: Efface le contenu du terminal.
*/
void txtClear();

/**
@brief: Affiche le terrain sur le terminal.
@param: le terrain a afficher. 
*/
void affiche(Terrain terrain);

/**
@brief: Boucle du jeu en mode terminal.
@param: jeu à boucler.
*/
void boucle(Jeu &jeu);

#endif