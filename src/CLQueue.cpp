// Austin Swanlaw
#ifndef CLQUEUE
#define CLQUEUE 
#include "../include/CLQueue.hpp"
#include <iostream>

// constructor
CLQueue::CLQueue() {
    // default to having an empty list
    this->list = new CLList();
}

// destructor
CLQueue::~CLQueue() {
    // delete the list
    delete this->list;
}

// checks if the queue is empty
bool CLQueue::isEmpty() const {
    return list->isEmpty();
}

// returns the size of the queue
int CLQueue::size() const {
    return list->size();
}

// returns the front node of the queue
const Shooter& CLQueue::front() const {
    return list->front();
}

// adds an element to the queue.
// Add the element to the list, then
// move forward to add that new 
// element to the back of the list
void CLQueue::enqueue(const Shooter& e) {
    list->add(e);
    this->displayAddToQueue();
    list->advance();
}

// remove the front element from the queue
void CLQueue::dequeue() {
    // if it is the last time this is going
    // to be in the queue, then display that 
    // the shooter is done.
    if (this->front().getQuantity() == 1) {
        this->displayDone();
    }
    list->remove();
}

// displays when we are adding a shooter to the queue
void CLQueue::displayAddToQueue() const {
    // if we are adding a shooter to the queue for the first time,
    // then display this text stating such
    if (this->front().getQuantity() == this->front().getInitialQuantity()) {
        std::cout << "Shooter: " << this->front().getName()
            << " added to the queue. Remaining Bullets: "
            << this->front().getQuantity() << std::endl;
    }
    // otherwise, display how many bullets they have left
    // and that they are going back into the queue
    else if (this->front().getQuantity() > 0){
        std::cout << "Shooter: " << this->front().getName()
            << " was sent to the back of the queue. Remaining Bullets: "
            << this->front().getQuantity() << std::endl;
    }
}

// displays that the shooter is done shooting.
void CLQueue::displayDone() const {
        std::cout << "Shooter: " << this->front().getName()
            << " is completed!" << std::endl;
}

#endif /* ifndef CLQUEUE */
