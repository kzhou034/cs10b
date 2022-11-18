#include <iostream>
#include <string>
#include "Character.h"
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string & _name, double hp, double atk, string allegiance): Character(WARRIOR, _name, hp, atk), _alg(allegiance) {}

bool Warrior::alg(const string foeAlg) const {
    bool _a = false;
    if (_alg == foeAlg) {
        _a = true;
    }
    else {
        _a = false;
    }
    return _a;
}

string Warrior::allegiance() const {
    return _alg;
}

void Warrior::attack(Character& foe) {
    double dmg = (health/MAX_HEALTH) * attackStrength;
    if (foe.getType() == WARRIOR) {
        Warrior &red = dynamic_cast<Warrior &> (foe);
        if ( allegiance() == red.allegiance()) {
            cout << "Warrior " << name << " does not attack Warrior " << red.getName() << "." << endl;
            cout << "They share an allegiance with " << red.allegiance() << "." << endl;
        }
        else {
            cout << "Warrior " << name << " attacks " << red.name << " --- SLASH!!" << endl;
            cout << red.name << " takes " << dmg << " damage." << endl;
            foe.damage(dmg);
        }
    }
    else {
        cout << "Warrior " << name << " attacks " << foe.getName() << " --- SLASH!!" << endl;
        cout << foe.getName() << " takes " << dmg << " damage." << endl;
        foe.damage(dmg);
    }
}