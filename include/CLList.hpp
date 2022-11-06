// Austin Swanlaw
#define CLLIST
#include "CLNode.hpp"

/*
 * CLList Class
 * ------------
 *
 *  This class implements a simple Circularly 
 *  Linked List. The list can hold one element
 *  of any type since it is a template class.
 *
 */
template<typename E>
class CLList {
public:
    // Constructor and Destructor
    CLList();
    virtual ~CLList();

    // test if the list is empty
    bool isEmpty() const;
    // returns the size/length of the list
    int size() const;

    /*
     * Accessors
     */
    // return the front element (after cursor)
    const E& front() const;

    // return the back element (before cursor)
    const E& back() const;

    /*
     * Setters
     */
    // Move the cursor forward one
    void advance();

    // add an element to the list
    void add(const E& e);

    // remove an elemnt from the list
    void remove();

private:
    // beginning of list
    CLNode<E>* cursor;
    // size of the list (count of # of elements)
    int n;
};
