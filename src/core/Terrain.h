#ifndef TERRAIN_H
#define TERRAIN_H

/**
@brief La classe Terrain contient ses dimensions et un tab 2D de cases (une case=1 char)
*/
class Terrain
{

private:
    int dimx;
    int dimy;
    char ter[80][30];

public:
    /**
    @brief <B>Construit</B> un objet Terrain.
    Le constructeur remplit dimx et dimy
    */
    Terrain();

    /**
       @brief Renvoie vrai si on peut positionnner un objet aux coordonnées (x,y), faux sinon
       @param x : abs de la case à tester
       @param y : ordonnée de la case à tester
       */
    bool posEstValide(const int x, const int y) const;

    /**
    @brief Renvoie la largeur du terrain
    */
    int getDimX() const;

    /**
    @brief Renvoie la hauteur du terrain
    */
    int getDimY() const;

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    char getXY(const int x, const int y) const;

    void setDim(const int x, const int y);
};

#endif