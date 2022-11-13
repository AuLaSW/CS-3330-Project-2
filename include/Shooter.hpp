// Austin Swanlaw
#define SHOOTER
#include <string>

class Shooter {
public:
    // Constructor and Destructor
    Shooter ();
    Shooter (const std::string&);
    Shooter (const std::string&, const int);
    Shooter (const std::string&, const int, const int);
    Shooter (const Shooter&);
    virtual ~Shooter ();

    static const Shooter& createShooter(const std::string);

    /*
     * Accessors
     */
    // returns the name of the shooter
    std::string getName() const;

    // returns the remaining bullet count
    int getQuantity() const;
    int getInitialQuantity() const;

    // initiates the shooting command;
    // the shooter shoots one bullet
    void shooting();

    bool operator==(const Shooter&) const;

private:
    std::string name;
    int bulletCount;
    int initialBulletCount;

};
