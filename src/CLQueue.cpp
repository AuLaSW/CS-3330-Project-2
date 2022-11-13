// Austin Swanlaw
#ifndef CLQUEUE
#define CLQUEUE 
#include "../include/CLQueue.hpp"

CLQueue::CLQueue() {
    
}

CLQueue::~CLQueue() {
    
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
}

void CLQueue::dequeue() {
    list->remove();
}

#endif /* ifndef CLQUEUE */
