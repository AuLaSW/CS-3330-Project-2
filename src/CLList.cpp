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
template<typename E>
CLList<E>::CLList() {
    this->cursor = nullptr;
    this->n = 0;
}

/*
 * Destructor
 */
template<typename E>
CLList<E>::~CLList() {
    delete cursor;
}

template<typename E>
bool CLList<E>::isEmpty() const{
    return this->n == 0;
}

template<typename E>
int CLList<E>::size() const {
    return this->n;
}

template <typename E>
const E& CLList<E>::front() const {
    return this->back()->next;
}

template <typename E>
const E& CLList<E>::back() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        return this->cursor;
    }
}

template <typename E>
void CLList<E>::advance() {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty list cannot return a node.");
    }
    else {
        this->cursor = this->cursor->next;
    }
}

template <typename E>
void CLList<E>::add(const E& e) {
    CLNode<E> *node = new CLNode<E>(e);

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
}

template <typename E>
void CLList<E>::remove() {
    if (this->isEmpty()) {
        throw std::runtime_error("Cannot remove a node from an emtpy list.");
    }
    // set a temporary node to point to the front node
    CLNode<E> *node = this->front();

    // set the back node's next pointer to point to
    // the node that comes after the front node
    this->cursor->next = this->cursor->next->next;
}

#endif /* ifndef CLLIST */
