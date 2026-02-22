#include "StudentList.h"
#include <iostream>

using std::cout;
using std::endl;

StudentList::StudentList()
    : head(nullptr), tail(nullptr), current_position(nullptr), total_nodes(0) {}

StudentList::StudentList(Student* student)
    : head(nullptr), tail(nullptr), current_position(nullptr), total_nodes(0) {
    if (student != nullptr) {
        head = new Node(student);
        tail = head;
        current_position = head;
        total_nodes = 1;
    }
}

StudentList::StudentList(const StudentList& other)
    : head(nullptr), tail(nullptr), current_position(nullptr), total_nodes(0) {
    if (other.head == nullptr) return;

    head = new Node(new Student(*other.head->getData()));
    tail = head;
    total_nodes = 1;

    Node* current_other = other.head->getNext();
    while (current_other != nullptr) {
        Node* new_node = new Node(new Student(*current_other->getData()));
        new_node->setPrev(tail);
        tail->setNext(new_node);
        tail = new_node;
        current_other = current_other->getNext();
        total_nodes++;
    }
}

StudentList& StudentList::operator=(const StudentList& other) {
    if (this != &other) {
        delete_all();

        if (other.head != nullptr) {
            head = new Node(new Student(*other.head->getData()));
            tail = head;
            total_nodes = 1;

            Node* current_other = other.head->getNext();
            while (current_other != nullptr) {
                Node* new_node = new Node(new Student(*current_other->getData()));
                new_node->setPrev(tail);
                tail->setNext(new_node);
                tail = new_node;
                current_other = current_other->getNext();
                total_nodes++;
            }
        }
    }
    return *this;
}

StudentList::~StudentList() {
    if (!is_empty())
        delete_all();
}

void StudentList::insert_at_the_beginning(Student* student) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    Node* temp = new Node(student);
    temp->setNext(head);

    if (head != nullptr) {
        head->setPrev(temp);   // el antiguo head ahora apunta atras
    } else {
        tail = temp;           // lista vacía: tail = head = nuevo nodo
    }

    head = temp;
    total_nodes++;
}

void StudentList::insert_at_the_end(Student* student) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    Node* temp = new Node(student);

    if (tail == nullptr) {
        head = temp;
        tail = temp;
    } else {
        temp->setPrev(tail);
        tail->setNext(temp);
        tail = temp;
    }

    total_nodes++;
}

void StudentList::insert_at_position(Student* student, int position) {
    if (student == nullptr) {
        cout << "Error: No se puede insertar un estudiante nulo" << endl;
        return;
    }

    if (position < 0) {
        cout << "Error: Posicion invalida" << endl;
        return;
    }

    if (position == 0 || head == nullptr) {
        insert_at_the_beginning(student);
        return;
    }

    // Llegar al nodo en position-1
    Node* aux = head;
    int current_pos = 0;

    while (aux->getNext() != nullptr && current_pos < position - 1) {
        aux = aux->getNext();
        current_pos++;
    }

    // Si aux es el ultimo nodo o hemos llegado al final, insertar al final
    if (aux->getNext() == nullptr) {
        insert_at_the_end(student);
        return;
    }

    // Insertar entre aux y aux->getNext()
    Node* temp = new Node(student);
    Node* next_node = aux->getNext();

    temp->setNext(next_node);
    temp->setPrev(aux);
    aux->setNext(temp);
    if (next_node != nullptr) {
        next_node->setPrev(temp);
    } else {
        tail = temp;
    }

    total_nodes++;

    cout << "Estudiante " << student->get_firstname() << " "
         << student->get_lastname() << " insertado en posicion "
         << position << endl;
}

Node* StudentList::search_by_name(const std::string& first_name,
                                   const std::string& last_name) {
    if (head == nullptr) {
        cout << "Lista vacia" << endl;
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
        cout << "Lista vacia" << endl;
        return nullptr;
    }

    if (position < 0) {
        cout << "Posicion invalida" << endl;
        return nullptr;
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posicion " << position << " fuera de rango" << endl;
        return nullptr;
    }

    return aux;
}

bool StudentList::delete_at_position(int position) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    if (position < 0) {
        cout << "Posicion invalida" << endl;
        return false;
    }

    if (position == 0) {
        return delete_first();
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posicion " << position << " fuera de rango" << endl;
        return false;
    }

    // Actualizar current_position si es necesario
    if (aux == current_position) {
        current_position = nullptr;
    }

    // Reconectar enlaces dobles
    if (aux->getPrev() != nullptr) {
        aux->getPrev()->setNext(aux->getNext());
    } else {
        head = aux->getNext();   // era el head
    }

    if (aux->getNext() != nullptr) {
        aux->getNext()->setPrev(aux->getPrev());
    } else {
        tail = aux->getPrev();   // era el tail
    }

    delete aux;
    total_nodes--;

    cout << "Estudiante en posicion " << position << " eliminado" << endl;
    return true;
}

bool StudentList::delete_by_name(const std::string& first_name,
                                  const std::string& last_name) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    Node* aux = head;
    while (aux != nullptr) {
        Student* student = aux->getData();
        if (student != nullptr &&
            student->get_firstname() == first_name &&
            student->get_lastname() == last_name) {
            break;
        }
        aux = aux->getNext();
    }

    if (aux == nullptr) {
        cout << "Estudiante " << first_name << " " << last_name
             << " no encontrado" << endl;
        return false;
    }

    if (aux == current_position) {
        current_position = nullptr;
    }

    // Reconectar enlaces dobles
    if (aux->getPrev() != nullptr) {
        aux->getPrev()->setNext(aux->getNext());
    } else {
        head = aux->getNext();   // era el head
    }

    if (aux->getNext() != nullptr) {
        aux->getNext()->setPrev(aux->getPrev());
    } else {
        tail = aux->getPrev();   // era el tail
    }

    delete aux;
    total_nodes--;

    cout << "Estudiante " << first_name << " " << last_name
         << " eliminado" << endl;
    return true;
}

bool StudentList::delete_first() {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return false;
    }

    Node* temp = head;
    head = head->getNext();

    if (head != nullptr) {
        head->setPrev(nullptr);  // el nuevo head no tiene anterior
    } else {
        tail = nullptr;          // la lista quedo vacia
    }

    if (temp == current_position) {
        current_position = head;
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
    tail = nullptr;
    current_position = nullptr;
    total_nodes = 0;
}

void StudentList::show_all() const {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Node* aux = head;
    int index = 1;

    cout << "\n+----------------------------------------------------+" << endl;
    cout << "|          LISTA DE ESTUDIANTES (DOBLE ENLACE)       |" << endl;
    cout << "+----------------------------------------------------+" << endl;

    while (aux != nullptr) {
        Student* student = aux->getData();
        if (student != nullptr) {
            cout << "| [" << index << "]" << endl;
            cout << "|   Nombre: " << student->get_firstname() << " "
                 << student->get_lastname() << endl;
            cout << "|   Edad: " << student->get_age() << endl;
            cout << "|   Grado: " << student->get_grade() << endl;
            cout << "|   Promedio: " << student->get_average() << endl;
            cout << "|   Prev: "
                 << (aux->getPrev() ? aux->getPrev()->getData()->get_firstname() : "NULL")
                 << " | Next: "
                 << (aux->getNext() ? aux->getNext()->getData()->get_firstname() : "NULL")
                 << endl;

            if (aux->getNext() != nullptr) {
                cout << "+----------------------------------------------------+" << endl;
            }
        }
        aux = aux->getNext();
        index++;
    }

    cout << "+----------------------------------------------------+" << endl;
    cout << "Total de estudiantes: " << total_nodes << endl;
}

void StudentList::show_at_position(int position) const {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    if (position < 0 || position >= total_nodes) {
        cout << "Posicion invalida" << endl;
        return;
    }

    Node* aux = head;
    int current_pos = 0;

    while (aux != nullptr && current_pos < position) {
        aux = aux->getNext();
        current_pos++;
    }

    if (aux == nullptr) {
        cout << "Posicion " << position << " fuera de rango" << endl;
        return;
    }

    Student* student = aux->getData();
    if (student != nullptr) {
        cout << "\n+----------------------------------------------------+" << endl;
        cout << "| Estudiante en posicion " << position << endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << "| Nombre: " << student->get_firstname() << " "
             << student->get_lastname() << endl;
        cout << "| Edad: " << student->get_age() << endl;
        cout << "| Grado: " << student->get_grade() << endl;
        cout << "| Promedio: " << student->get_average() << endl;
        cout << "+----------------------------------------------------+" << endl;
    }
}

bool StudentList::is_empty() const {
    return head == nullptr;
}

int StudentList::size() const {
    return total_nodes;
}

Node* StudentList::first() {
    if (head == nullptr) return nullptr;
    current_position = head;
    return current_position;
}

Node* StudentList::last() {
    if (tail == nullptr) {
        cout << "Lista vacia" << endl;
        return nullptr;
    }
    current_position = tail;
    return current_position;
}

Node* StudentList::get_current() {
    if (current_position == nullptr) {
        cout << "Posicion actual no definida" << endl;
        return nullptr;
    }
    return current_position;
}

Node* StudentList::next_node() {
    if (current_position == nullptr) {
        cout << "Posicion actual no definida. Use first() o last()" << endl;
        return nullptr;
    }

    if (current_position->getNext() == nullptr) {
        cout << "Ya esta en el ultimo nodo" << endl;
        return nullptr;
    }

    current_position = current_position->getNext();
    return current_position;
}

Node* StudentList::previous_node() {
    if (current_position == nullptr) {
        cout << "Posicion actual no definida. Use first() o last()" << endl;
        return nullptr;
    }

    if (current_position->getPrev() == nullptr) {
        cout << "Ya esta en el primer nodo" << endl;
        return nullptr;
    }

    current_position = current_position->getPrev();
    return current_position;
}

void StudentList::reset_current() {
    current_position = head;
}

void StudentList::inicializate() {
    if (!is_empty())
        delete_all();
}