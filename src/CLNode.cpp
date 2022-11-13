#ifndef CLNODE
#define CLNODE 
#include "../include/CLNode.hpp"

// constructor
CLNode::CLNode() {
    this->next = nullptr;
    this->element = *new Shooter();
}

// copy constructor
CLNode::CLNode(const CLNode& node) : element(node.element), next(node.next) {
}

// destructor (empty)
CLNode::~CLNode() {
}

// copy the element we are adding into the node
void CLNode::add(const Shooter& s) {
    this->element = s;      
}

// get the next node the current node points to
const CLNode& CLNode::getNext() const {
    return *this->next;
}

// get the element of the current node
const Shooter& CLNode::getElement() const {
    return this->element;
}

#endif /* ifndef CLNODE */
