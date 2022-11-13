#ifndef CLNODE
#define CLNODE 
#include "../include/CLNode.hpp"

CLNode::CLNode() {
    this->next = nullptr;
}

CLNode::CLNode(const CLNode& node) : element(node.element), next(node.next) {
}

CLNode::~CLNode() {
}

void CLNode::add(Shooter& s) {
    this->element = s;      
}

#endif /* ifndef CLNODE */
