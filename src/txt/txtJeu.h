#ifndef TXT_H
#define TXT_H
#include "../core/Terrain.h"
#include "winTxt.h"


    /**
    @brief Efface le contenu du terminal. 
    */
    void txtClear();

    /**
    @brief Affiche le terrain sur le terminal. 
    */
    void affiche(Terrain terrain);

    /**
    @brief Boucle du jeu en mode terminal. 
    */
    void boucle(Jeu & jeu);


#endif