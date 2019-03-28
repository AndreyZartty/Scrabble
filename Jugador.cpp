
#include "Jugador.h"

/**
 * Representa a un Jugador.
 *
 * @author Ruben Salas
 * @since 27/03/19.
 * @version 1.0
 */


/**
 * Constructor de Jugador.
 */
Jugador::Jugador(){

}

List* Jugador::getListaFichas() {
    return listaFichas;
}

void Jugador::setListaFichas(List* _listaFichas) {
    listaFichas = _listaFichas;
}

string Jugador::getNombre() {
    return nombre;
}

void Jugador::setNombre(string _nombre) {
    nombre = _nombre;
}

int Jugador::getPuntaje() {
    return puntaje;
}

void Jugador::setPuntaje(int _puntaje) {
    puntaje = _puntaje;
}

int Jugador::getTurnosPasados() {
    return turnosPasados;
}

void Jugador::setTurnosPasados(int _turnosPasados) {
    turnosPasados = _turnosPasados;
}

void Jugador::reponerFichas(){

}

void Jugador::colocarFicha(){

}
