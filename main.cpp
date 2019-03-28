#include <iostream>

using namespace std;

#include "List.h"
#include "FichaCreator.h"
#include "Juego.h"

/**
 * Main del programa.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 * @version 1.2
 */
int main() {

    //Instancia de Juego
    Juego* juego = new Juego();

    //Instanciacion de 4 jugadores
    Jugador* jugador1 = new Jugador();
    Jugador* jugador2 = new Jugador();
    Jugador* jugador3 = new Jugador();
    Jugador* jugador4 = new Jugador();

    //Ingreso de los 4 jugadores a Juego
    juego->addJugador(jugador1);
    juego->addJugador(jugador2);
    juego->addJugador(jugador3);
    juego->addJugador(jugador4);

    //Cantidad de jugadores
    cout << "\nCantidad de Jugadores Actuales: " << juego->getCantJugadoresActuales() << "\n" << endl;

    //Creacion de las fichas
    juego->crearFichas();

    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();

    //Reparticion de las fichas a los jugadores
    juego->repartirFichas();

    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();


    return 0;
}