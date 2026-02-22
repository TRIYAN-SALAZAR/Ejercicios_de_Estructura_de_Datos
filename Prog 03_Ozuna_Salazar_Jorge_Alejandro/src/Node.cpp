#include "Node.h"
#include "Student.h"

Node::Node() : data(nullptr), next(nullptr), prev(nullptr) {}

Node::Node(Student* stdnt) : data(stdnt), next(nullptr), prev(nullptr) {}

Node::Node(const Node &other) : next(nullptr), prev(nullptr) {
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
        prev = nullptr;
    }

    return *this;
}

void Node::setData(Student *student) {
    data = student;
}

void Node::setNext(Node *node) {
    next = node;
}

void Node::setPrev(Node *node) {
    prev = node;
}

Student* Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrev() const {
    return prev;
}

Student* Node::releaseData() {
    Student *temp = data;
    data = nullptr;
    return temp;
}