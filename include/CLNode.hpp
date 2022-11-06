// Austin Swanlaw
#define CLNODE
#include "Shooter.hpp"

class CLNode {
public:
    CLNode();
    CLNode(const Shooter&);
    virtual ~CLNode();

private:
    Shooter element;
    CLNode* next;

    friend class CLList;
};
