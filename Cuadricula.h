//
// Created by cucho16 on 26/03/19.
//

#ifndef SCRABBLE_CUADRICULA_H
#define SCRABBLE_CUADRICULA_H

#include "Node.h"

class Cuadricula {

private:
    int tamano;
    Node casillasOcu[0];
    Node casillasEsp[0];
    Node matriz[0][0];
    int cOcupadas=0;
    int cEspeciales=0;
public:
    int gettamano();
    Node getCasillaOcu(int casilla);
    Node getCasillaEsp(int casilla);
    void setMatriz(int tam);
    void settamano(int tam);
    void setCasillaEsp(Node especial);
    void addCasillaOcu(Node ocupada);
};


#endif //SCRABBLE_CUADRICULA_H
