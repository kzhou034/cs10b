#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date::Date() {
   this->day = 1;
   this->month = 1;
   this->monthName = "January";
   this->year = 2000;
}

//input 1 (using numbers)
Date::Date(unsigned m, unsigned d, unsigned y) {
   bool changeM = false;
   bool changeD = false;
   this->month = m;
   this->day = d;
   this->year = y;
   this->monthName = name(m);
   if (m < 1) {
      this->month = 1;
      this->monthName = "January";
      changeM = true;
   }
   if (m > 12) {
      this->month = 12;
      this->monthName = "December";
      changeD = true;
   }
   if(d != daysPerMonth(m, y)) {
      if (d < 1) {
      this->day = 1;
      changeD = true;
      } 
      else if (d > daysPerMonth(m, y)) {
      this->day = daysPerMonth(m, y);
      changeD = true;
      }
   }
   if(number(monthName) == 0) {
      this->day = 1;
      this->month = 1;
      this->monthName = "January";
      this->year = 2000;
      changeM = true;
   }
   if (changeM && changeD == false) {
      cout << "Invalid month name: the Date was set to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }
   if (changeD) {
      cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }
}

//input 2 (using name of month)
Date::Date(const string &mn, unsigned d, unsigned y) {
   bool changeM = false;
   bool changeD = false;
   this->monthName = mn;
   this->day = d;
   this->year = y;
   monthName.at(0) = toupper(monthName.at(0));
   this->month = number(monthName);
   for (unsigned int i = 1; i < mn.size(); i++) {
      monthName.at(i) = tolower(monthName.at(i));
   }
   if(d != daysPerMonth(number(this->monthName), y)) {
         if (d < 1) {
         this->day = 1;
         changeD = true;
      }
      else if (d > daysPerMonth(number(this->monthName), y)) {
         this->day = daysPerMonth(number(this->monthName), y);
         changeD = true;
      }
   }
   if(number(monthName) == 0) {
      this->day = 1;
      this->month = 1;
      this->monthName = "January";
      this->year = 2000;
      changeM = true;
   }
   if (changeM) {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   }
   else if (changeD) {
      cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }  
}

//prints date with numbers
void Date::printNumeric() const {
cout << this->month << "/" << this->day << "/" << this->year;
}

//prints date with name of month
void Date::printAlpha() const {
cout << this->monthName << " " << this->day << ", " << this->year;
}

//determines of year is a leap year
bool Date::isLeap(unsigned y) const {
   if (y % 400 == 0) {
      return true;
   } 
   else if (y % 100 == 0) {
      return false;
   } 
   else if (y % 4 == 0) {
      return true;
   }
   else {
      return false;
   }
}

//returns number of days in a month
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (isLeap(y)) {
      if (m == 2) {
         return 29;
      }
   }
   if (m == 2) {
      return 28;
   }
   if (m == 4 || m == 6 || m == 9 || m == 11) {
      return 30;
   }
   else {
      return 31;
   } 
}

//returns name of month
string Date::name(unsigned m) const {
   if (m == 1) {
      return "January";
   }
   else if (m == 2) {
      return "February";
   }
   else if (m == 3) {
      return "March";
   }
   else if (m == 4) {
      return "April";
   }
   else if (m == 5) {
      return "May";
   }
   else if (m == 6) {
      return "June";
   }
   else if (m == 7) {
      return "July";
   }
   else if (m == 8) {
      return "August";
   }
   else if (m == 9) {
      return "September";
   }
   else if (m == 10) {
      return "October";
   }
   else if (m == 11) {
      return "November";
   }
   else if (m == 12) {
      return "December";
   }
   return "December";
}

//returns number of the month
unsigned Date::number(const string &mn) const {
   if (mn == "January") {
      return 1;
   }
   else if (mn == "February") {
      return 2;
   }
   else if (mn == "March") {
      return 3;
   }
   else if (mn == "April") {
      return 4;
   }
   else if (mn == "May") {
      return 5;
   }
   else if (mn == "June") {
      return 6;
   }
   else if (mn == "July") {
      return 7;
   }
   else if (mn == "August") {
      return 8;
   }
   else if (mn == "September") {
      return 9;
   }
   else if (mn == "October") {
      return 10;
   }
   else if (mn == "November") {
      return 11;
   }
   else if (mn == "December") {
      return 12;
   }
   return 0;
}




// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}