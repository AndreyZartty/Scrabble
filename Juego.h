
#ifndef FICHAS_JUEGO_H
#define FICHAS_JUEGO_H


#include "Jugador.h"
#include "FichaCreator.h"
#include "Cuadricula.h"


/**
 * Header de Juego.
 *
 * @author Ruben Salas
 * @since 27/03/19
 * @version 1.1
 */
class Juego {

private:
    FichaCreator* creator;
    Jugador* j1;
    Jugador* j2;
    Jugador* j3;
    Jugador* j4;
    Jugador* enTurno;
    int cantJugadoresActuales;
    int cantJugadoresPermitidos;
    Cuadricula* cuadricula;
    List* poolFichas;
    int cantFichas;
    bool terminado;
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
    Jugador* getEnTurno();
    void setEnTurno();
    int getCantJugadoresActuales();
    void setCantJugadoresActuales(int _cantJugadoresActuales);
    int getCantJugadoresPermitidos();
    void setCantJugadoresPermitidos(int _cantJugadoresPermitidos);
    Cuadricula* getCuadricula();
    void setCuadricula(Cuadricula* _cuadricula);
    List* getPoolFichas();
    void setPoolFichas(List* _poolFichas);
    int getCantFichas();
    void setCantFichas(int _cantFichas);

    bool isTerminado();

    void setTerminado(bool _terminado);

    void addJugador(Jugador* nJugador);
    void crearFichas();
    void repartirFichas();
    void reestablecerFichas();

};


#endif //FICHAS_JUEGO_H
