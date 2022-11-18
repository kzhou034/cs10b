#include "IntVector.h"
#include <iostream>
using namespace std;

int main() {
    //sees if size and capacity is assigned/outputs correctly
    IntVector testVec(10, 1);
    cout << "Size Test - " << endl;
    cout << "Size: " << testVec.size() << endl;
    cout << endl;
    cout << "Capacity Test - " << endl;
    cout << "Capacity: " << testVec.capacity() << endl;
    cout << endl;

    //test empty
    IntVector testVec2(10, 2);
    bool expected = false;
    bool actual = testVec2.empty();
    if(actual != expected) {
        cout << "Empty Test - " << endl;
        cout << "Error: IntVect()::empty(). Actual: " << actual << ", Expected: " << expected << endl;
        exit(1);  //program terminates if there is an error
    }
    else{
        cout << "Empty test - " << endl;
        cout << "Expected: " << expected << ", Actual: " << actual << endl; 
        cout << endl;
    }

    //test at
    IntVector testVec3(10, 3);
    cout << "At Test - " << endl;
    cout << "Expected: 3, Actual: " << testVec3.at(2) << endl;
    cout << endl;

    //test front
    IntVector testVec4(10, 4);
    cout << "Front Test - " << endl;
    cout << "Expected: 4, Actual: " << testVec4.front() << endl;
    cout << endl;

    //test back
    IntVector testVec5(10, 5);
    cout << "Back Test - " << endl;
    cout << "Expected: 5, Actual: " << testVec5.back() << endl;
    cout << endl;

    return 0;
}