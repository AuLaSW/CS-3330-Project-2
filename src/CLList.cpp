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
    while (!this->isEmpty()) {
        this->remove();
    }
}

// checks if the list is empty
bool CLList::isEmpty() const{
    return this->cursor == nullptr;
}

// returns the size of the list
int CLList::size() const {
    return this->n;
}

// returns the front node of the list
const Shooter& CLList::front() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return this->cursor->next->element;
    }
}

// returns the back node of the list
const Shooter& CLList::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return this->cursor->element;
    }
}

// moves the list forward one node
void CLList::advance() {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        this->cursor = this->cursor->next;
    }
}

// adds an node to the list
void CLList::add(const Shooter& e) {
    CLNode *node = new CLNode();
    node->add(e);

    // if the list is empty, then the
    // cursor just points to that node
    // and the node points to itself
    if (this->isEmpty()) {
        node->next = node;
        this->cursor = node;
    }
    // otherwise, insert the node
    // between the back and front nodes
    else {
        node->next = cursor->next;
        cursor->next = node;
    }

    // increase the length by one
    ++this->n;
}

// remove the front node from the list
void CLList::remove() {
    // set up a temporary node to point to
    // the front node
    CLNode *node = this->cursor->next;
    // if the lsit is empty, then throw an error
    if (this->isEmpty()) {
        throw std::runtime_error("Cannot remove a node from an emtpy list.");
    }
    // if the list only has one element, then
    // set the cursor to the nullptr
    else if (this->size() == 1) {
        this->cursor = nullptr;
    }
    // otherwise, point the cursor's next
    // value to the node after the first node
    else if (this->size() >= 1) {
        this->cursor->next = this->cursor->next->next;
    }

    // delete the node
    delete node;

    // decrement the size of the list
    --this->n;

}

#endif /* ifndef CLLIST */
