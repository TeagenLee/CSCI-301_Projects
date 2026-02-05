/*
The problem I am trying to solve is being able to have a fraction class that can take values in and be able to output them.
as well as being able to add, subtract, multiply, and divide fractions together.
Teagen Lee
9/4/2025
*/

#include <iostream>
#include "newfraction2.h"
using namespace std;

int main() {
    fraction f1, f2;

    cout << "Enter the first fraction (numerator denominator): ";
    cin >> f1;

    cout << "Enter the second fraction (numerator denominator): ";
    cin >> f2;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    cout << "f1 / f2 = " << f1 / f2 << endl;

    return 0;
}