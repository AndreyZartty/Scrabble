//
// Created by cucho16 on 05/04/19.
//
#include <iostream>
#include <cstdlib>

using namespace std;

string generarCodigo(){
    string abecedario = "abcdefghijklmnopqrstuvwxyz";
    string numeros = "1234567890";
    string abecedario2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string codigo;
    while (codigo.length() < 8){
        int random = rand() % 3 +1;
        if (random == 1){
            int r2 = rand() % 26;
            codigo = codigo + abecedario[r2];
        }
        else if (random == 2){
            int r2 = rand() % 10;
            codigo = codigo + numeros[r2];
        }
        else if (random == 3){
            int r2 = rand() % 26;
            codigo = codigo + abecedario2[r2];
        }
    }
    return codigo;
}

int main(){
    string codigo1 = generarCodigo();
    string codigo2 = generarCodigo();
    string codigo3 = generarCodigo();
    cout << codigo1 << endl;
    cout << codigo2 << endl;
    cout << codigo3 << endl;
}