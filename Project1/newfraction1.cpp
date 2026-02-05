/*
The problem I am trying to solve is being able to have a fraction class that can take values and be able to output them.
as well as being able to add, subtract, multiply, and divide fractions together.
Teagen Lee
9/4/2025
*/

#include "newfraction1.h"
using namespace std;

fraction::fraction(double num, double den) {
    numerator = num;
    denominator = (den == 0 ? 1.0 : den);
}

void fraction::changeNumerator(double num) {
    numerator = num; 
}

void fraction::changeDenominator(double den) { 
    denominator = (den == 0 ? 1.0 : den); 
}

double fraction::getNumerator() const { 
    return numerator; 
}

double fraction::getDenominator() const { 
    return denominator; 
}

void fraction::printFraction() {
    cout << numerator << "/" << denominator;
}

// Operator overloads
fraction operator+(const fraction& f1, const fraction& f2) {
    if (f1.getDenominator() == f2.getDenominator()) {
        // Denominators are the same, just add numerators
        return fraction(f1.getNumerator() + f2.getNumerator(), f1.getDenominator());
    } else {
        // Denominators are different, cross-multiply
        return fraction(f1.getNumerator() * f2.getDenominator() +
                        f2.getNumerator() * f1.getDenominator(),
                        f1.getDenominator() * f2.getDenominator());
    }
}

fraction operator-(const fraction& f1, const fraction& f2) {
    if (f1.getDenominator() == f2.getDenominator()) {
        // Same denominator, just subtract numerators
        return fraction(f1.getNumerator() - f2.getNumerator(), f1.getDenominator());
    } else {
        // Different denominators, cross-multiply
        return fraction(f1.getNumerator() * f2.getDenominator() -
                        f2.getNumerator() * f1.getDenominator(),
                        f1.getDenominator() * f2.getDenominator());
    }
}

fraction operator*(const fraction& f1, const fraction& f2) {
    return fraction(f1.getNumerator() * f2.getNumerator(),
                    f1.getDenominator() * f2.getDenominator());
}

fraction operator/(const fraction& f1, const fraction& f2) {
    return fraction(f1.getNumerator() * f2.getDenominator(),
                    f1.getDenominator() * f2.getNumerator());
} 

ostream& operator<<(ostream& os, const fraction& f) {
    os << f.getNumerator() << "/" << f.getDenominator();
    return os;
}
