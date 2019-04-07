#ifndef SENDJSON_H
#define SENDJSON_H

#include <iostream>

using namespace std;


class serverHelper
{
private:
    string codigo = "0000";
    string jugador = "xxxx";

public:
    serverHelper();

    string getCodigo();
    void setCodigo(string _codigo);
    string getJugador();
    void setJugador(string _jugador);


};

#endif // SENDJSON_H
