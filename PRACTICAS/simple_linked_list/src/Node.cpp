#include "Node.h"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int data) : data(data), next(nullptr) {}

Node::Node(int data, Node *Next) : data(data), next(Next) {}