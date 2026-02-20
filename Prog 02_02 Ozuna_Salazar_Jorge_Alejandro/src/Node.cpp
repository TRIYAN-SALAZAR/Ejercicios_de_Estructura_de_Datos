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

Node::~Node()
{

}
