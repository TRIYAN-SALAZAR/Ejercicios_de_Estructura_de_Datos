#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}
SinglyLinkedList::SinglyLinkedList(Node *node) : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    if(!is_emty())
        delete_all();
}
