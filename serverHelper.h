#ifndef SENDJSON_H
#define SENDJSON_H

#include <iostream>

using namespace std;


class serverHelper
{
private:
    string codigo;

public:
    serverHelper();

    string getCodigo();
    void setCodigo();

    int send(string instruccion);


};

#endif // SENDJSON_H
