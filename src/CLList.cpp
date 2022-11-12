#ifndef CLLIST
#define CLLIST 
#include "../include/CLList.hpp"
#include <exception>
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

void CLList::add(const Shooter& e) {
    CLNode *node = new CLNode(e);

    // if the list is already populated then we have to
    // insert the node into the list with the following
    // motions
    if (!this->isEmpty()) {
        // set the node to point to the front node
        node->next = this->cursor->next;
        // set the back node to point to the new node
        this->cursor->next = node;
    }

    // set the cursor to point to the new node
    this->cursor = node;

    // set the current node to point to itself
    // if it is the only node in the list.
    if (this->size() == 0) {
        node->next = node;
    }

    // we perform this last because checking against 
    // 0 is faster than checking against another number.
    this->n += 1;
}

void CLList::remove() {
    if (this->isEmpty()) {
        throw std::runtime_error("Cannot remove a node from an emtpy list.");
    }
    try {
        CLNode *node = this->cursor->next;
        this->cursor->next = this->cursor->next->next;
        delete node;
    }
    catch (std::exception) {
        throw std::runtime_error("No node to remove!");
    }
    this->n--;
}

#endif /* ifndef CLLIST */
