#include <iostream>
#include <string>
#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string & _name, double hp, double atk, int rnk): Character(WIZARD, _name, hp, atk),  _rank(rnk) {}

/*bool Wizard::alg(const string foeAlg) const {
    bool _a = false;
    if (_alg == foeAlg) {
        _a = true;
    }
    else {
        _a = false;
    }
    return _a;
}*/

int Wizard::rank() const {
    return _rank;
}

void Wizard::attack(Character& foe) {
    double dmg;
    if (foe.getType() == WIZARD) {
        Wizard &red = dynamic_cast<Wizard &>(foe);
        dmg = attackStrength * (static_cast<double>(_rank)/red._rank);
    }
    else {
        dmg = attackStrength;
    }
    cout << "Wizard " << name << " attacks " << foe.getName() << " --- POOF!!" << endl;
    cout << foe.getName() << " takes " << dmg << " damage." << endl;
    foe.damage(dmg);
    /*if (foe.getType() == WIZARD) {
        Wizard &red = dynamic_cast<Wizard &> (foe);
        if ( allegiance() == red.allegiance()) {
            cout << "Wizard " << name << " does not attack Wizard " << red.allegiance() << "." << endl;
            cout << "They share an allegiance with " << red.allegiance() << "." << endl;
        }
        else {
            cout << "Wizard " << name << " attacks " << red.name << " --- SLASH!!" << endl;
            cout << red.allegiance() << " takes " << dmg << " damage." << endl;
        }
    }
    else {
        cout << "Wizard " << name << " attacks " << foe.getName() << " --- TWANG!!" << endl;
        cout << foe.getName() << " takes " << dmg << " damage." << endl;
    }*/
}