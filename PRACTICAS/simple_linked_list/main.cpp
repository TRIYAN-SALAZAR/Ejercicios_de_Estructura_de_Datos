#include <iostream>
#include "SimpleList.h"

using namespace std;

int main()
{
    int dato;

    SimpleList *list = new SimpleList();

    list->insertarInicio(1);
    list->insertarInicio(2);
    list->insertarInicio(3);
    list->insertarInicio(4);

    list->insertarFinal(5);    
    list->insertarFinal(6);
    list->insertarFinal(7);

    list->mostrarTodo();
    
    cout << endl << endl;
    cout << "Dato a eliminar: ";
    cin  >> dato;
    
    while(getchar() != '\n');
    
    list->eliminar(dato);
    list->eliminar(5);
    list->mostrarTodo();

    return 0;
}
