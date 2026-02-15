#include "SinglyLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), current_position(nullptr), previous(nullptr), total_nodes(0) {}
SinglyLinkedList::SinglyLinkedList(Node *node) : head(nullptr), current_position(nullptr), previous(nullptr), total_nodes(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    if(!is_empty())
        delete_all();
}

void SinglyLinkedList::insert_at_the_beggining(int data) {
    Node *temp = new Node(data);
    temp->next = head;

    head = temp;
    total_nodes++;
}

void SinglyLinkedList::insert_at_the_end(int data) {
    Node *temp = new Node(data);

    if(!head)
        head = temp;
    else {
        Node *aux = head;
        while(aux->next != nullptr)
            aux = aux->next;

        aux->next = temp;
    }

    total_nodes++;
}

void SinglyLinkedList::insert_in_a_position(int data, int value_position_data) {

    if(head == nullptr) {
        cout << "Lista vacía. Insertando al inicio." << endl;
        insert_at_the_beggining(data);
        return;
    } else if(head->data == value_position_data) {
        insert_at_the_beggining(data);
        return;
    }

    Node *aux = head;
    while(aux != nullptr && aux->data != value_position_data) {
        aux = aux->next;
    }

    if(aux == nullptr) {
        cout << "Valor " << value_position_data << " no encontrado" << endl;
        return;
    }

    Node *temp = new Node(data);
    temp->next = aux->next;
    aux->next = temp;

    total_nodes++;
    
    cout << "Elemento " << data << " insertado después de " << value_position_data << endl;
}

void SinglyLinkedList::delete_one(int data) {
    if(head==nullptr) {
        cout << "La Lista esta vacia" << endl;
        return;
    }
    
    Node *aux = head;
    Node *auxPrevious = nullptr;
    bool band = true;

    while(aux and band) {
        if(aux->data == data)
            band = false;
        else {
            auxPrevious = aux;
            aux = aux->next; 
        }
    }

    if(aux == nullptr) {
        cout << "Elemento " << data << " no encontrado" << endl;
        return;
    }

    if(aux==head) {
        head = head->next;
    } else {
        auxPrevious->next = aux->next;
    }

    delete aux;
    total_nodes--;

    if(aux == current_position) {
        current_position = nullptr;
        previous = nullptr;
    }
}

void SinglyLinkedList::delete_all() {
    Node *aux = head;
    Node *temp;
    while(aux != nullptr) {
        temp = aux->next;
        delete aux;
        aux = temp;
    }

    head = nullptr;
    current_position = nullptr;
    previous = nullptr;
    total_nodes = 0;
}

int SinglyLinkedList::size() {
    return total_nodes;
}

bool SinglyLinkedList::is_empty() {
    if(head == nullptr) return true;
    return false;
}

void SinglyLinkedList::show_all() {
    Node *aux = head;

    if(aux == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    while(aux->next != nullptr) {
        cout << aux->data << "->";
        aux = aux->next;
    }
    cout << aux->data;
}

void SinglyLinkedList::search(int data) {
    
    if(head == nullptr) {
        cout << "No hay datos, Lista vacia" << endl;
        return;
    }
    
    Node *aux = head;
    while(aux != nullptr and aux->data != data) {
        aux = aux->next;
    }

    if(aux == nullptr)
        cout << "Valor " << data << " no existente" << endl;
    else
        cout << "Valor " << data << " encontrado" << endl;
}

Node* SinglyLinkedList::first() {
    if(head == nullptr)
        return nullptr;
    
    current_position = head;
    return current_position;
}

Node* SinglyLinkedList::last() {
    if(head == nullptr) {
        cout << "Lista vacia" << endl;
        return nullptr;
    }

    Node *aux = head;
    while(aux->next != nullptr) 
        aux = aux->next;
    
    current_position = aux;
    return current_position;
}

Node* SinglyLinkedList::next_node() {
    if(current_position == nullptr) {
        cout << "Posicion actual no definida. Use first() o last()" << endl;
        return nullptr;
    }

    if(head == nullptr) {
        cout << "Lista vacia" << endl;
        return nullptr;
    }

    if(current_position->next == nullptr) {
        cout << "Ya esta en el ultimo nodo" << endl;
        return nullptr;
    }

    previous = current_position;
    current_position = current_position->next;
    return current_position;
}

Node* SinglyLinkedList::previous_node() {
    if(current_position == nullptr) {
        cout << "Posicion actual no definida. Use first() o last()" << endl;
        return nullptr;
    }

    if(current_position == head) {
        cout << "Ya esta en el primer nodo" << endl;
        return nullptr;
    }

    current_position = previous;
    
    if(current_position == head) {
        previous = nullptr;
    } else {
        Node *aux = head;
        while(aux->next != current_position) {
            aux = aux->next;
        }
        previous = aux;
    }

    return previous;
}

Node* SinglyLinkedList::get_current() {
    if(current_position == nullptr) {
        cout << "Posicion actual no definida" << endl;
        return nullptr;
    }

    return current_position;
}

void SinglyLinkedList::reset_current() {
    current_position = head;
    previous = nullptr;
}