#include <iostream>
#include <string>
#include "Character.h"
#include "Elf.h"

using namespace std;

Elf::Elf(const string & _name, double hp, double atk, string _fam): Character(ELF, _name, hp, atk), fam(_fam) {}

bool Elf::family(const string foeFam) const {
    bool _a = false;
    if (fam == foeFam) {
        _a = true;
    }
    else {
        _a = false;
    }
    return _a;
}

string Elf::getFamName() const {
    return fam;
}

void Elf::attack(Character& foe) {
    double dmg = (health/MAX_HEALTH) * attackStrength;
    if (foe.getType() == ELF) {
        Elf &red = dynamic_cast<Elf &> (foe);
        if ( getFamName() == red.getFamName()) {
            cout << "Elf " << name << " does not attack Elf " << red.getName() << "." << endl;
            cout << "They are both members of the " << red.getFamName() << " family." << endl;
        }
        else {
            cout << "Elf " << name << " shoots an arrow at " << red.getName() << " --- TWANG!!" << endl;
            cout << red.getName() << " takes " << dmg << " damage." << endl;
            foe.damage(dmg);
        }
    }
    else {
        cout << "Elf " << name << " shoots an arrow at " << foe.getName() << " --- TWANG!!" << endl;
        cout << foe.getName() << " takes " << dmg << " damage." << endl;
        foe.damage(dmg);
    }
    
}