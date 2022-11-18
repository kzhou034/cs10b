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
        int & at(unsigned index);
        void insert (unsigned index, int value);
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
        unsigned _size; 
        unsigned _capacity; 
        int *_data;
        void expand();  //private helper
        void expand(unsigned amount); //private helper
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

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

/*
This function inserts data at position index. 
To do this, all values currently at position 
index and greater are shifted to the right by 1 
(to the element right after its current position).

Size will be increased by 1. 
However, If size will become larger than capacity, 
this function needs to first double the capacity. 
In other words, if capacity and size 
are both 20 when this function is called, 
this function must first increase the 
capacity to 40 and then it will be able 
to increase the size to 21.

Since other functions will also potentially 
need to expand (double) the capacity, 
call the private helper function named 
expand (see above) to do this for you.

This function should throw an out_of_range exception, 
passing it the string "IntVector::insert_range_check" 
if the index is too large. See bottom of specifications 
for more details on how to throw an exception and 
how to test that it works properly.
*/
void IntVector::insert(unsigned index, int value) {
    unsigned int i = 0;
    if (index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if (index < 0) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if (_size >= _capacity) {
        expand();
    }
    int* tempData = _data;
    _size += 1;
    _data = new int[_size];
    for (i = 0; i <= index; i++) {
        _data[i] = tempData[i];
    }
    for (i = index; i < _capacity; i++) {
        _data[i+1] = tempData[i];
    }
    _data[index] = value;
}

/* This function removes the value at position 
index and shifts all of the values at positions 
greater than index to the left by one 
(to the element right before its current position).

Size is decreased by 1.

This function should throw an out_of_range exception, 
passing it the string "IntVector::erase_range_check" 
if the index is too large. See bottom of specifications 
for more details on how to throw an exception and 
how to test that it works properly.

*/
void IntVector::erase(unsigned index) {
    unsigned int i = 0;
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    else if (index < 0) {
        throw out_of_range("IntVector::erase_range_check");
    }
    else {
        _size -= 1;
        for (i = index; i < _size + 1; i++) {
            _data[i] = _data[i+1];
        }
    }
}

const int & IntVector::front() const {
    return _data[0];
}

int & IntVector::front() {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size - 1];
}

int & IntVector::back() {
    return _data[_size - 1];
}

/*
Assigns new content to the vector object, 
dropping all the elements contained in the 
vector before the call and replacing them by 
those specified by the parameters. 
The new value of size will be n and all values 
stored in the vector will have the value of the 2nd parameter.

If the new value of size will be larger than capacity, 
then this function must first expand capacity by either 
double (expand()) or by increasing the capacity by a 
specific amount (expand(n - capacity)), whichever 
results in the largest capacity.
*/
void IntVector::assign(unsigned n, int value) { //resizes and populates vector object with 2nd parameter
    unsigned int i = 0;
    _size = n;
    resize(_size);

    for (i = 0; i < _size; i++) {
        _data[i] = value;
    }
}

/* This function inserts a value at the back end of the array.

Size will be increased by 1. However, If 
size will become larger than capacity, 
this function needs to first increase the capacity. 
In other words, if capacity and size are both 20 
when this function is called, capacity must first be 
increased to 40 and then size can be increased to 21.

Since other functions will also potentially 
need to expand (double) the capacity, call the private 
helper function named expand (see above) to do this for you. */
void IntVector::push_back(int value) {
    if (_size >= _capacity) {
        expand(); //doubles capacity
        _data[_size] = value;
        _size += 1;
    }
    else {
        _data[_size] = value;
        _size += 1;
    }
}

void IntVector::pop_back() {
    _size -= 1;
}

//This function reduces the size of the vector to 0.
void IntVector::clear() {
    _size = 0;
}

/*This function resizes the vector to contain size elements.

If size is smaller than the current size(_size), 
this function just reduces the value of _size to size.

If size is greater than the current size(_size), 
then the appropriate number of elements are 
inserted at the end of the vector, 
giving all of the new elements the 
value passed in through the 2nd parameter (value).

If the new value of size will be larger than capacity, 
then the capacity must first be expanded by either doubling (expand()) 
or by increasing the capacity by a 
specific amount (expand(new size - current capacity)), 
whichever results in the largest capacity. 
Then, this function can increase the size appropriately.*/
void IntVector::resize(unsigned size, int value) {
    unsigned int i = 0;
    unsigned int doubleCap = _capacity * 2;
    if (size > _capacity) {
        if (_capacity == 0) {
            expand(); //sets cap = 1
            expand(size); //then it increases by size 
        }
        else if (doubleCap > size) {
            expand(); //expand() doubles
        }
        else if (doubleCap < size) {
            expand(size); 
        }
    }
    if (size < _size) {
        _size = size;
    }
    else if (size > _size) {
        int* tempData = _data;
        unsigned int oldSize = _size;
        _size = size;
        _data = new int[_capacity];
        for (i = 0; i <= oldSize; i++) {
            _data[i] = tempData[i];
        }
        for (i = oldSize; i < _size; i++) {
            _data[i] = value;
        }
    }
}

/*This function requests that the capacity 
(the size of the dynamically allocated array) be 
set to n at minimum. 
This informs the vector of a planned increase in size.

This function should NOT ever reduce the size of the vector. 
If n is larger than the current capacity then the 
capacity should be expanded to n.

A call to this function never affects the elements 
contained in the vector, nor the vector's size.*/
void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        _capacity = n;
    }
}

/*This function will double the capacity of the vector. 
This function should reallocate memory for the dynamically 
allocated array and update the value of capacity. 
Make sure your expand() function properly handles 
the case when capacity is 0. 
This will be a special case within the expand() function. 
Since doubling 0 still gives you 0, you should 
set capacity to 1 in this special case.

Make sure you don't create a memory leak here.*/
void IntVector::expand() {  //double capacity of vector
    /*
    unsigned _capacity; //store the size of the array (therefore must always be >= to _size).
    int *_data; //a pointer that stores the address of the dynamically-allocated array of integers
    */
    unsigned i = 0;
    if (_capacity == 0) {
        _capacity = 1;
        _data = new int[_capacity];
    }
    else {
        int* tempData = _data;
        _capacity *= 2;
        _data = new int[_capacity];
        for (i = 0; i < _size; i++) {
            _data[i] = tempData[i]; 
        }
    }
}

/*This function will expand the capacity 
of the vector by the amount passed in. 
This function should reallocate memory for 
the dynamically allocated array and 
update the value of capacity.

Make sure you don't create a memory leak here.*/
void IntVector::expand(unsigned amount) {   //increase capacity by amount passed in
    unsigned i = 0;
    if (_capacity == 0) {
        _capacity = 1;
        _data = new int[_capacity];
    }
    else {
        int* tempData = _data;
        _capacity = amount;
        _data = new int[_capacity];
        for (i = 0; i < _size; i++) {
            _data[i] = tempData[i]; 
        }
    }
}