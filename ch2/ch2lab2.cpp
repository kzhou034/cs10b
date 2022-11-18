#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char ch);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;

   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    string str;
    int count = 0;
    while (!file.eof()) {
        getline(file, str);
        for (unsigned i = 0; i < str.size(); i++) {
            if (str.at(i) == ch) {
                count += 1;
            }
        }
    }
    file.close();
    return count;
}