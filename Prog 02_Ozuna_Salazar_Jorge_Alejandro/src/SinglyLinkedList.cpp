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
