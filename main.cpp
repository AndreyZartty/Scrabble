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

int main(){
    string diccionario[186594] ={};
    lectura("/home/cucho16/Documentos/Proyectos C++/Scrabble/diccio.txt", diccionario);
    cout << diccionario[139108] << endl;
    string prueba = "planta";
    int c=0 ;
    while(c<=186594){
        string actual = diccionario[c].substr(0,diccionario[c].length()-1);
        //cout << actual << endl;
        if(actual.compare(prueba) == 0){
            cout << c << endl;
            break;
        }
        c++;
    }
}

