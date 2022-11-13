// Austin Swanlaw
#define SHOOTER
#include <string>

class Shooter {
public:
    // Constructor and Destructor
    Shooter ();
    Shooter (const std::string, const int);
    Shooter (const Shooter&);
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

    bool operator==(const Shooter&);

private:
    std::string name;
    int bulletCount;
    int initialBulletCount;

};
