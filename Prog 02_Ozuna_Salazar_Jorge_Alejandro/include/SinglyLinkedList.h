#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <Node.h>

class SinglyLinkedList
{
    public:
        Node *head;
        Node *tail;
        Node *current_position;
        int total_nodes = 0;

        SinglyLinkedList();
        SinglyLinkedList(Node*);
        virtual ~SinglyLinkedList();

        void insert_at_the_beggining(int);
        void insert_at_the_end(int);
        void insert_in_a_position(int, int);

        void search(int);
        void delete_one(int);
        void delete_all();

        void show_all();

        bool is_empty();
        Node* first();
        Node* last();
        Node* previous_node();
        Node* next_node();
        int size();
};

#endif // SINGLYLINKEDLIST_H
