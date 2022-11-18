#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
using namespace std;

class IntVector {
    public: 
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        int & at(unsigned index);
        void insert(unsigned index, int value);
        void erase(unsigned index);
        const int & front() const;
        int & front();
        const int & back() const;
        int & back();
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
    private: 
        unsigned _size; //stores the size of the IntVector (the number of elements currently being used to store the user's values).
        unsigned _capacity; //store the size of the array (therefore must always be >= to _size).
        int *_data; //a pointer that stores the address of the dynamically-allocated array of integers
        void expand();  //private helper
        void expand(unsigned amount); //private helper
};

#endif