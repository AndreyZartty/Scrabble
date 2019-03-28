
#include <iostream>
#include <stdlib.h>

#include "Ficha.h"

using namespace std;

/**
 * Representa a una Ficha.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 * @version 1.1
 */


/**
 * Constructor de Ficha.
 */
Ficha::Ficha(string _letra, int _puntaje){
    letra = _letra;
    puntaje = _puntaje;
    puedeMoverse = true;
    posicion = 0;
}

/**
 * Getter de la letra de Ficha.
 * @returns letra - letra guardada en ficha
 */
string Ficha::getLetra(){
    return letra;
}

/**
 * Setter de data de Ficha.
 * @param _data - numero
 */
void Ficha::setLetra(string _letra){
    letra = _letra;
}

bool Ficha::getPuedeMoverse(){
    return puedeMoverse;
}

void Ficha::setPuedeMoverse(bool _puedeMoverse) {
    puedeMoverse = _puedeMoverse;
}

int Ficha::getPosicion(){
    return posicion;
}

void Ficha::setPosicion(int _posicion) {
    posicion = _posicion;
}
