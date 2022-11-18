#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string name);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(string name){
    ifstream fin;
    int value;
    int sum = 0;
    fin.open(name);
    if (!fin.is_open()) {
        cout << "Error opening " << name << endl;
        exit(1);
    }

    while (fin >> value) {
        sum += value;
    }
    fin.close();
    return sum;
}