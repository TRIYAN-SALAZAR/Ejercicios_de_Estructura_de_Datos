#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <Node.h>

class SimpleList
{
    public:
        Node *head;
        SimpleList();
        SimpleList(Node*);
        ~SimpleList();

        void mostrarTodo();
        void insertarInicio(int);
        void insertarFinal(int);
        void eliminar(int);
        bool is_empty() const;
        void remove_front(); //Para asegurar que los nodos son eliminados correctamente
};

#endif // SIMPLELIST_H
