//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
   double total = 0;
   int j;
   for (j = 0; j < arraySize; j++) {
      total = total + array[j];
   }
   double avg = total / arraySize;
   return avg;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {
   int k;
   double temp = 0;
   
   for (k = index; k < arraySize - 1; k++) {
      temp = array[k];
      array[k] = array[k+1];
      array[k+1] = temp;
   }
   --arraySize;
   cout << endl;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
   int l;
   for (l = 0; l < arraySize; l++) {
      if (l < arraySize - 1) {
         cout << array[l] << ", ";
      }
      else {
         cout << array[l];
      }
   }
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {

   // verify file name provided on command line
   ifstream ifFS;
   string nameOfFile = argv[1];

   // open file and verify it opened
   ifFS.open(nameOfFile);
   if(!ifFS.is_open()) {
      cout << "Error opening " << nameOfFile << endl;
      exit(1);
   }

   // Declare an array of doubles of size ARR_CAP.
   double arrays[ARR_CAP];

   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   double val = 0;
   int i = 0;
   int counter = 0;
   while (ifFS >> val) {
      arrays[i] = val;
      i++;
      counter++;
   }

   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(arrays, counter) << endl;

   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int indexRemove = 0;
   cout << "Enter index of value to be removed (0 to " << counter - 1 << "): "  << endl;
   cin >> indexRemove;
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(arrays, counter);
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(arrays, counter, indexRemove);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(arrays, counter);
   
   // Call the mean function again to get the new mean
   cout << endl;
   cout << "Mean: " << mean(arrays, counter);
   
   ifFS.close();

	return 0;
}