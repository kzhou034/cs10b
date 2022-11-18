#include "IntVector.h"
#include <iostream>
#include <stdexcept>

using namespace std;
/* 
    public:
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;

    private:
        unsigned _size; 
        unsigned _capacity; 
        int *_data;
*/
IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    
    if (capacity <= 0) {
        _data = nullptr;
    }
    else {
        _data = new int[capacity]; 
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }
}
IntVector::~IntVector(){
    delete[] _data;
}
unsigned IntVector::size() const {
    return _size;
}
unsigned IntVector::capacity() const {
    return _capacity;
}
bool IntVector::empty() const {
    bool empty = false;
    if (_size == 0) {
        empty = true;
    }
    return empty;
}
const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}
const int & IntVector::front() const {
    return _data[0];
}
const int & IntVector::back() const {
    return _data[_size - 1];
}
