#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node *next;
        Node();
        Node(int);
        Node(int, Node*);
        virtual ~Node();
};

#endif // NODE_H
