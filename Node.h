//
// Created by cucho16 on 26/03/19.
//

#ifndef SCRABBLE_NODE_H
#define SCRABBLE_NODE_H


class Node {
private:
    bool ocupado;
    bool especial;
    //Ficha ficha;
    Node* siguiente;
public:
    bool isOcupado();
    bool isEspecial();
    //Ficha getFicha();
    Node* getSiguiente();
    void setOcupado(bool ocup);
    void setEspecial(bool esp);
    //void setFicha(Ficha fich);
    void setSiguiente(Node* sig);
};


#endif //SCRABBLE_NODE_H
