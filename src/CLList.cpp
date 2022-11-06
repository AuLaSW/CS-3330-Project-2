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
    return this->n == 0;
}

int CLList::size() const {
    return this->n;
}

const CLNode& CLList::front() const {
    return *this->back().next;
}

const CLNode& CLList::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return *this->cursor;
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
    this->n += 1;
}

void CLList::remove() {
    if (this->isEmpty()) {
        throw std::runtime_error("Cannot remove a node from an emtpy list.");
    }
    // set a temporary node to point to the front node
    CLNode *node = this->cursor->next;

    // set the back node's next pointer to point to
    // the node that comes after the front node
    this->cursor->next = this->cursor->next->next;
}

#endif /* ifndef CLLIST */
