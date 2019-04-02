#include <iostream>

#include "List.h"
#include "FichaCreator.h"
#include "Juego.h"

using namespace std;

/**
 * Main del programa.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 * @version 1.3
 */
int main() {

    //Instancia de Juego
    Juego* juego = new Juego();



    //Instanciacion de 4 jugadores
    Jugador* jugador1 = new Jugador("Jugador #1");
    Jugador* jugador2 = new Jugador("Jugador #2");
    Jugador* jugador3 = new Jugador("Jugador #3");
    Jugador* jugador4 = new Jugador("Jugador #4");

    //Ingreso de los 4 jugadores a Juego
    juego->addJugador(jugador1);
    juego->addJugador(jugador2);
    juego->addJugador(jugador3);
    juego->addJugador(jugador4);

    //Cantidad de jugadores
    cout << "\nCantidad de Jugadores Actuales: " << juego->getCantJugadoresActuales() << "\n" << endl;

    //Creacion de las fichas
    juego->crearFichas();

    //Cantidad inicial de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();

    //Reparticion de las fichas a los jugadores
    juego->repartirFichas();

    //Cantidad final de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();



    cout << "\n\nTest Lista J1" << endl;

    //Imprime la cantidad de fichas del Jugador1
    juego->getJ1()->getListaFichas()->printList();

    //Simulacion de haber escogido una ficha en la lista del jugador
    Ficha* fichaPreescogida = juego->getJ1()->getListaFichas()->getHead()->getFicha();
    cout << "Ficha por mover: " << fichaPreescogida->getLetra() << endl;


    cout << "\n\nTest Lista Cuadricula" << endl;

    //Imprime la lista de fichas que tendria la cuadricula
    juego->getCuadricula()->getListaCuadricula()->printList();


    ///Ficha que se movera a la cuadricula, proveniente del jugador
    Ficha* fichaEnMovimiento = juego->getJ1()->colocarFicha(fichaPreescogida);

    ///Agregar la ficha del jugador a la cuadricula
    juego->getCuadricula()->getListaCuadricula()->newNode(fichaEnMovimiento);
    cout << "\nSe ha agregado la ficha: " << fichaEnMovimiento->getLetra() << endl;

    cout << "\n\nTest Lista Cuadricula" << endl;
    //Imprime la lista de fichas que estaran en la cuadricula
    juego->getCuadricula()->getListaCuadricula()->printList();

    cout << "\n\nTest Lista J1" << endl;
    //Imprime la lista de fichas del jugador1
    juego->getJ1()->getListaFichas()->printList();


    return 0;

}
