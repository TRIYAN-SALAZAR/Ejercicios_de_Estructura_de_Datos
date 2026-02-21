#include "StudentList.h"

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
