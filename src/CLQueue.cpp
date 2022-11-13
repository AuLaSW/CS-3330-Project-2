// Austin Swanlaw
#ifndef CLQUEUE
#define CLQUEUE 
#include "../include/CLQueue.hpp"
#include <iostream>

CLQueue::CLQueue() {
    this->list = new CLList();
}

CLQueue::~CLQueue() {
    delete this->list;
}

bool CLQueue::isEmpty() const {
    return list->isEmpty();
}

int CLQueue::size() const {
    return list->size();
}

const Shooter& CLQueue::front() const {
    return list->front();
}

void CLQueue::enqueue(const Shooter& e) {
    list->add(e);
    list->advance();
    this->displayAddToQueue();
}

void CLQueue::dequeue() {
    if (this->front().getQuantity() == 1) {
        this->displayDone();
    }
    list->remove();
}

void CLQueue::displayAddToQueue() const {
    if (this->front().getQuantity() == this->front().getInitialQuantity()) {
        std::cout << "Shooter: " << this->front().getName()
            << " added to the queue. Remaining Bullets: "
            << this->front().getQuantity() << std::endl;
    }
    else if (this->front().getQuantity() > 0){
        std::cout << "Shooter: " << this->front().getName()
            << " was sent to the back of the queue. Remaining Bullets: "
            << this->front().getQuantity() << std::endl;
    }
    else {
        std::cout << "Shooter: " << this->front().getName()
            << " is completed!" << std::endl;
    }
}

void CLQueue::displayDone() const {
        std::cout << "Shooter: " << this->front().getName()
            << " is completed!" << std::endl;
}

#endif /* ifndef CLQUEUE */
