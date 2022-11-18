#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
#include <ostream>
using namespace std;

int main() {
    cout << "Enter a test number(1-6): ";
	int test;
	cin >> test;
	cout << endl;

    //pushfront
    if (test == 1) {
      cout << endl;
      cout << "sset1 constructor called" << endl;
      SortedSet sset1;
      cout << "pushfront 1" << endl;
      sset1.push_front(1);
      cout << "pushfront 2" << endl;
      sset1.push_front(2);
      cout << "pushfront 3" << endl;
      sset1.push_front(3);
      cout << "sset1: " << sset1 << endl;
   }
   if (test == 1) {
      cout << "sset1 destructor called" << endl;
   }
   
   //pushback
   if (test == 2) {
      cout << endl;
      cout << "sset2 constructor called" << endl;
      SortedSet sset2;
      cout << "pushback 10" << endl;
      sset2.push_back(10);
      cout << "pushback 20" << endl;
      sset2.push_front(20);
      cout << "pushback 30" << endl;
      sset2.push_back(30);
      cout << "sset2: " << sset2 << endl;
   }
   if (test == 2) {
      cout << "sset2 destructor called" << endl;
   }

    //union
    if (test == 3) {
      cout << endl;
      cout << "sset3 constructor called" << endl;
      SortedSet sset3;
      cout << "pushback 40" << endl;
      sset3.push_back(40);
      cout << "pushback 50" << endl;
      sset3.push_front(50);
      cout << "pushback 60" << endl;
      sset3.push_back(60);
      cout << "sset4 constructor called" << endl;
      SortedSet sset4;
      cout << "pushback 4" << endl;
      sset4.push_back(4);
      cout << "pushback 5" << endl;
      sset4.push_front(5);
      cout << "pushback 6" << endl;
      sset4.push_back(6);
      cout << "sset3: " << sset3 << endl;
      cout << "sset4: " << sset4 << endl;
      cout << "Union: " << sset3.operator|(sset4) << endl;
   }
   if (test == 3) {
      cout << "sset3 and sset4 destructor called" << endl;
   }

    //intersect
    if (test == 4) {
      cout << endl;
      cout << "sset5 constructor called" << endl;
      SortedSet sset5;
      cout << "pushback 7" << endl;
      //sset5.push_back(7);
      cout << "pushback 80" << endl;
      //sset5.push_front(80);
      cout << "pushback 90" << endl;
      //sset5.push_back(90);
      cout << "sset6 constructor called" << endl;
      SortedSet sset6;
      cout << "pushback 7" << endl;
      sset6.push_back(7);
      cout << "pushback 8" << endl;
      sset6.push_front(8);
      cout << "pushback 9" << endl;
      sset6.push_back(9);
      cout << "sset5: " << sset5 << endl;
      cout << "sset6: " << sset6 << endl;
      cout << "Intersection: " << sset5.operator&(sset6) << endl;
   }
   if (test == 4) {
      cout << "sset5 and sset6 destructor called" << endl;
   }

    //operator|=
    if (test == 5) {
      cout << endl;
      cout << "sset7 constructor called" << endl;
      SortedSet sset7;
      //cout << "pushback 20" << endl;
      //sset7.push_back(20);
      //cout << "pushback 30" << endl;
      //sset7.push_front(30);
      //cout << "pushback 40" << endl;
      //sset7.push_back(40);
      cout << "sset8 constructor called" << endl;
      SortedSet sset8;
      cout << "pushback 30" << endl;
      sset8.push_back(30);
      cout << "pushback 81" << endl;
      sset8.push_front(81);
      cout << "pushback 91" << endl;
      sset8.push_back(91);
      cout << "sset7: " << sset7 << endl;
      cout << "sset8: " << sset8 << endl;
      cout << "|=: " << sset7.operator|=(sset8) << endl;
      //cout << "&=: " << sset7.operator&=(sset8) << endl;
   }
   if (test == 5) {
      cout << "sset7 and sset8 destructor called" << endl;
   }

   //operator&=
    if (test == 6) {
      cout << endl;
      cout << "sset0 constructor called" << endl;
      SortedSet sset0;
      cout << "pushback 20" << endl;
      sset0.push_back(20);
      cout << "pushback 30" << endl;
      sset0.push_front(30);
      cout << "pushback 40" << endl;
      sset0.push_back(40);
      cout << "sset10 constructor called" << endl;
      SortedSet sset10;
      cout << "pushback 30" << endl;
      sset10.push_back(30);
      cout << "pushback 81" << endl;
      sset10.push_front(81);
      cout << "pushback 91" << endl;
      sset10.push_back(91);
      cout << "sset0: " << sset0 << endl;
      cout << "sset10: " << sset10 << endl;
      cout << "&=: " << sset0.operator&=(sset10) << endl;
   }
   if (test == 6) {
      cout << "sset0 and sset10 destructor called" << endl;
   }
    return 0;
}
