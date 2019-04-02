
#ifndef SCRABBLE_CUADRICULA_H
#define SCRABBLE_CUADRICULA_H

#include "Node.h"
#include "List.h"

class Cuadricula {

private:
    List* listaCuadricula;

    //int tamano;
    //Node casillasOcu[0];
    //Node casillasEsp[0];
    //Node matriz[0][0];
    //int cOcupadas=0;
    //int cEspeciales=0;


public:
    Cuadricula();
    List* getListaCuadricula();
    void setListaCuadricula(List* _listaCuadricula);

};


#endif //SCRABBLE_CUADRICULA_H
