#include <iostream>
#include <limits>
#include "SinglyLinkedList.h"
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void limpiar_pantalla() {
    system("cls");
}

int leer_entero(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        }
        cout << "Entrada invalida. Solo numeros.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int leer_opcion() {
    int opcion;
    while (true) {
        cout << "Seleccione una opcion: ";
        if (cin >> opcion && opcion >= 0 && opcion <= 12) {
            return opcion;
        }
        cout << "Opcion invalida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void mostrar_menu() {
    cout << "\n===== MENU LISTA ENLAZADA =====\n";
    cout << "1. Insertar al inicio\n";
    cout << "2. Insertar al final\n";
    cout << "3. Insertar despues de un valor\n";
    cout << "4. Eliminar un valor\n";
    cout << "5. Buscar un valor\n";
    cout << "6. Mostrar lista\n";
    cout << "7. Mostrar primero (first)\n";
    cout << "8. Mostrar ultimo (last)\n";
    cout << "9. Siguiente nodo (next)\n";
    cout << "10. Nodo anterior (previous)\n";
    cout << "11. Ver nodo actual\n";
    cout << "12. Vaciar lista\n";
    cout << "0. Salir\n";
}

int main() {
    SinglyLinkedList lista;
    int opcion, valor, referencia;

    do {
        limpiar_pantalla();
        mostrar_menu();
        opcion = leer_opcion();

        switch (opcion) {
            case 1:
                valor = leer_entero("Valor a insertar al inicio: ");
                lista.insert_at_the_beggining(valor);
                break;

            case 2:
                valor = leer_entero("Valor a insertar al final: ");
                lista.insert_at_the_end(valor);
                break;

            case 3:
                valor = leer_entero("Valor a insertar: ");
                referencia = leer_entero("Insertar despues de: ");
                lista.insert_in_a_position(valor, referencia);
                break;

            case 4:
                valor = leer_entero("Valor a eliminar: ");
                lista.delete_one(valor);
                break;

            case 5:
                valor = leer_entero("Valor a buscar: ");
                lista.search(valor);
                break;

            case 6:
                lista.show_all();
                cout << endl;
                break;

            case 0:
                cout << "Saliendo...\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}