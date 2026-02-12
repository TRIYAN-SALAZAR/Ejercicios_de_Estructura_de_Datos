#include "Node.h"

Node::Node() : data(0), next(nullptr) {}
Node::Node(int dt) : data(dt), next(nullptr) {}
Node::Node(int dt, Node *nxt) : data(dt), next(nxt) {}

Node::~Node() {}
