#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here
Rational::Rational(int num, int den) {
this->numerator = num;
this->denominator = den;
}

Rational::Rational(int num) {
this->numerator = num;
this->denominator = 1;
}

Rational::Rational(){
this->numerator = 0;
this->denominator = 1;
}

Rational Rational::add(const Rational& w) const {
//(a/b) + (c/d) = (ad + bc) / (b*d)
int a = (numerator * w.denominator) + (denominator * w.numerator);
int b = denominator * w.denominator;
Rational temp(a,b);
return temp;
}

Rational Rational::subtract(const Rational &w) const {
//(a/b) - (c/d) = (ad - bc) / (b*d)
int a = (numerator * w.denominator) - (denominator * w.numerator);
int b = denominator * w.denominator;
Rational temp(a,b);
return temp;
}

Rational Rational::multiply(const Rational &w) const {
//(a/b) * (c/d) = (ac) / (bd)
int a = numerator * w.numerator;
int b = denominator * w.denominator;
Rational temp(a,b);
return temp; 
}

Rational Rational::divide(const Rational &w) const {
//(a/b) / (c/d) = (ad) / (cb)
//dividing fractions = multiply by reciprocal
int a = numerator * w.denominator;
int b = denominator * w.numerator;
Rational temp(a,b);
return temp; 
}

int Rational::gcd(int a,int b) const {
   if (b == 0) {
     return a;
   } 
   else{
      return gcd(b, a % b);
   }
}

void Rational::simplify(){
   int GCD = gcd(numerator, denominator);
   numerator /= GCD;
   denominator /= GCD;
}

void Rational::display() const {
   cout << this->numerator << " / " << this->denominator; 
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}