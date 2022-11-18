#include <string>
#include "Character.h"

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character {
    public:
        Wizard(const string &, double, double, int);
        //bool alg(const string) const;
        int rank() const;
        void attack(Character&);
    private: 
        //double hpMax;
        int _rank;
};

#endif