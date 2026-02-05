/*
The problem I am trying to solve is creating a fraction class that has a constructer, setter and getter functions, and be
able to print the function.
Teagen Lee
dj5172pl
*/

#include <iostream>   
#include "fraction.h"

using namespace std;

fraction::fraction() {
    numerator = 0.0;    // Constructer sets fraction with default values
    denominator = 1.0;  
}

void fraction::setNumerator(double num) {  
    numerator = num; // allows user to set the numerator
}

void fraction::setDenominator(double den) { 
    denominator = den; // allows user to set the denominator
}

double fraction::getNumerator() const {
    return numerator; 
}

double fraction::getDenominator() const {
    return denominator;
}

void fraction::printFraction() {
    cout << numerator << "/" << denominator << endl; // prints vaules as a fraction
}