#include <iostream>
#include "Distance.h"

using namespace std;

//default distance
Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;

    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;

    init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return (feet * 12) + inches;
}

double Distance::distanceInFeet() const {
    return (inches / 12) + feet;
}

// 1 inch = 0.0254 meters
double Distance::distanceInMeters() const {
    return ((feet * 12.0) + inches) * 0.0254;
}

Distance Distance::operator+ (const Distance &rhs) const {
    unsigned int fTemp = 0;
    double iTemp;

    fTemp = feet + rhs.feet;
    iTemp = inches + rhs.inches;

    Distance distance(fTemp, iTemp);

    return distance;
}

Distance Distance::operator- (const Distance &rhs) const {
    Distance distance;

    if (rhs.feet > feet) {
        distance.feet = rhs.feet - feet;
        distance.inches = rhs.inches - inches;
    }
    else {
        distance.feet = feet - rhs.feet;
        distance.inches = inches - rhs.inches;
    }

    if (distance.inches < 0.0) {
        distance.feet = distance.feet - 1;
        distance.inches = distance.inches + 12.0;
    }

    return distance;
}

ostream &operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {

    if (inches < 0.0) {
        inches = abs(inches);
    }

    while (inches >= 12.0) {
        feet += 1;
        inches -= 12.0;
    }
}