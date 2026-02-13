#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <Node.h>

class SinglyLinkedList
{
    public:
        Node *head;
        SinglyLinkedList();
        SinglyLinkedList(Node*);
        virtual ~SinglyLinkedList();

        void insert_at_the_beggining(int);
        void insert_at_the_end(int);
        void insert_in_a_position(int);

        void search(int);
        void delete_one(int);
        void delete_all();

        bool is_emty();
        void first();
        void last();
        void previous_node();
        void next_node();
        void size();
};

#endif // SINGLYLINKEDLIST_H
