#ifndef SHOOTER
#define SHOOTER 
#include "../include/Shooter.hpp"
#include <stdexcept>

// create the shooter
Shooter::Shooter() : Shooter("", 0) {
}

Shooter::Shooter(const std::string name, const int initialBulletCount) {
    this->name = name;

    if (initialBulletCount < 0) {
        throw std::invalid_argument("Cannot have a bullet count less than 0.");
    }
    else {
        this->bulletCount = initialBulletCount;
        this->initialBulletCount = initialBulletCount;
    }
}

Shooter::Shooter(const Shooter& shooter) :
    name(shooter.name), bulletCount(shooter.bulletCount), 
    initialBulletCount(shooter.initialBulletCount) { }

// delete the shooter
Shooter::~Shooter() {
    
}

// return the name of the shooter
std::string Shooter::getName() {
    return this->name;
}

// return the number of bullets left
int Shooter::getQuantity() {
    return this->bulletCount;
}

// simulates shooting
void Shooter::shooting() {
    --this->bulletCount;
}

// method for displaying shooter information
void Shooter::display() {
    // write method
}

#endif /* ifndef SHOOTER */
