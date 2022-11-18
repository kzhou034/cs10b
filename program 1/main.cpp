#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
 
using namespace std;
 
void readData(const string &nameOfFile, vector<double> &flightPath, vector<double> &coef);
 
double interpolation(double num, const vector<double> &flightPath, const vector<double> &coefficient);
 
bool isOrdered(const vector<double> &flight);
 
void reorder(vector<double> &flight, vector<double> &coef);
 
int main(int argc, char* argv[]) {
 
    //cout << "OUTPUT TEST" << endl; 

    string fn;
    string fileName; 
    vector <double> angles;  //angles  (first column in tunnel)
    vector<double> lift;    //coefficients of lift (2nd column in tunnel)
    bool inOrder = false;  
    double userInput;
    //the two doubles below are for determining the range 
    double lowest = 0;
    double highest = 0;
    //continue to ask for more coefficients?
    string userYesNo = "Yes";
    double intp; //stores interpolation value
 
    fn = argv[1];
 
  //  cin >> fileName;   //input name of file
    
    while (userYesNo != "No" && userYesNo != "no" && userYesNo != "n") {

        //reads data from tunnel file
        readData(fn, angles, lift);
        
        //determines whether vector angles is in ascending order
        inOrder = isOrdered(angles);  

        //if true, it does not run. if false, it runs.
        if (inOrder != true) {
            reorder(angles, lift);
        }
    
        //doubles represent range that userInput should be in
        lowest = angles.at(0);
        highest = angles.at(angles.size() - 1); // .size() - 1 to get index of last element in reordered vector

        cin >> userInput;

        //checks if userInput is within the range
        if (userInput > highest || userInput < lowest) {
            exit(1);
        }
        if (userInput == lowest){
            cout << lift.at(0) << endl;
        }
        else if (userInput == highest){
            cout << lift.at(lift.size() - 1) << endl;
        }
        else if (userInput > lowest && userInput < highest) {
            //checks if userInput already has a coefficient of lift by finding userInput (which is an angle) in vector angles
            for (unsigned int i = 0; i < angles.size(); i++){
                if (userInput == angles.at(i)) {
                    cout << lift.at(i) << endl;
                }
            }
            //if it isn't in vector angles, use interpolation
            intp = interpolation(userInput, angles, lift);
            cout << intp << endl;
        }
        cin >> userYesNo; 
    }
    
    return 0;
}
 
//write functions below
void readData(const string &nameOfFile, vector<double> &flight, vector<double> &coef){
    ifstream file;
 
    file.open(nameOfFile);
    if (!file.is_open()) {
        cout << "Error opening " << nameOfFile << endl;
        exit(1);
    }
 
    double val; //values from tunnel data
    vector <double> temp;
    if (temp.size() == 0) {
        while (file >> val){
            temp.push_back(val);
        }
    }
    for (unsigned int i = 0; i < temp.size(); i += 2) {
        flight.push_back(temp.at(i));
    }
    for (unsigned int i = 1; i < temp.size(); i += 2) {
        coef.push_back(temp.at(i));
    }
    file.close();
}

//similar to linear approximation in math (like a midpoint)
double interpolation(double num, const vector<double> &flight, const vector<double> &coef) {
    double y;
    double low; 
    double high;
    //num is the angle of flight path that user wants to find

    for (unsigned int i = 0; i < flight.size(); i++){
        if (num == flight.at(i)){
            y = coef.at(i);
            return y;
        }
    }

    //if num is not currently given in the vector
    //get which numbers it fits in between
    // a < b < c ; |c-a| minimal
    for (unsigned int i = 0; i < flight.size()-1; i++){
        if (flight.at(i) < num && num < flight.at(i+1)) {
            low = i;
            high = i + 1;
        }
    }

    //(a, f(a)), (b, f(b)), (c,f(c)); here, num = b, y = f(b)
    //interpolation equation
    // f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
    y = coef.at(low) + (((num - flight.at(low)) / (flight.at(high) - flight.at(low))) * (coef.at(high) - coef.at(low)));
 
    return y;
}


bool isOrdered(const vector<double> &flight) {
    if (flight.size() <= 1) {
        return true;  //vector with only one element is already in order
    }
    else {
        for (unsigned int i = 0; i < flight.size() - 1; i++){
            if (flight.at(i) > flight.at(i+1)) {
                return false;
            }
        }
    }
    
    return true;
}

//reorders vectors if angles aren't in ascending order
void reorder(vector<double> &flight, vector<double> &coef) {
    for (unsigned int j = 0; j < flight.size(); j++){
        //ex. if flight.at(0) is the biggest element in the vector, the following would only bring that element to the end of the vector
        //process must be repeated flight.size() amount of times to sort through entire vector
        for (unsigned int i = 0; i < flight.size() -1; i++){
            double temp;
            double ctemp;
            if (flight.at(i) > flight.at(i+1)){
                temp = flight.at(i);
                flight.at(i) = flight.at(i+1);
                flight.at(i+1) = temp;
                
                ctemp = coef.at(i);
                coef.at(i) = coef.at(i+1);
                coef.at(i+1) = ctemp;
            }
        }
    }
}

