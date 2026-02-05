/*
The problem I am trying to solve is being able to have a fraction class that can take values in and be able to output them.
as well as being able to add, subtract, multiply, and divide fractions together.
Teagen Lee
dj5172pl
9/4/2025
Dr. Jie Hu Meichsner
*/

#include "newfraction2.h"
using namespace std;

fraction::fraction() {
    numerator = 0.0;
    denominator = 1.0;
}

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

istream& operator>>(istream& is, fraction& f) {
    double num, den;
    is >> num >> den;
    f.numerator = num;
    f.denominator = (den == 0 ? 1.0 : den); // Avoid zero denominator
    return is;
}

fraction fraction::operator+(const fraction& f2) const {
    if (denominator == f2.denominator) {
        // Same denominator, just add numerators
        return fraction(numerator + f2.numerator, denominator);
    } else {
        // Different denominators, cross-multiply
        return fraction(numerator * f2.denominator + f2.numerator * denominator,
                        denominator * f2.denominator);
    }
}

fraction fraction::operator-(const fraction& f2) const {
    if (denominator == f2.denominator) {
        // Same denominator, just subtract numerators
        return fraction(numerator - f2.numerator, denominator);
    } else {
        // Different denominators, cross-multiply
        return fraction(numerator * f2.denominator - f2.numerator * denominator,
                        denominator * f2.denominator);
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
