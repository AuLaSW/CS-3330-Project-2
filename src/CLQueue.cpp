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
}

void CLQueue::dequeue() {
    list->remove();
}

void CLQueue::displayAddToQueue() const {
    std::cout << "Shooter: " << this->front().getName()
        << " added to the queue. Remaining Bullets: "
        << this->front().getQuantity() << std::endl;
}

#endif /* ifndef CLQUEUE */
