#include <iostream>
#include <typeinfo>
#include "Juego.h"



//*********************************

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <json-c/json.h>
#include <string>
#include <iostream>

#define PORT 3550
#define BACKLOG 4
#define MAXDATASIZE 1000

//*********************************



using namespace std;

static Juego* juegoTest;

static int cantJuegosActuales = 0;
static Juego* juegosActuales[10];





void juegoNuevo(string codigo, int cantJugadores) {
    if (cantJuegosActuales < 10 ) {
        ///Instancia el objeto Juego
        Juego* nJuego = new Juego(codigo, cantJugadores);
        ///Lo agrega en la siguiente posicion sin juego guardado
        juegosActuales[cantJuegosActuales] = nJuego;
        ///Actualiza la cantidad de juegos actuales
        cantJuegosActuales++;

        cout << "\nJuego nuevo creado!" << endl;
        cout << "Juegos activos: " << cantJuegosActuales << endl;

    } else {
        cout << "\nLimite de juegos activos alcanzado." << endl;
    }
}

void printJuegosActivos() {
    int i = 0;
    while (i < cantJuegosActuales) {
        cout << juegosActuales[i]->getCodigo() << endl;
        i++;
    }
}



/**
 *
 */
void inicio() {
    //Crea un nuevo juego
    juegoNuevo("0001",4);

    //Instancia del juego1
    juegoTest = juegosActuales[0];

    //Creacion de las fichas
    //Asignacion de poolFichas y cantFichas
    juegoTest->crearFichas();


    //Instanciacion de 4 jugadores
    Jugador* jugador1 = new Jugador("Jugador #1");
    Jugador* jugador2 = new Jugador("Jugador #2");
    Jugador* jugador3 = new Jugador("Jugador #3");
    Jugador* jugador4 = new Jugador("Jugador #4");

    //Ingreso de los 4 jugadores a Juego
    juegoTest->addJugador(jugador1);
    juegoTest->addJugador(jugador2);
    juegoTest->addJugador(jugador3);
    juegoTest->addJugador(jugador4);

    //Cantidad de jugadores
    cout << "\nCantidad de Jugadores Actuales: " << juegoTest->getCantJugadoresActuales() << "\n" << endl;

    //Cantidad inicial de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juegoTest->getPoolFichas()->printList();

}

/**
 *
 */
void comenzarJuego() {
    //Reparticion de las fichas a los jugadores
    juegoTest->repartirFichas();

    //Cantidad final de fichas
    cout<<""<<endl;
    cout<<"Pool de fichas"<<endl;
    juegoTest->getPoolFichas()->printList();

    juegoTest->siguienteTurno();
}

/**
 *
 */
void pasarTurno() {

    cout << "Jugador en turno: " << juegoTest->getEnTurno()->getNombre() << endl;

    //Agrega +1 a los turnos del jugador
    juegoTest->getEnTurno()->setTurnosPasados(juegoTest->getEnTurno()->getTurnosPasados() + 1);
    //Verifica los turnos seguidos de todos los jugadores
    juegoTest->checkTurnosPasados();
    //Verifica que el juego no haya terminado
    juegoTest->checkTerminado();
    //Pasa al siguiente turno con un nuevo jugador
    juegoTest->siguienteTurno();
}

void getJuego(string codigo){
    //Buscar entre los juegos el codigo que sea igual
    cout << "Modificar el juego con este codigo: " << codigo << endl;
}

//*********************************************************************************

void scrabble() {
    cout << "\nCall a Scrabble!" << endl;
}

void pasar() {
    cout << "\nCall a Pasar" << endl;
    pasarTurno();

}





void getInstruction(string instruccion){

    if (instruccion == "Scrabble!") {
        scrabble();
    } else if (instruccion == "Pasar" ) {
        pasarTurno();
    } else if (instruccion == "Iniciar") {
        inicio();
    } else if (instruccion == "Comenzar") {
        comenzarJuego();
    } else {
        //Para obtener que juego es el que se debe de modificar
        getJuego(instruccion);
    }
}



//*********************************************************************************






/**
 * Main del programa.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 */
int main(int argc, char **argv) {




    //*****************************************************************************************************

    int fd, fd2;

    struct sockaddr_in server;


    struct sockaddr_in client;



    if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
        printf("error en socket()\n");
        exit(-1);
    }

    server.sin_family = AF_INET;

    server.sin_port = htons(PORT);


    server.sin_addr.s_addr = INADDR_ANY;


    bzero(&(server.sin_zero),8);

    if(bind(fd,(struct sockaddr*)&server,
            sizeof(struct sockaddr))==-1) {
        printf("error en bind() \n");
        exit(-1);
    }

    if(listen(fd,BACKLOG) == -1) {
        printf("error en listen()\n");
        exit(-1);
    }

    printf("Servidor Scrabble abierto!\n");

    while(1) {

        unsigned int address_size = sizeof(client);

        if ((fd2 = accept(fd, (struct sockaddr *) &client,
                          &address_size)) == -1) {
            printf("error en accept()\n");
            exit(-1);
        }

        printf("Se obtuvo una conexión de un cliente.\n");

        ssize_t r;

        char buff[MAXDATASIZE];

        for (;;) {
            r = read(fd2, buff, MAXDATASIZE);

            if (r == -1) {
                perror("read");
                return EXIT_FAILURE;
            }
            if (r == 0)
                break;
            printf("READ: %s\n", buff);

            //*****************************
            //string str(buff);
            //getInstruction(str);
            //*****************************


            ///JUGADOR
            struct json_object *tempJugador;
            json_object *parsed_jsonJugador = json_tokener_parse(buff);
            json_object_object_get_ex(parsed_jsonJugador, "JUGADOR", &tempJugador);
            printf("Jugador: %s\n", json_object_get_string(tempJugador));

            //Llama a funcion para verificar la instruccion
            if (json_object_get_string(tempJugador) != 0) {
                getInstruction(json_object_get_string(tempJugador));
            }


            ///JUGADORES PERMITIDOS
            struct json_object *tempCantidad;
            json_object *parsed_jsonCantidad = json_tokener_parse(buff);
            json_object_object_get_ex(parsed_jsonCantidad, "JUGADORES PERMITIDOS", &tempCantidad);
            printf("Jugadores Permitidos: %s\n", json_object_get_string(tempCantidad));

            //Llama a funcion para verificar la instruccion
            if (json_object_get_string(tempCantidad) != 0) {
                getInstruction(json_object_get_string(tempCantidad));
            }


            ///BOTON
            struct json_object *tempBoton;
            json_object *parsed_jsonBoton = json_tokener_parse(buff);
            json_object_object_get_ex(parsed_jsonBoton, "BOTON", &tempBoton);
            printf("Boton: %s\n", json_object_get_string(tempBoton));

            //Llama a funcion para verificar la instruccion
            if (json_object_get_string(tempBoton) != 0) {
                getInstruction(json_object_get_string(tempBoton));
            }


            ///CODIGO
            struct json_object *tempCodigo;
            json_object *parsed_jsonCodigo = json_tokener_parse(buff);
            json_object_object_get_ex(parsed_jsonCodigo, "CODIGO", &tempCodigo);
            printf("Codigo: %s\n", json_object_get_string(tempCodigo));

            //Llama a funcion para verificar la instruccion
            if (json_object_get_string(tempCodigo) != 0) {
                getInstruction(json_object_get_string(tempCodigo));
            }


            memset(buff, 0, MAXDATASIZE);
        }

        close(fd2);

    }
    //*****************************************************************************************************









    /*


    //Inicio de la ventana del Juego
    inicio();







    //Comienzo del juego
    comenzarJuego();




    //Simula al jugador1 como si estuviese en turno
    juegoTest->setEnTurno(jugador1);
    cout<<"\n\nEn turno: " << juegoTest->getEnTurno()->getNombre() << endl;



    cout << "\nLista " << juegoTest->getEnTurno()->getNombre() << endl;

    //Imprime la cantidad de fichas del Jugador1
    juegoTest->getJ1()->getListaFichas()->printList();

    //Simulacion de haber escogido una ficha en la lista del jugador
    Ficha* fichaPreescogida = juegoTest->getJ1()->getListaFichas()->getHead()->getFicha();
    cout << "\nFicha por mover: " << fichaPreescogida->getLetra() << endl;


    cout << "\n\nLista Cuadricula" << endl;

    //Imprime la lista de fichas que tendria la cuadricula
    juegoTest->getCuadricula()->getListaCuadricula()->printList();


    ///Ficha que se movera a la cuadricula, proveniente del jugador
    Ficha* fichaEnMovimiento = juegoTest->getJ1()->colocarFicha(fichaPreescogida);

    ///Agregar la ficha del jugador a la cuadricula
    juegoTest->getCuadricula()->getListaCuadricula()->newNode(fichaEnMovimiento);
    cout << "\nSe ha agregado la ficha: " << fichaEnMovimiento->getLetra() << endl;

    cout << "\n\nLista Cuadricula" << endl;
    //Imprime la lista de fichas que estaran en la cuadricula
    juegoTest->getCuadricula()->getListaCuadricula()->printList();

    cout << "\n\nLista " << juegoTest->getEnTurno()->getNombre() << endl;
    //Imprime la lista de fichas del jugador1
    juegoTest->getJ1()->getListaFichas()->printList();

*/

    return 0;

}
