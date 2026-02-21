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
