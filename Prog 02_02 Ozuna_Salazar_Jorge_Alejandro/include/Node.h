#ifndef NODE_H
#define NODE_H

#include <Student.h>

class Node {
private:
    Student *data;
    Node *next;

public:
    Node();
    explicit Node(Student *student);    
    
    Node(const Node& other);
    Node& operator=(const Node& other);
    virtual ~Node();
    
    void setData(Student *student);
    void setNext(Node *node);
    
    Student* getData() const;
    Node* getNext() const;
    
    Student* releaseData();
};

#endif // NODE_H
