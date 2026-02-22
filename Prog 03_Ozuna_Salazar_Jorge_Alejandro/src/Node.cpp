#include "Node.h"
#include "Student.h"

Node::Node() : data(nullptr), next(nullptr) {}

Node::Node(Student* stdnt) : data(stdnt), next(nullptr) {}

Node::Node(const Node &other) : next(nullptr) {
    if(other.data != nullptr) {
        data = new Student(*other.data);
    } else {
        data = nullptr;
    }
}

Node::~Node() {
    delete data;
    data = nullptr;
}

Node& Node::operator=(const Node &other) {
    if(this != &other) {
        delete data;
        
        if(other.data != nullptr) {
            data = new Student(*other.data);
        } else {
            data = nullptr;
        }

        next = nullptr;
    }

    return *this;
}

void Node::setData(Student *student) {
    data = student;
}

void Node::setNext(Node *node) {
    next = node;
}

Student* Node::getData() const{
    return data;
}

Node* Node::getNext() const{
    return next;
}

Student* Node::releaseData() {
    Student *temp = data;
    data = nullptr;
    return temp;
}