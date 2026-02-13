#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}
SinglyLinkedList::SinglyLinkedList(Node *node) : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    if(!is_emty())
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
}