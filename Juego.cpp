
#include <cstdlib>
#include <time.h>


#include "Juego.h"

/**
 * Representa al Juego.
 *
 * @author Ruben Salas
 * @since 27/03/19.
 * @version 1.0
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
}

FichaCreator* Juego::getCreator() {
    return creator;
}

void Juego::setCreator(FichaCreator* _creator) {
    creator = _creator;
}

Jugador* Juego::getJ1() {
    return j1;
}

void Juego::setJ1(Jugador* _j1) {
    j1 = _j1;
}

Jugador* Juego::getJ2() {
    return j2;
}

void Juego::setJ2(Jugador* _j2) {
    j2 = _j2;
}

Jugador* Juego::getJ3() {
    return j3;
}

void Juego::setJ3(Jugador* _j3) {
    j3 = _j3;
}

Jugador* Juego::getJ4() {
    return j4;
}

void Juego::setJ4(Jugador* _j4) {
    j4 = _j4;
}

int Juego::getCantJugadoresActuales() {
    return cantJugadoresActuales;
}

void Juego::setCantJugadoresActuales(int _cantJugadoresActuales) {
    cantJugadoresActuales = _cantJugadoresActuales;
}

int Juego::getCantJugadoresPermitidos() {
    return cantJugadoresPermitidos;
}

void Juego::setCantJugadoresPermitidos(int _cantJugadoresPermitidos) {
    cantJugadoresPermitidos = _cantJugadoresPermitidos;
}

List* Juego::getPoolFichas() {
    return poolFichas;
}

void Juego::setPoolFichas(List* _poolFichas) {
    poolFichas = _poolFichas;
}

int Juego::getCantFichas() {
    return cantFichas;
}

void Juego::setCantFichas(int _cantFichas) {
    cantFichas = _cantFichas;
}


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
    ///Random pick del pool 7 por jugador

    ///Genera un valor diferente cada vez que se llame a la funcion dependiendo de la hora y fecha.
    srand (time(NULL));
    ///Obtiene un int aleatorio
    int random0 = rand() % cantFichas + 1;

    if (j1 != nullptr) {

        cout << "\nJugador 1 listo para recibir fichas." << endl;
        cout << "Repartiendo fichas Jugador 1" << endl;

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
        lF1->printList();

    }
    if (j2 != nullptr) {
        cout << "\nJugador 2 listo para recibir fichas." << endl;
        cout << "Repartiendo fichas Jugador 2" << endl;

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
        lF2->printList();
    }
    if (j3 != nullptr) {
        cout << "\nJugador 3 listo para recibir fichas." << endl;
        cout << "Repartiendo fichas Jugador 3" << endl;

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
        lF3->printList();
    }
    if (j4 != nullptr) {
        cout << "\nJugador 4 listo para recibir fichas." << endl;
        cout << "Repartiendo fichas Jugador 4" << endl;

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
        lF4->printList();
    }

    if (cantJugadoresActuales == 0) {
        cout << "No hay jugadores disponibles para repartir fichas." << endl;
    }


}
