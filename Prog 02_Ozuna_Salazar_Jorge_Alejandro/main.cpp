#include <iostream>
#include <limits>
#include <cstdlib>
#include "SinglyLinkedList.h"

using std::cin;
using std::cout;
using std::endl;

void limpiar_pantalla() {
    system("cls");
}

void pausar() {
    cout << endl << "Presione ENTER para continuar..." << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

int leer_entero(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        }
        cout << "Entrada invalida. Solo numeros." << endl;
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
        cout << "Opcion invalida. Intente de nuevo." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void mostrar_menu() {
    cout << "===== MENU LISTA ENLAZADA =====" << endl;
    cout << "1. Insertar al inicio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Insertar despues de un valor" << endl;
    cout << "4. Eliminar un valor" << endl;
    cout << "5. Buscar un valor" << endl;
    cout << "6. Mostrar lista" << endl;
    cout << "7. Mostrar primero (first)" << endl;
    cout << "8. Mostrar ultimo (last)" << endl;
    cout << "9. Siguiente nodo (next)" << endl;
    cout << "10. Nodo anterior (previous)" << endl;
    cout << "11. Ver nodo actual" << endl;
    cout << "12. Vaciar lista" << endl;
    cout << "13. Inicializar Lista" << endl;
    cout << "0. Salir" << endl;
}

int main() {
    SinglyLinkedList lista;
    int opcion, valor, referencia;

    do {
        limpiar_pantalla();
        mostrar_menu();
        opcion = leer_opcion();

        limpiar_pantalla();

        switch (opcion) {
            case 1:
                valor = leer_entero("Valor a insertar al inicio: ");
                lista.insert_at_the_beggining(valor);
                cout << "Elemento " << valor << " insertado al inicio." << endl;
                break;

            case 2:
                valor = leer_entero("Valor a insertar al final: ");
                lista.insert_at_the_end(valor);
                cout << "Elemento " << valor << " insertado al final." << endl;
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
                cout << "Lista actual: ";
                lista.show_all();
                cout << endl;
                break;

            case 7: {
                Node* n = lista.first();
                if (n) cout << "Primero: " << n->data << endl;
                break;
            }

            case 8: {
                Node* n = lista.last();
                if (n) cout << "Ultimo: " << n->data << endl;
                break;
            }

            case 9: {
                Node* n = lista.next_node();
                if (n) cout << "Siguiente: " << n->data << endl;
                break;
            }

            case 10: {
                Node* n = lista.previous_node();
                if (n) cout << "Anterior: " << n->data << endl;
                break;
            }

            case 11: {
                Node* n = lista.get_current();
                if (n) cout << "Actual: " << n->data << endl;
                break;
            }

            case 12:
                lista.delete_all();
                cout << "Lista vaciada." << endl;
                break;
            case 13:
                lista.inicializate();
                cout << "Lista vaciada eh inicializada" << endl;
            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                break;
        }

        if (opcion != 0) {
            pausar();
        }

    } while (opcion != 0);

    return 0;
}