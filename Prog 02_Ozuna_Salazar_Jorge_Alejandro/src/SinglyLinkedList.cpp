#include "SinglyLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}
SinglyLinkedList::SinglyLinkedList(Node *node) : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    if(!is_empty())
        delete_all();
}

void SinglyLinkedList::insert_at_the_beggining(int data) {
    Node *temp = new Node(data);
    if(head) {
        temp->next = head;
        head = temp;
    } else {
        head = temp;
    }
    
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
        delete aux;
    } else if(aux->next==nullptr) {
        auxPrevious->next = nullptr;
        delete aux;
    } else {
        auxPrevious->next = aux->next;
        delete aux;
    }

    total_nodes--;
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
    total_nodes = 0;
}

int SinglyLinkedList::size() {
    return total_nodes;
}

bool SinglyLinkedList::is_empty() {
    if(head == nullptr) return true;
    return false;
}