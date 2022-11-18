#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream input;
   input.open(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!input.is_open()){
      cout << "Error opening file." << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   vector<int> vec;
   int n;
   char c;

   while (input >> n) {
      vec.push_back(n);
      input >> c;
   }

   // Close input stream.
   input.close();

   // Get integer average of all values read in.

   int total = 0;
   for (long unsigned int i = 0; i < vec.size(); i++) {
      total += vec.at(i);
   }
   int avg = total / vec.size();

   // Convert each value within vector to be the difference between the original value and the average.
   for (long unsigned int i = 0; i < vec.size(); i++) {
      vec.at(i) -= avg;
   }

   // Create output stream and open/create output csv file.
   ofstream output;
   output.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!output.is_open()){
      cout << "Error opening file." << endl;
      return 1;
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (long unsigned int i = 0; i < vec.size(); i++){
      output << vec.at(i);
      if (i < vec.size() - 1) {
         output << ", ";
      }
   }

   // Close output stream.
   output.close();

   return 0;
}