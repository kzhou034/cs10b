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


    //tests empty (two tests)
    IntVector testVec2(10,2);
    bool expected = false;
    bool actual = testVec2.empty(); //is the vector empty? yes = 1, no = 0
    if(actual != expected) {
        cout << "Empty Test - " << endl;
        cout << "Error: IntVect()::empty(). Actual: " << actual << ", Expected: " << expected << endl;
        cout << endl;
 //       exit(1);  //program terminates if there is an error
    }
    else{
        cout << "Empty test - " << endl;
        cout << "Expected: " << expected << ", Actual: " << actual << endl; 
        cout << endl;
    }

    IntVector test_Vec2;
    expected = false;
    actual = test_Vec2.empty(); //is the vector empty? yes = 1, no = 0
    if(actual != expected) {
        cout << "Empty Test - " << endl;
        cout << "Error: IntVect()::empty(). Actual: " << actual << ", Expected: " << expected << endl;
        cout << endl;
 //       exit(1);  //program terminates if there is an error
    }
    else{
        cout << "Empty test - " << endl;
        cout << "Expected: " << expected << ", Actual: " << actual << endl; 
        cout << endl;
    }

    //tests at
    IntVector testVec3(10, 3);
    cout << "At Test - " << endl;
    cout << "Expected: 3, Actual: " << testVec3.at(2) << endl;
    cout << endl;

    //tests insert
    IntVector testVec4(10, 4);
    cout << "Insert Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec4.size(); i++) {
        cout << testVec4.at(i) << " ";
    }
    testVec4.insert(3,8);
    cout << endl;
    cout << "After: " << endl;
    for (unsigned int i = 0; i < testVec4.size(); i++) {
        cout << testVec4.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    //tests erase
   IntVector testVec5(10, 5);
    cout << "Erase Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec5.size(); i++) {
        cout << testVec5.at(i) << " ";
    }
    testVec5.erase(1);
    cout << endl;
    cout << "After: "<< endl;
    for (unsigned int i = 0; i < testVec5.size(); i++) {
        cout << testVec5.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    //tests front
    IntVector testVec6(10, 6);
    cout << "Front Test - " << endl;
    cout << "Expected: 6, Actual: " << testVec6.front() << endl;
    cout << endl;

    //tests back
    IntVector testVec7(10, 7);
    cout << "Back Test - " << endl;
    cout << "Expected: 7, Actual: " << testVec7.back() << endl;
    cout << endl;

    //tests assign
    //IntVector testVec8(10, 8);
    
    //tests push_back
    IntVector testVec9(10, 9);
    cout << "Push_back Test - " << endl;
    cout << "Before: ";
    for (unsigned int i = 0; i < testVec9.size(); i++) {
        cout << testVec9.at(i) << " ";
    }
    cout << endl;
    testVec9.push_back(8);
    cout << "After: ";
    for (unsigned int i = 0; i < testVec9.size(); i++) {
        cout << testVec9.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    //tests pop_back
    IntVector testVec10(10, 10);
    cout << "Pop_back Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec10.size(); i++) {
        cout << testVec10.at(i) << " ";
    }
    testVec10.pop_back();
    cout << endl;
    cout << "After: "<< endl;
    for (unsigned int i = 0; i < testVec10.size(); i++) {
        cout << testVec10.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    //tests clear
    IntVector testVec11(10, 11);
    cout << "Clear Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec11.size(); i++) {
        cout << testVec11.at(i) << " ";
    }
    testVec11.clear();
    cout << endl;
    cout << "After: "<< endl; 
    for (unsigned int i = 0; i < testVec11.size(); i++) {
        cout << testVec11.at(i) << " ";
    }
    cout << "Cleared." << endl; //there should be no values before this
    cout << endl;

    //tests resize
    IntVector testVec12(10, 12);
    cout << "Resize Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec12.capacity(); i++) {
        cout << testVec12.at(i) << " ";
    }
    cout << endl;
    testVec12.resize(15, 3);
    cout << "After: " << endl;
    for (unsigned int i = 0; i < testVec12.capacity(); i++) {
        cout << testVec12.at(i) << " ";
    }
    cout << endl;
    cout << endl;

    //tests reserve
     IntVector testVec13(10, 13);
    cout << "Reserve Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec13.capacity(); i++) {
        cout << testVec13.at(i) << " ";
    }
    cout << endl;
    testVec12.reserve(15);
    cout << "After: " << endl;
    for (unsigned int i = 0; i < testVec13.capacity(); i++) {
        cout << testVec13.at(i) << " ";
    }
    cout << endl;
    cout << endl; 

    //tests expand
  /*  IntVector testVec14(10, 14);
    cout << "Expand() Test - " << endl;
    cout << "Before: " << endl;
    for (unsigned int i = 0; i < testVec14.capacity(); i++) {
        cout << testVec14.at(i) << " ";
    }
    cout << endl;
    testVec14.expand();
    cout << "After: " << endl;
    for (unsigned int i = 0; i < testVec14.capacity(); i++) {
        cout << testVec14.at(i) << " ";
    }
    cout << endl;
    cout << endl;
    

    //tests expand(parameter)
    //IntVector testVec15(10, 15); */
    

    return 0;
}