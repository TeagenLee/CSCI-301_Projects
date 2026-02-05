/*
The problem I am trying to solve is creating a fraction class that has a constructer, setter and getter functions, and be
able to print the function.
Teagen Lee
9/4/2025
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    double top;
    double bottom;
    fraction f1;

    f1.setNumerator(1);
    f1.setDenominator(54);

    top = f1.getNumerator();
    bottom = f1.getDenominator();

    f1.printFraction();
    
    cout << "Proof that get functions work: " << top << "/" << bottom << endl;

    return 0;
}