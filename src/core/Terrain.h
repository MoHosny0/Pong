#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain {


private : 
    int dimx;
    int dimy;
    char ter [100][30];

public : 

    /**
    @brief <B>Construit</B> un objet Terrain.
    Le constructeur remplit dimx et dimy
    */
    Terrain();
    /**
    @brief Renvoie la largeur du terrain
    */
    int getDimX() const;

    /**
    @brief Renvoie la hauteur du terrain
    */
    int getDimY() const;

    char getXY(const int x, const int y) const;

};



#endif