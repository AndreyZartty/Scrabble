
#ifndef FICHAS_JUEGO_H
#define FICHAS_JUEGO_H


#include "Jugador.h"
#include "FichaCreator.h"


/**
 * Header de Juego.
 *
 * @author Ruben Salas
 * @since 27/03/19.
 * @version 1.0
 */
class Juego {

private:
    FichaCreator* creator;
    Jugador* j1;
    Jugador* j2;
    Jugador* j3;
    Jugador* j4;
    int cantJugadoresActuales;
    int cantJugadoresPermitidos;
    //Tablero;
    List* poolFichas;
    int cantFichas;
    //Terminado;
    //Codigo;
    //Turno;

public:
    Juego();

    FichaCreator* getCreator();
    void setCreator(FichaCreator* _creator);
    Jugador* getJ1();
    void setJ1(Jugador* _j1);
    Jugador* getJ2();
    void setJ2(Jugador* _j2);
    Jugador* getJ3();
    void setJ3(Jugador* _j3);
    Jugador* getJ4();
    void setJ4(Jugador* _j4);
    int getCantJugadoresActuales();
    void setCantJugadoresActuales(int _cantJugadoresActuales);
    int getCantJugadoresPermitidos();
    void setCantJugadoresPermitidos(int _cantJugadoresPermitidos);
    List* getPoolFichas();
    void setPoolFichas(List* _poolFichas);
    int getCantFichas();
    void setCantFichas(int _cantFichas);

    void addJugador(Jugador* nJugador);
    void crearFichas();
    void repartirFichas();

};


#endif //FICHAS_JUEGO_H
