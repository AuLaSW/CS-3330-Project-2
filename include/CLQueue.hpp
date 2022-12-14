// Austin Swanlaw
#define CLQUEUE
#include "CLList.hpp"

/*
 * CLQueue Class
 * -------------
 *
 *  This class implements a simple Queue using a Circularly
 *  Linked List.
 *
 */

class CLQueue {
public:
    // Constructor and Destructor
    CLQueue ();
    virtual ~CLQueue ();

    // returns true if the queue is empty
    bool isEmpty() const;
    // returns the size of the queue
    int size() const;

    /*
     * Accessors
     */
    // returns the element at the front of the queue
    const Shooter& front() const;

    /* 
     * Setters
     */
    // Add an element to the end of the queue
    void enqueue(const Shooter& e);

    // remove the front-most queue-element
    void dequeue();

private:
    // circularl list we are using to store the queue
    CLList* list;

    void displayAddToQueue() const;
    void displayDone() const;
};
