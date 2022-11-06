// Austin Swanlaw
#define SHOOTER
#include <string>

class Shooter {
public:
    // Constructor and Destructor
    Shooter ();
    virtual ~Shooter ();

    /*
     * Accessors
     */
    // returns the name of the shooter
    std::string getName();
    // returns the remaining bullet count
    int getQuantity();

    // initiates the shooting command;
    // the shooter shoots one bullet
    void shooting();
    // display shooter information on screen
    void display();

private:
    std::string name;
    int bulletCount;
    int initialBulletCount;
};
