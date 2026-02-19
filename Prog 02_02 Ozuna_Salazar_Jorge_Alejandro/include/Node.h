#ifndef NODE_H
#define NODE_H

#include <Student.h>

class Node
{
    public:
        Student *data;
        Node *Next;

        Node();
        Node(Student* student);

        virtual ~Node();
};

#endif // NODE_H
