/*
The problem I am trying to solve is creating a fraction class that has a constructer, setter and getter functions, and be
able to print the function.
Teagen Lee
dj5172pl
9/4/2025
Dr. Jie Hu Meichsner
*/

#ifndef FRACTION_H
#define FRACTION_H

class fraction
{
public:
        /** Constructor; 
	* @pre None
	* @post sets the fraction to (0.0, 1.0)*/
    fraction();

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the numerator of the fraction
	/* @param numerator the numerator of the fraction
	/* @pre None
	/* @post The numerator is set to (numerator)*/
    void setNumerator(double numerator);  

	/** sets the denominator of the fraction
	/* @param denominator the denominator of the fraction
	/* @pre None
	/* @post The denominator is set to (denominator)*/  
    void setDenominator(double denominator);  
    
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

#endif