#include <iostream>
#include "SimpleList.h"

using std::cout;
using std::endl;

SimpleList::SimpleList() : head(nullptr) {}
SimpleList::SimpleList(Node *h) : head(h) {}

SimpleList::~SimpleList() {
    while(!is_empty())
        remove_front();

    cout << endl;
    cout << "Lista simplemente enlazada de strings eliminada con exito" << std::endl;
    cout << endl;
}

bool SimpleList::is_empty() const {
    return head == nullptr;
}

void SimpleList::remove_front() {
    Node *old = head;
    head = old->next;
    cout << "Elemento eliminado: " << (old->data) << endl;
    delete old;
}

void SimpleList::mostrarTodo() {
    Node *aux = head;
    while(aux) {
        cout << aux->data << ", " << endl;
        aux = aux->next;
    }
}

void SimpleList::insertarInicio(int elem) {
    Node *temp = new Node(elem);
    if(head) {
        temp->next = head;
        head = temp;
    } else {
        head = temp;
    }
}

void SimpleList::insertarFinal(int elem) {
    Node *temp = new Node(elem);
    
    if(head == nullptr) {
        head = temp;
    } else {
        Node *aux = head;

        while(aux->next!=nullptr) {
            aux = aux->next;
        }
        aux->next = temp;
    }
}

void SimpleList::eliminar(int element) {
    if(head==nullptr)
        cout << "La Lista esta vacia" << endl;
    
    Node *aux = head;
    Node *auxDeleyed = nullptr;
    bool band = true;

    while(aux and band) {
        if(aux->data == element)
            band = false;
        else {
            auxDeleyed = aux;
            aux = aux->next; 
        }
    }

    if(aux==head) {
        head = head->next;
        delete aux;
    } else if(aux->next==nullptr) {
        auxDeleyed->next = nullptr;
        delete aux;
    } else {
        auxDeleyed->next = aux->next;
        delete aux;
    }
}