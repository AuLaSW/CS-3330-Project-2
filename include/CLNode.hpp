// Austin Swanlaw
#define CLNODE

template<typename E>
class CLNode {
public:
    CLNode();
    virtual ~CLNode();

private:
    E element;
    CLNode<E>* next;

    template<typename T>
    friend class CLList;
};
