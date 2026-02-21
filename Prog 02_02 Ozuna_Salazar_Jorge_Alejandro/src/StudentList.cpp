#include "StudentList.h"

#include <iostream>

using std::cout;
using std::endl;

StudentList::StudentList() : head(nullptr), current_position(nullptr), previous(nullptr), total_nodes(0) {}

StudentList::StudentList(Student* student) : head(nullptr), current_position(nullptr), previous(nullptr), total_nodes(0) {
    if(student != nullptr) {
        head = new Node(student);
        current_position = head;
        total_nodes = 1;
    }
}

StudentList::StudentList(const StudentList& other) : head(nullptr), current_position(nullptr), previous(nullptr), total_nodes(0) {
    if (other.head == nullptr) {
        return;
    }

    head = new Node(new Student(*other.head->getData()));
    total_nodes = 1;

    Node* current_other = other.head->getNext();
    Node* current_this = head;

    while (current_other != nullptr) {
        Node* new_node = new Node(new Student(*current_other->getData()));
        current_this->setNext(new_node);
        current_this = new_node;
        current_other = current_other->getNext();
        total_nodes++;
    }
}

StudentList& StudentList::operator=(const StudentList& other) {
    if (this != &other) {
        // Limpiar la lista actual
        delete_all();

        if (other.head != nullptr) {
            // Copiar el primer nodo
            head = new Node(new Student(*other.head->getData()));
            total_nodes = 1;

            // Copiar el resto de nodos
            Node* current_other = other.head->getNext();
            Node* current_this = head;

            while (current_other != nullptr) {
                Node* new_node = new Node(new Student(*current_other->getData()));
                current_this->setNext(new_node);
                current_this = new_node;
                current_other = current_other->getNext();
                total_nodes++;
            }
        }
    }
    return *this;
}

StudentList::~StudentList() {
    if(!is_empty()) 
        delete_all();
}

void StudentList::insert_at_the_beginning(Student* student) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    Node* temp = new Node(student);
    temp->setNext(head);
    head = temp;
    total_nodes++;
}


void StudentList::insert_at_the_end(Student* student) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    Node* temp = new Node(student);

    if (head == nullptr) {
        head = temp;
    } else {
        Node* aux = head;
        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(temp);
    }

    total_nodes++;
}

void StudentList::insert_at_position(Student* student, int position) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    if (position < 0) {
        cout << "Error: Posición inválida" << endl;
        return;
    }

    if (position == 0 || head == nullptr) {
        insert_at_the_beginning(student);
        return;
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux->getNext() != nullptr && current_pos < position - 1) {
        aux = aux->getNext();
        current_pos++;
    }

    Node* temp = new Node(student);
    temp->setNext(aux->getNext());
    aux->setNext(temp);
    total_nodes++;

    cout << "Estudiante " << student->get_firstname() << " " 
         << student->get_lastname() << " insertado en posición " 
         << position << endl;
}

Node* StudentList::search_by_name(const std::string& first_name, 
                                   const std::string& last_name) {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return nullptr;
    }

    Node* aux = head;
    while (aux != nullptr) {
        Student* student = aux->getData();
        if (student != nullptr && 
            student->get_firstname() == first_name && 
            student->get_lastname() == last_name) {
            return aux;
        }
        aux = aux->getNext();
    }

    cout << "Estudiante " << first_name << " " << last_name 
         << " no encontrado" << endl;
    return nullptr;
}

Node* StudentList::search_at_position(int position) {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return nullptr;
    }

    if (position < 0) {
        cout << "Posición inválida" << endl;
        return nullptr;
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posición " << position << " fuera de rango" << endl;
        return nullptr;
    }

    return aux;
}

bool StudentList::delete_at_position(int position) {
    if (head == nullptr) {
        cout << "La lista está vacía" << endl;
        return false;
    }

    if (position < 0) {
        cout << "Posición inválida" << endl;
        return false;
    }

    if (position == 0) {
        return delete_first();
    }

    Node* aux = head;
    Node* aux_previous = nullptr;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux_previous = aux;
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posición " << position << " fuera de rango" << endl;
        return false;
    }

    // Actualizar punteros de navegación si es necesario
    if (aux == current_position) {
        current_position = nullptr;
        previous = nullptr;
    } else if (aux == previous) {
        previous = nullptr;
    }

    aux_previous->setNext(aux->getNext());
    delete aux;
    total_nodes--;

    cout << "Estudiante en posición " << position << " eliminado" << endl;
    return true;
}


bool StudentList::delete_by_name(const std::string& first_name, const std::string& last_name) {
    if (head == nullptr) {
        cout << "La lista está vacía" << endl;
        return false;
    }

    Node* aux = head;
    Node* aux_previous = nullptr;

    while (aux != nullptr) {
        Student* student = aux->getData();
        if (student != nullptr && 
            student->get_firstname() == first_name && 
            student->get_lastname() == last_name) {
            break;
        }
        aux_previous = aux;
        aux = aux->getNext();
    }

    if (aux == nullptr) {
        cout << "Estudiante " << first_name << " " << last_name << " no encontrado" << endl;
        return false;
    }

    // Actualizar punteros de navegación si es necesario
    if (aux == current_position) {
        current_position = nullptr;
        previous = nullptr;
    } else if (aux == previous) {
        previous = nullptr;
    }

    if (aux == head) {
        head = head->getNext();
    } else {
        aux_previous->setNext(aux->getNext());
    }

    delete aux;
    total_nodes--;

    cout << "Estudiante " << first_name << " " << last_name << " eliminado" << endl;
    return true;
}

bool StudentList::delete_first() {
    if (head == nullptr) {
        cout << "La lista está vacía" << endl;
        return false;
    }

    Node* temp = head;
    head = head->getNext();

    if (temp == current_position) {
        current_position = head;
        previous = nullptr;
    }

    delete temp;
    total_nodes--;

    return true;
}

void StudentList::delete_all() {
    Node* aux = head;
    Node* temp;

    while (aux != nullptr) {
        temp = aux->getNext();
        delete aux;
        aux = temp;
    }

    head = nullptr;
    current_position = nullptr;
    previous = nullptr;
    total_nodes = 0;
}

void StudentList::show_all() const {
    if (head == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Node* aux = head;
    int index = 1;

    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║          LISTA DE ESTUDIANTES                      ║" << endl;
    cout << "╠════════════════════════════════════════════════════╣" << endl;

    while (aux != nullptr) {
        Student* student = aux->getData();
        if (student != nullptr) {
            cout << "║ [" << index << "]" << endl;
            cout << "║   Nombre: " << student->get_firstname() << " " 
                 << student->get_lastname() << endl;
            cout << "║   Edad: " << student->get_age() << endl;
            cout << "║   Grado: " << student->get_grade() << endl;
            cout << "║   Promedio: " << student->get_average() << endl;
            
            if (aux->getNext() != nullptr) {
                cout << "╟────────────────────────────────────────────────────╢" << endl;
            }
        }
        aux = aux->getNext();
        index++;
    }

    cout << "╚════════════════════════════════════════════════════╝" << endl;
    cout << "Total de estudiantes: " << total_nodes << endl;
}

void StudentList::show_at_position(int position) const {
    if (head == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    if (position < 0 or position > total_nodes) {
        cout << "Posición inválida" << endl;
        return;
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posición " << position << " fuera de rango" << endl;
        return;
    }

    Student* student = aux->getData();
    if (student != nullptr) {
        cout << "\n╔════════════════════════════════════════════════════╗" << endl;
        cout << "║ Estudiante en posición " << position << endl;
        cout << "╠════════════════════════════════════════════════════╣" << endl;
        cout << "║ Nombre: " << student->get_firstname() << " " 
             << student->get_lastname() << endl;
        cout << "║ Edad: " << student->get_age() << endl;
        cout << "║ Grado: " << student->get_grade() << endl;
        cout << "║ Promedio: " << student->get_average() << endl;
        cout << "╚════════════════════════════════════════════════════╝" << endl;
    }
}

bool StudentList::is_empty() const {
    return head == nullptr;
}

int StudentList::size() const {
    return total_nodes;
}

Node* StudentList::first() {
    if (head == nullptr) {
        return nullptr;
    }

    current_position = head;
    previous = nullptr;
    return current_position;
}

Node* StudentList::last() {
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
        return nullptr;
    }

    Node* aux = head;
    previous = nullptr;

    while (aux->getNext() != nullptr) {
        previous = aux;
        aux = aux->getNext();
    }

    current_position = aux;
    return current_position;
}