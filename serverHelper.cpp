#include "serverHelper.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <json-c/json.h>
#include <json-c/debug.h>
#include <json-c/json_object.h>

#define PORT 3550
#define MAXDATASIZE 1000

serverHelper::serverHelper()
{

}

string serverHelper::getCodigo(){
    return codigo;
}
void serverHelper::setCodigo(string _codigo){
    codigo = _codigo;
}
string serverHelper::getJugador(){
    return jugador;
}
void serverHelper::setJugador(string _jugador){
    jugador = _jugador;
}
