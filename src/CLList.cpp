#ifndef CLLIST
#define CLLIST 
#include "../include/CLList.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

/*
 * Default Constructor
 * -------------------
 *
 *  Create a new CLNode cursor
 *  and initializes the size to 0.
 */
CLList::CLList() {
    this->cursor = nullptr;
    this->n = 0;
}

/*
 * Destructor
 */
CLList::~CLList() {
    delete cursor;
}

bool CLList::isEmpty() const{
    return (this->n == 0 && this->cursor == nullptr);
}

int CLList::size() const {
    return this->n;
}

const Shooter& CLList::front() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return *this->cursor->next->element;
    }
}

const Shooter& CLList::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return *this->cursor->element;
    }
}

void CLList::advance() {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        this->cursor = this->cursor->next;
    }
}

void CLList::add(Shooter& e) {
    CLNode *node = new CLNode();
    node->add(e);

    if (this->isEmpty()) {
        node->next = node;
        this->cursor = node;
    }
    else {
        node->next = cursor->next;
        cursor->next = node;
    }

    // we perform this last because checking against 
    // 0 is faster than checking against another number.
    this->n += 1;
}

void CLList::remove() {
    CLNode *node = new CLNode(*this->cursor->next);
    if (this->isEmpty()) {
        throw std::runtime_error("Cannot remove a node from an emtpy list.");
    }
    else if (node == cursor) {
        this->cursor = nullptr;
    }

    std::cout << node << std::endl;
    std::cout << cursor << std::endl;

    delete node;

    /*
    CLNode *node = this->cursor->next;

    this->cursor->next = this->cursor->next->next;

    delete node;
    */

    this->n--;
}

#endif /* ifndef CLLIST */
