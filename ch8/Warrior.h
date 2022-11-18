#include <string>
#include "Character.h"

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character {
    public:
        Warrior(const string &, double, double, string);
        bool alg(const string) const;
        string allegiance() const;
        void attack(Character&);
    private: 
        //double hpMax;
        string _alg;
};

#endif