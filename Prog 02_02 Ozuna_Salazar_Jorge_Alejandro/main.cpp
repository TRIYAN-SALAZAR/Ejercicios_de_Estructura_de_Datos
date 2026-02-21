#include "StudentList.h"
#include "Student.h"
#include <iostream>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void clearScreen() {
        system("cls");
}

void pauseScreen() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Error: Debe ingresar un numero entero." << endl;
        clearInputBuffer();
        cout << prompt;
    }
    clearInputBuffer();
    return value;
}

float readFloat(const string& prompt) {
    float value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Error: Debe ingresar un numero valido." << endl;
        clearInputBuffer();
        cout << prompt;
    }
    clearInputBuffer();
    return value;
}

string readString(const string& prompt) {
    string value;
    cout << prompt;
    std::getline(cin, value);
    return value;
}

void showMainMenu() {
    cout << "\n+----------------------------------------------------+" << endl;
    cout << "|        SISTEMA DE GESTION DE ESTUDIANTES           |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "|  1. Inicializar lista                              |" << endl;
    cout << "|  2. Insertar estudiante al inicio                  |" << endl;
    cout << "|  3. Insertar estudiante al final                   |" << endl;
    cout << "|  4. Insertar estudiante en posicion                |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "|  5. Buscar estudiante por nombre                   |" << endl;
    cout << "|  6. Buscar estudiante en posicion                  |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "|  7. Eliminar estudiante por nombre                 |" << endl;
    cout << "|  8. Eliminar estudiante en posicion                |" << endl;
    cout << "|  9. Eliminar primer estudiante                     |" << endl;
    cout << "| 10. Eliminar todos los estudiantes                 |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "| 11. Mostrar todos los estudiantes                  |" << endl;
    cout << "| 12. Mostrar estudiante en posicion                 |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "| 13. Navegar por la lista (modo interactivo)        |" << endl;
    cout << "| 14. Ver informacion de la lista                    |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "|  0. Salir                                          |" << endl;
    cout << "+----------------------------------------------------+" << endl;
}

Student* createStudent() {
    cout << "\n--- Ingrese los datos del estudiante ---" << endl;
    
    int age = readInt("Edad: ");
    int grade = readInt("Grado: ");
    float average = readFloat("Promedio: ");
    string first_name = readString("Nombre: ");
    string last_name = readString("Apellido: ");
    
    return new Student(age, grade, average, first_name, last_name);
}

void inicializarLista(StudentList& lista) {
    cout << "\n=== INICIALIZAR LISTA ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista ya esta vacia." << endl;
    } else {
        char confirm;
        cout << "Esta seguro de que desea eliminar todos los estudiantes? (s/n): ";
        cin >> confirm;
        clearInputBuffer();
        
        if (confirm == 's' || confirm == 'S') {
            lista.inicializate();
            cout << "[OK] Lista inicializada correctamente." << endl;
        } else {
            cout << "Operacion cancelada." << endl;
        }
    }
}

void insertarAlInicio(StudentList& lista) {
    cout << "\n=== INSERTAR AL INICIO ===" << endl;
    Student* student = createStudent();
    lista.insert_at_the_beginning(student);
    cout << "[OK] Estudiante insertado al inicio de la lista." << endl;
}

void insertarAlFinal(StudentList& lista) {
    cout << "\n=== INSERTAR AL FINAL ===" << endl;
    Student* student = createStudent();
    lista.insert_at_the_end(student);
    cout << "[OK] Estudiante insertado al final de la lista." << endl;
}

void insertarEnPosicion(StudentList& lista) {
    cout << "\n=== INSERTAR EN POSICION ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia. El estudiante se insertara en la posicion 0." << endl;
    } else {
        cout << "Tamanio actual de la lista: " << lista.size() << endl;
    }
    
    int position = readInt("Ingrese la posicion (0 a " + 
                          std::to_string(lista.size()) + "): ");
    
    Student* student = createStudent();
    lista.insert_at_position(student, position);
}

void buscarPorNombre(StudentList& lista) {
    cout << "\n=== BUSCAR POR NOMBRE ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    string first_name = readString("Nombre: ");
    string last_name = readString("Apellido: ");
    
    Node* found = lista.search_by_name(first_name, last_name);
    
    if (found && found->getData()) {
        cout << "\n[OK] Estudiante encontrado:" << endl;
        cout << "--------------------------" << endl;
        found->getData()->display();
    }
}

void buscarEnPosicion(StudentList& lista) {
    cout << "\n=== BUSCAR EN POSICION ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    cout << "Tamanio de la lista: " << lista.size() << endl;
    int position = readInt("Ingrese la posicion: ");
    
    Node* found = lista.search_at_position(position);
    
    if (found && found->getData()) {
        cout << "\n[OK] Estudiante encontrado:" << endl;
        cout << "--------------------------" << endl;
        found->getData()->display();
    }
}

void eliminarPorNombre(StudentList& lista) {
    cout << "\n=== ELIMINAR POR NOMBRE ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    string first_name = readString("Nombre: ");
    string last_name = readString("Apellido: ");
    
    if (lista.delete_by_name(first_name, last_name)) {
        cout << "[OK] Estudiante eliminado exitosamente." << endl;
    }
}

void eliminarEnPosicion(StudentList& lista) {
    cout << "\n=== ELIMINAR EN POSICION ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    cout << "Tamanio de la lista: " << lista.size() << endl;
    int position = readInt("Ingrese la posicion: ");
    
    if (lista.delete_at_position(position)) {
        cout << "[OK] Estudiante eliminado exitosamente." << endl;
    }
}

void eliminarPrimero(StudentList& lista) {
    cout << "\n=== ELIMINAR PRIMER ESTUDIANTE ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    if (lista.delete_first()) {
        cout << "[OK] Primer estudiante eliminado exitosamente." << endl;
    }
}

void eliminarTodos(StudentList& lista) {
    cout << "\n=== ELIMINAR TODOS ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista ya esta vacia." << endl;
        return;
    }
    
    char confirm;
    cout << "Esta seguro de que desea eliminar todos los estudiantes? (s/n): ";
    cin >> confirm;
    clearInputBuffer();
    
    if (confirm == 's' || confirm == 'S') {
        lista.delete_all();
        cout << "[OK] Todos los estudiantes han sido eliminados." << endl;
    } else {
        cout << "Operacion cancelada." << endl;
    }
}

void mostrarTodos(StudentList& lista) {
    cout << "\n=== MOSTRAR TODOS ===" << endl;
    lista.show_all();
}

void mostrarEnPosicion(StudentList& lista) {
    cout << "\n=== MOSTRAR EN POSICION ===" << endl;
    
    if (lista.is_empty()) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    
    cout << "Tamanio de la lista: " << lista.size() << endl;
    int position = readInt("Ingrese la posicion: ");
    
    lista.show_at_position(position);
}

void navegarLista(StudentList& lista) {
    if (lista.is_empty()) {
        cout << "\nLa lista esta vacia." << endl;
        return;
    }
    
    Node* current = nullptr;
    int option;
    bool exit = false;
    
    while (!exit) {
        clearScreen();
        cout << "\n+----------------------------------------------------+" << endl;
        cout << "|           MODO NAVEGACION INTERACTIVA              |" << endl;
        cout << "+----------------------------------------------------+" << endl;
        
        if (current != nullptr && current->getData()) {
            cout << "\n--- Posicion actual ---" << endl;
            current->getData()->display();
        } else {
            cout << "\nNo hay posicion actual definida." << endl;
        }
        
        cout << "\n+----------------------------------------------------+" << endl;
        cout << "| 1. Ir al primer nodo                               |" << endl;
        cout << "| 2. Ir al ultimo nodo                               |" << endl;
        cout << "| 3. Ir al siguiente nodo                            |" << endl;
        cout << "| 4. Ir al nodo anterior                             |" << endl;
        cout << "| 5. Obtener nodo actual                             |" << endl;
        cout << "| 6. Reiniciar posicion actual                       |" << endl;
        cout << "| 7. Recorrer toda la lista (adelante)               |" << endl;
        cout << "| 0. Volver al menu principal                        |" << endl;
        cout << "+----------------------------------------------------+" << endl;
        
        option = readInt("\nSeleccione una opcion: ");
        
        switch (option) {
            case 1:
                current = lista.first();
                if (current && current->getData()) {
                    cout << "\n[OK] Movido al primer nodo." << endl;
                    pauseScreen();
                }
                break;
                
            case 2:
                current = lista.last();
                if (current && current->getData()) {
                    cout << "\n[OK] Movido al ultimo nodo." << endl;
                    pauseScreen();
                }
                break;
                
            case 3:
                current = lista.next_node();
                if (current && current->getData()) {
                    cout << "\n[OK] Movido al siguiente nodo." << endl;
                    pauseScreen();
                }
                break;
                
            case 4:
                current = lista.previous_node();
                if (current && current->getData()) {
                    cout << "\n[OK] Movido al nodo anterior." << endl;
                    pauseScreen();
                }
                break;
                
            case 5:
                current = lista.get_current();
                if (current && current->getData()) {
                    cout << "\n[OK] Nodo actual obtenido." << endl;
                    pauseScreen();
                } else {
                    pauseScreen();
                }
                break;
                
            case 6:
                lista.reset_current();
                current = lista.get_current();
                cout << "\n[OK] Posicion reiniciada al inicio." << endl;
                pauseScreen();
                break;
                
            case 7: {
                cout << "\n=== RECORRIDO COMPLETO ===" << endl;
                Node* temp = lista.first();
                int pos = 0;
                while (temp != nullptr) {
                    cout << "\n[Posicion " << pos << "]" << endl;
                    if (temp->getData()) {
                        temp->getData()->display();
                    }
                    temp = lista.next_node();
                    pos++;
                }
                pauseScreen();
                break;
            }
                
            case 0:
                exit = true;
                break;
                
            default:
                cout << "\n[ERROR] Opcion invalida." << endl;
                pauseScreen();
                break;
        }
    }
}

void verInformacion(StudentList& lista) {
    cout << "\n+----------------------------------------------------+" << endl;
    cout << "|           INFORMACION DE LA LISTA                  |" << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "| Tamanio: " << lista.size() << " estudiante(s)" << endl;
    cout << "| Estado: " << (lista.is_empty() ? "Vacia" : "Con datos") << endl;
    cout << "+----------------------------------------------------+" << endl;
}

void cargarDatosDePrueba(StudentList& lista) {
    cout << "\nCargando datos de prueba..." << endl;
    
    lista.insert_at_the_end(new Student(20, 3, 8.5f, "Juan", "Perez"));
    lista.insert_at_the_end(new Student(21, 4, 9.2f, "Maria", "Gonzalez"));
    lista.insert_at_the_end(new Student(19, 2, 7.8f, "Carlos", "Rodriguez"));
    lista.insert_at_the_end(new Student(22, 5, 8.9f, "Ana", "Lopez"));
    lista.insert_at_the_end(new Student(20, 3, 8.0f, "Pedro", "Martinez"));
    
    cout << "[OK] 5 estudiantes de prueba han sido agregados." << endl;
}

int main() {
    StudentList lista;
    int option;
    bool exit = false;
    
    char loadTest;
    cout << "Desea cargar datos de prueba? (s/n): ";
    cin >> loadTest;
    clearInputBuffer();
    
    if (loadTest == 's' || loadTest == 'S') {
        cargarDatosDePrueba(lista);
        pauseScreen();
    }
    
    while (!exit) {
        clearScreen();
        showMainMenu();
        option = readInt("\nSeleccione una opcion: ");
        
        switch (option) {
            case 1:
                inicializarLista(lista);
                pauseScreen();
                break;
                
            case 2:
                insertarAlInicio(lista);
                pauseScreen();
                break;
                
            case 3:
                insertarAlFinal(lista);
                pauseScreen();
                break;
                
            case 4:
                insertarEnPosicion(lista);
                pauseScreen();
                break;
                
            case 5:
                buscarPorNombre(lista);
                pauseScreen();
                break;
                
            case 6:
                buscarEnPosicion(lista);
                pauseScreen();
                break;
                
            case 7:
                eliminarPorNombre(lista);
                pauseScreen();
                break;
                
            case 8:
                eliminarEnPosicion(lista);
                pauseScreen();
                break;
                
            case 9:
                eliminarPrimero(lista);
                pauseScreen();
                break;
                
            case 10:
                eliminarTodos(lista);
                pauseScreen();
                break;
                
            case 11:
                mostrarTodos(lista);
                pauseScreen();
                break;
                
            case 12:
                mostrarEnPosicion(lista);
                pauseScreen();
                break;
                
            case 13:
                navegarLista(lista);
                break;
                
            case 14:
                verInformacion(lista);
                pauseScreen();
                break;
                
            case 0:
                cout << "\nEsta seguro de que desea salir? (s/n): ";
                char confirm;
                cin >> confirm;
                clearInputBuffer();
                if (confirm == 's' || confirm == 'S') {
                    exit = true;
                    cout << "\nGracias por usar el sistema!" << endl;
                }
                break;
                
            default:
                cout << "\n[ERROR] Opcion invalida. Por favor, intente nuevamente." << endl;
                pauseScreen();
                break;
        }
    }
    
    return 0;
}