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

#endif /* ifndef CLQUEUE */
