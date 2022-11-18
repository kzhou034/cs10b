#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character::Character(HeroType _type, const string & _name, double hp, double atk) {
    type = _type;
    name = _name;
    health = hp;
    attackStrength = atk;
}

HeroType Character::getType() const{
    return type;
}

const string & Character::getName() const {
    return name;
}

/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const {
    return health;
}

/* Reduces health value by amount passed in. */
void Character::damage(double d) {
    health -= d;
}

/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const {
    bool intGreater = false;
    if (getHealth() > 0) {
        intGreater = true;
    }
    else {
        intGreater = false;
    }
    return intGreater;
}

/*virtual void Character::attack(Character &) {

}*/