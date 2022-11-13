#ifndef CLNODE
#define CLNODE 
#include "../include/CLNode.hpp"

CLNode::CLNode() {
    this->next = nullptr;
    this->element = *new Shooter();
}

CLNode::CLNode(const CLNode& node) : element(node.element), next(node.next) {
}

CLNode::~CLNode() {
}

void CLNode::add(Shooter& s) {
    this->element = s;      
}

const CLNode& CLNode::getNext() const {
    return *this->next;
}

const Shooter& CLNode::getElement() const {
    return this->element;
}

#endif /* ifndef CLNODE */
