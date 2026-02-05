/*
The problem I am trying to solve is being able to have a fraction class that can take values and be able to output them.
as well as being able to add, subtract, multiply, and divide fractions together.
Teagen Lee
dj5172pl
9/4/2025
Dr. Jie Hu Meichsner
*/

#include <iostream>
#include "newfraction1.h"
using namespace std;

int main() {
    double numerator, denominator;

    cout << "Enter the first fraction: numerator denominator" << endl;
    cin >> numerator >> denominator;
    fraction f1(numerator, denominator);

    cout << "Enter the second fraction: numerator denominator" << endl;
    cin >> numerator >> denominator;
    fraction f2(numerator, denominator);

    cout << "The two fractions entered are:" << endl;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << endl;

    cout << "Arithmetic operations:" << endl;
    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    cout << "f1 / f2 = " << f1 / f2 << endl;

    return 0;
}
