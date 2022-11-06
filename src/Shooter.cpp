#ifndef SHOOTER
#define SHOOTER 
#include "../include/Shooter.hpp"

// create the shooter
Shooter::Shooter() : Shooter("", 0) {
}

Shooter::Shooter(const std::string name, const int initialBulletCount) {
    this->name = name;
    this->bulletCount = 0;
    this->initialBulletCount = initialBulletCount;
}

Shooter::Shooter(const Shooter& shooter) {
    this->name = shooter.name;
    this->bulletCount = shooter.bulletCount;
    this->initialBulletCount = shooter.initialBulletCount;
}

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
