#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <Node.h>

class SimpleList
{
    public:
        Node *head;
        SimpleList();
        SimpleList(Node*);

        void mostrarTodo();
        void insertarInicio(int);
        void insertarFinal(int);
        void eliminar(int);
};

#endif // SIMPLELIST_H
