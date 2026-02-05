/*
The problem I am trying to solve is being able to have a fraction class that can take values and be able to output them.
as well as being able to add, subtract, multiply, and divide fractions together.
Teagen Lee
9/4/2025
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class fraction {
public:
      /** Constructor;
	/** 
	* @param num the fraction's numerator
	* @param den the fration's denominator
	* @pre None
	* @post sets the fraction to (num, den)*/
    fraction(double num, double den);

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the numerator of the fraction
	/* @param numerator the numerator of the fraction
	/* @pre None
	/* @post The numerator is set to (numerator)*/
    void changeNumerator(double numerator);  

	/** sets the denominator of the fraction
	/* @param denominator the denominator of the fraction
	/* @pre None
	/* @post The denominator is set to (denominator)*/  
    void changeDenominator(double denominator);  
    
        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the numerator of the fraction
	/* @pre None
	/* @post The value returned is the numerator of the fraction.*/
    double getNumerator() const;
    
	/** returns the denominator of the fraction
	/* @pre None
	/* @post The value returned is the denominator of the fraction.*/    
    double getDenominator() const;

        
        /** Print MEMBER FUNCTIONS*/
	/** displays the fraction
	/* @pre None
	/* @post The fraction is displayed.*/
    void printFraction();

private:
    /** the numerator of the fraction*/
    double numerator;

    /** the denominator of the fraction*/
    double denominator;
};

/** NONMEMBER FUNCTIONS for the point class */

	/**  Arithmetic operators */
/** computes the sum of f1 and f2
	/* @param f1 the first fraction of the equation
	/* @param f2 the second fraction of the equation
	/* @pre None
	/* @post f1 is added to f2*/
fraction operator+(const fraction& f1, const fraction& f2);

/** computes the difference of f1 and f2
	/* @param f1 the first fraction of the equation
	/* @param f2 the second fraction of the equation
	/* @pre None
	/* @post f1 is subtracted by f2*/
fraction operator-(const fraction& f1, const fraction& f2);

/** computes the product of f1 and f2
	/* @param f1 the first fraction of the equation
	/* @param f2 the second fraction of the equation
	/* @pre None
	/* @post f1 is multiplied by f2*/
fraction operator*(const fraction& f1, const fraction& f2);

/** computes the division of f1 and f2
	/* @param f1 the first fraction of the equation
	/* @param f2 the second fraction of the equation
	/* @pre None
	/* @post f1 is divided by f2*/
fraction operator/(const fraction& f1, const fraction& f2);

	/** Stream output operator*/
/** writes the fraction out onto the screen
	/* @param os the outstream 
	/* @param f the fraction that will be displayed 
	/* @pre None
	/* @post The numerator is set to (numerator)*/
ostream& operator<<(ostream& os, const fraction& f);

#endif
