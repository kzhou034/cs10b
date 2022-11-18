#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   string frnt;  //front

   if (s.size() <= 1) {
      s = s;
   }
   else {
      frnt = s.at(0);
      string temp = s.substr(1, s.size() - 1); //temp is s starting at index 1 to the end
      flipString(temp);
      s = temp + frnt;
   }
}

