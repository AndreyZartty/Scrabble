#include <iostream>

//#include "List.h"
//#include "FichaCreator.h"
#include "Juego.h"

#include <typeinfo>

using namespace std;

static Juego* juego;

/**
 *
 */
void inicio() {
    //Instancia el objeto Juego
    juego = new Juego("codigo", 4);

    //Creacion de las fichas
    //Asignacion de poolFichas y cantFichas
    juego->crearFichas();
}

/**
 *
 */
void comenzarJuego() {
    //Reparticion de las fichas a los jugadores
    juego->repartirFichas();
}

/**
 *
 */
void pasarTurno() {
    //Agrega +1 a los turnos del jugador
    juego->getEnTurno()->setTurnosPasados(juego->getEnTurno()->getTurnosPasados() + 1);
    //Verifica los turnos seguidos de todos los jugadores
    juego->checkTurnosPasados();
    //Verifica que el juego no haya terminado
    juego->checkTerminado();
    //Pasa al siguiente turno con un nuevo jugador
    juego->siguienteTurno();
}

void scrabble(){
    //VERIFICAR PALABRA

}


/**
 * Main del programa.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 */
int main(int argc, char **argv) {

    //Inicio de la ventana del Juego
    inicio();



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

    //Cantidad inicial de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();



    //Comienzo del juego
    comenzarJuego();

    //Cantidad final de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juego->getPoolFichas()->printList();


    //Simula al jugador1 como si estuviese en turno
    juego->setEnTurno(jugador1);
    cout<<"\n\nEn turno: " << juego->getEnTurno()->getNombre() << endl;



    cout << "\nLista " << juego->getEnTurno()->getNombre() << endl;

    //Imprime la cantidad de fichas del Jugador1
    juego->getJ1()->getListaFichas()->printList();

    //Simulacion de haber escogido una ficha en la lista del jugador
    Ficha* fichaPreescogida = juego->getJ1()->getListaFichas()->getHead()->getFicha();
    cout << "\nFicha por mover: " << fichaPreescogida->getLetra() << endl;


    cout << "\n\nLista Cuadricula" << endl;

    //Imprime la lista de fichas que tendria la cuadricula
    juego->getCuadricula()->getListaCuadricula()->printList();


    ///Ficha que se movera a la cuadricula, proveniente del jugador
    Ficha* fichaEnMovimiento = juego->getJ1()->colocarFicha(fichaPreescogida);

    ///Agregar la ficha del jugador a la cuadricula
    juego->getCuadricula()->getListaCuadricula()->newNode(fichaEnMovimiento);
    cout << "\nSe ha agregado la ficha: " << fichaEnMovimiento->getLetra() << endl;

    cout << "\n\nLista Cuadricula" << endl;
    //Imprime la lista de fichas que estaran en la cuadricula
    juego->getCuadricula()->getListaCuadricula()->printList();

    cout << "\n\nLista " << juego->getEnTurno()->getNombre() << endl;
    //Imprime la lista de fichas del jugador1
    juego->getJ1()->getListaFichas()->printList();


    return 0;

}
