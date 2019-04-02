
#include <cstdlib>
#include <time.h>

#include "Juego.h"

/**
 * Representa al Juego.
 *
 * @author Ruben Salas
 * @since 27/03/19.
 * @version 1.2
 */


/**
 * Constructor de Juego.
 */
Juego::Juego(){
    creator = new FichaCreator();
    poolFichas = nullptr;
    cantFichas = 0;
    cantJugadoresActuales = 0;
    cantJugadoresPermitidos = 0;
    j1 = nullptr;
    j2 = nullptr;
    j3 = nullptr;
    j4 = nullptr;
    cuadricula = new Cuadricula();
    terminado = false;
}

/**
 * Getter del creador de fichas.
 * @return creator
 */
FichaCreator* Juego::getCreator() {
    return creator;
}

/**
 * Setter del creador de fichas
 * @param _creator
 */
void Juego::setCreator(FichaCreator* _creator) {
    creator = _creator;
}

/**
 * Getter del Jugador #1
 * @return j1
 */
Jugador* Juego::getJ1() {
    return j1;
}

/**
 * Setter del Jugador #1
 * @param _j1
 */
void Juego::setJ1(Jugador* _j1) {
    j1 = _j1;
}

/**
 * Setter del Jugador #2
 * @return j2
 */
Jugador* Juego::getJ2() {
    return j2;
}

/**
 *
 * @param _j2
 */
void Juego::setJ2(Jugador* _j2) {
    j2 = _j2;
}

/**
 *
 * @return
 */
Jugador* Juego::getJ3() {
    return j3;
}

/**
 *
 * @param _j3
 */
void Juego::setJ3(Jugador* _j3) {
    j3 = _j3;
}

/**
 *
 * @return
 */
Jugador* Juego::getJ4() {
    return j4;
}

/**
 *
 * @param _j4
 */
void Juego::setJ4(Jugador* _j4) {
    j4 = _j4;
}

/**
 *
 * @return
 */
int Juego::getCantJugadoresActuales() {
    return cantJugadoresActuales;
}

/**
 *
 * @param _cantJugadoresActuales
 */
void Juego::setCantJugadoresActuales(int _cantJugadoresActuales) {
    cantJugadoresActuales = _cantJugadoresActuales;
}

/**
 *
 * @return
 */
int Juego::getCantJugadoresPermitidos() {
    return cantJugadoresPermitidos;
}

/**
 *
 * @param _cantJugadoresPermitidos
 */
void Juego::setCantJugadoresPermitidos(int _cantJugadoresPermitidos) {
    cantJugadoresPermitidos = _cantJugadoresPermitidos;
}

/**
 *
 * @return
 */
Cuadricula* Juego::getCuadricula() {
    return cuadricula;
}

/**
 *
 * @param _cuadricula
 */
void Juego::setCuadricula(Cuadricula* _cuadricula) {
    cuadricula = _cuadricula;
}

/**
 *
 * @return
 */
List* Juego::getPoolFichas() {
    return poolFichas;
}

/**
 *
 * @param _poolFichas
 */
void Juego::setPoolFichas(List* _poolFichas) {
    poolFichas = _poolFichas;
}

/**
 *
 * @return
 */
int Juego::getCantFichas() {
    return cantFichas;
}

/**
 *
 * @param _cantFichas
 */
void Juego::setCantFichas(int _cantFichas) {
    cantFichas = _cantFichas;
}

/**
 *
 * @return
 */
bool Juego::isTerminado() {
    return terminado;
}

/**
 *
 * @param _terminado
 */
void Juego::setTerminado(bool _terminado) {
    terminado = _terminado;
}

/**
 * Añade un jugador y verifica si hay campo en el juego.
 * @param nJugador
 */
void Juego::addJugador(Jugador* nJugador) {
    if (j4 == nullptr) {
        if (j3 == nullptr) {
            if (j2 == nullptr) {
                if (j1 == nullptr) {
                    j1 = nJugador;
                } else {
                    j2 = nJugador;
                }
            } else {
                j3 = nJugador;
            }
        } else {
            j4 = nJugador;
        }
        cantJugadoresActuales++;

    } else {
        cout << "Todos los espacios disponibles estan ocupados." << endl;
    }
}


/**
 * Crea las fichas por medio del FichaCreator. Asigna el pool de fichas como atributo.
 */
void Juego::crearFichas(){
    ///FichaCreator crea todas las fichas y las ingresa al pool guardado en esa clase.
    creator->initialCreate();
    ///El pool de las fichas es pasado al atributo pool del juego para que sea accesado ahi.
    setPoolFichas(creator->getPool());
    ///Agrega el valor de la cantidad de fichas que hayan en el pool
    setCantFichas(poolFichas->getLen());
}

/**
 * Reparte las fichas entre los Jugadores existentes dando 7 a cada uno.
 */
void Juego::repartirFichas(){
    ///Genera un valor diferente cada vez que se llame a la funcion dependiendo de la hora y fecha.
    srand (time(NULL));
    ///Obtiene un int aleatorio
    int random0 = rand() % cantFichas + 1;

    if (j1 != nullptr) {
        cout << "\nRepartiendo fichas Jugador 1" << endl;

        ///Lista del jugador 1
        List* lF1 = new List();
        ///Contador jugador 1
        int i1 = 7;
        while (i1 > 0) {
            ///Obtiene un int aleatorio
            int random1 = rand() % cantFichas + 1;
            ///Obtiene la ficha del pool
            Ficha* randomFicha1 = poolFichas->getNode(random1)->getFicha();
            ///Elimina la ficha del pool
            poolFichas->deleteNode(randomFicha1);
            ///Actualiza la cantidad de Fichas en el pool
            setCantFichas(poolFichas->getLen());
            ///Agrega la ficha a la lista del jugador1
            lF1->newNode(randomFicha1);
            ///Disminuye el contador del jugador 1
            i1--;
        }
        j1->setListaFichas(lF1);
        j1->getListaFichas()->printList();

    }
    if (j2 != nullptr) {
        cout << "\nRepartiendo fichas Jugador 2" << endl;

        ///Lista del jugador 2
        List* lF2 = new List();
        ///Contador jugador 2
        int i2 = 7;
        while (i2 > 0) {
            ///Obtiene un int aleatorio
            int random2 = rand() % cantFichas + 1;
            ///Obtiene la ficha del pool
            Ficha* randomFicha2 = poolFichas->getNode(random2)->getFicha();
            ///Elimina la ficha del pool
            poolFichas->deleteNode(randomFicha2);
            ///Actualiza la cantidad de Fichas en el pool
            setCantFichas(poolFichas->getLen());
            ///Agrega la ficha a la lista del jugador1
            lF2->newNode(randomFicha2);
            ///Disminuye el contador del jugador 1
            i2--;
        }
        j2->setListaFichas(lF2);
        j2->getListaFichas()->printList();
    }
    if (j3 != nullptr) {
        cout << "\nRepartiendo fichas Jugador 3" << endl;

        ///Lista del jugador 3
        List* lF3 = new List();
        ///Contador jugador 3
        int i3 = 7;
        while (i3 > 0) {
            ///Obtiene un int aleatorio
            int random3 = rand() % cantFichas + 1;
            ///Obtiene la ficha del pool
            Ficha* randomFicha3 = poolFichas->getNode(random3)->getFicha();
            ///Elimina la ficha del pool
            poolFichas->deleteNode(randomFicha3);
            ///Actualiza la cantidad de Fichas en el pool
            setCantFichas(poolFichas->getLen());
            ///Agrega la ficha a la lista del jugador1
            lF3->newNode(randomFicha3);
            ///Disminuye el contador del jugador 1
            i3--;
        }
        j3->setListaFichas(lF3);
        j3->getListaFichas()->printList();
    }
    if (j4 != nullptr) {
        cout << "\nRepartiendo fichas Jugador 4" << endl;

        ///Lista del jugador 4
        List* lF4 = new List();
        ///Contador jugador 4
        int i4 = 7;
        while (i4 > 0) {
            ///Obtiene un int aleatorio
            int random4 = rand() % cantFichas + 1;
            ///Obtiene la ficha del pool
            Ficha* randomFicha4 = poolFichas->getNode(random4)->getFicha();
            ///Elimina la ficha del pool
            poolFichas->deleteNode(randomFicha4);
            ///Actualiza la cantidad de Fichas en el pool
            setCantFichas(poolFichas->getLen());
            ///Agrega la ficha a la lista del jugador1
            lF4->newNode(randomFicha4);
            ///Disminuye el contador del jugador 1
            i4--;
        }
        j4->setListaFichas(lF4);
        j4->getListaFichas()->printList();
    }

    if (cantJugadoresActuales == 0) {
        cout << "No hay jugadores disponibles para repartir fichas." << endl;
    }

}

/**
 * Reestablece la cantidad de fichas de cada jugador luego de su turno.
 */
void Juego::reestablecerFichas(){

}



