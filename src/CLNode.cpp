#ifndef CLNODE
#define CLNODE 
#include "../include/CLNode.hpp"

CLNode::CLNode() {
    this->element = nullptr;
    this->next = nullptr;
}

CLNode::CLNode(const Shooter& s) {
    this->element = new Shooter(s);
}

CLNode::CLNode(const CLNode& node) : element(node.element), next(node.next) {
}

CLNode::~CLNode() {
    delete element;
    delete next;
}

#endif /* ifndef CLNODE */
