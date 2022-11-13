// Austin Swanlaw
#define CLNODE
#include "Shooter.hpp"

// CLNode class
class CLNode {
public:
    // constructor
    CLNode();
    // copy constructor
    CLNode(const CLNode&);
    // destructor
    virtual ~CLNode();

    // add shooter element to node
    void add(const Shooter&);

    // get next node
    const CLNode& getNext() const;
    // get element from node
    const Shooter& getElement() const;

private:
    Shooter element;
    CLNode* next;

    friend class CLList;
};
