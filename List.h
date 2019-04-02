
#ifndef CODE_LIST_H
#define CODE_LIST_H

#include <stdlib.h>

#include "Node.h"

/**
 * Header de List.
 *
 * @author Ruben Salas
 * @since 26/03/19.
 * @version 1.1
 */
class List {

private:
    ///Primer node de List
    Node* head;
    ///Cantidad de nodos en List
    int len;

public:
    List();
    Node* getHead();
    void setHead(Node* _head);
    int getLen();
    void setLen(int _len);
    void newNode(Ficha* ficha);
    void deleteNode(Ficha* ficha);
    Node* getNode(int index);
    void printList();


};

#endif //CODE_LIST_H
