#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"
#include <ostream>

using namespace std;

class SortedSet: public IntList {
    public:
        SortedSet(); //default
        SortedSet(const SortedSet &); //The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor.
        SortedSet(const IntList &); //A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
        ~SortedSet(); //The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate. You may very well find that this function does not need to do anything.
        bool in(int value) const; //This function returns true if the value passed in is a member of the set, otherwise false.
        SortedSet operator|(const SortedSet &) const; 
        SortedSet operator&(const SortedSet &) const;
        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        SortedSet operator|=(SortedSet &); 
        SortedSet operator&=(SortedSet &);
};

#endif