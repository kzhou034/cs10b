#include <string>
#include "Character.h"

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character {
    public:
        Elf(const string &, double, double, string);
        bool family(const string) const;
        string getFamName() const;
        void attack(Character&);
    private: 
        //double hpMax;
        string fam;
};

#endif