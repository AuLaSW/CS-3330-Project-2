// Austin Swanlaw
#define CLNODE
#include "Shooter.hpp"

class CLNode {
public:
    CLNode();
    CLNode(const CLNode&);
    //virtual ~CLNode();

    void add(Shooter&);

private:
    Shooter element;
    CLNode* next;

    friend class CLList;
};
