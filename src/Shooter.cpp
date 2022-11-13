#ifndef SHOOTER
#define SHOOTER 
#include "../include/Shooter.hpp"
#include <stdexcept>
#include <iostream>

// create the shooter
Shooter::Shooter() : Shooter("", 0, 0) {
}

// construct shooter from a file input
Shooter::Shooter(const std::string& str) : 
    Shooter(Shooter::createShooter(str)){ }

// construct a shooter from just a name and an initial bullet count
Shooter::Shooter(const std::string& name, const int initialBulletCount) : 
    Shooter(name, initialBulletCount, initialBulletCount) { }

// copy constructor for shooters
Shooter::Shooter(const Shooter& shooter) : 
    Shooter(shooter.name, shooter.bulletCount, shooter.initialBulletCount) { }

// create shooter from member data
Shooter::Shooter(const std::string& name, const int bulletCount, 
                 const int initialBulletCount) {
    this->name = name;

    if (initialBulletCount < 0 || bulletCount < 0) {
        throw std::invalid_argument("Cannot have a bullet count less than 0.");
    }
    else {
        this->bulletCount = bulletCount;
        this->initialBulletCount = initialBulletCount;
    }
}

// delete the shooter
Shooter::~Shooter() {
    
}

// create a shooter from string input (such as from a file)
const Shooter& Shooter::createShooter(const std::string str) {
    std::string delim = " ";

    // get the name from the string, the first value
    std::string name = str.substr(0, str.find(delim));
    // get the bullet count from the string, the second value
    int bulletCount = stoi(str.substr(str.find(delim), str.length() - 1));
    // bullet count is the same as the initial bullet count
    int initialBulletCount = bulletCount;

    // return a shooter object.
    return *(new Shooter(name, bulletCount, initialBulletCount));
}

// return the name of the shooter
std::string Shooter::getName() const {
    return this->name;
}

// return the number of bullets left
int Shooter::getQuantity() const {
    return this->bulletCount;
}

// return the initial quantity of bullets the shooter had
int Shooter::getInitialQuantity() const {
    return this->initialBulletCount;
}

// simulates shooting
// decrements the number of bullets
// unless there are no bullets, in which case it throws an error
void Shooter::shooting() {
    if (this->bulletCount == 0) {
        throw std::out_of_range("No bullets left to shoot.");
    }
    else {
        --this->bulletCount;
    }
}

// this operator is really only used when comparing
// in the test suite.
bool Shooter::operator==(const Shooter& b) const {
    return ( this->name == b.name
             && this->bulletCount == b.bulletCount
             && this->initialBulletCount == b.initialBulletCount );
}

#endif /* ifndef SHOOTER */
