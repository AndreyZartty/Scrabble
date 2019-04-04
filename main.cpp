//
// Created by cucho16 on 02/04/19.
//

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void lectura(string nombre, string dcc[]){
    fstream datos(nombre.c_str());
    string linea;
    int c=0;
    if(!datos.is_open()){
        datos.open(nombre.c_str(), ios::in);
    }
    if(nombre == "/home/cucho16/Documentos/Proyectos C++/Scrabble/diccio.txt"){
        while (getline(datos,linea)){
            //cout << linea << endl;
            dcc[c] =linea;
            c++;
        }
        datos.close();
    }
    else{
        cout << "Fichero inexistente" << endl;
    }
}

int comprobarPalabra(string nueva){
    int aDcc = 186594;
    string diccionario[190000] ={};
    lectura("/home/cucho16/Documentos/Proyectos C++/Scrabble/diccio.txt", diccionario);
    int c=0 ;
    while(c < aDcc){
        string actual = diccionario[c].substr(0,diccionario[c].length()-1);
        //cout << actual << endl;
        if(actual.compare(nueva) == 0){
            cout << "La palabra '"<< nueva << "' se encuentra en el diccionario en la posición: "<< c << endl;
            return 0;
        }
        c++;
    }
    cout << "La palabra '" << nueva << "' no se encuentra en el diccionario."<< endl;
}

int main(){

    string prueba = "exito";
    comprobarPalabra(prueba);
}

