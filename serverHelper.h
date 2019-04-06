#ifndef SENDJSON_H
#define SENDJSON_H

#include <iostream>

using namespace std;


class serverHelper
{
private:
    string codigo = "0000";

public:
    serverHelper();

    string getCodigo();
    void setCodigo(string _codigo);

    int send(string instruccion);


};

#endif // SENDJSON_H
