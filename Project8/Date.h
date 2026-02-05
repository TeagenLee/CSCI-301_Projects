/*
This file creates the Date class.
dj5172pl Teagen Lee
Due: 12/3/2025
Dr. Jie Hu Meichsner
*/


#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
public:

            /** Constructor; 
    /** Default constructor
     *  @pre None
     *  @post Creates an empty Date */
    Date();

     /** Creates a date
     *  @param m the month
     *  @param d the day
     *  @param y the year
     *  @pre None
     *  @post Creates a date a month m day d and year y */
    Date(int m, int d, int y);

    
        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the month of the Date
	/* @pre None
	/* @post The value returned is the month of the Date.*/
    int getMonth() const;

    /** returns the day of the Date
	/* @pre None
	/* @post The value returned is the day of the Date.*/
    int getDay() const;

    /** returns the year of the Date
	/* @pre None
	/* @post The value returned is the year of the Date.*/
    int getYear() const;

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the month of the Date
	/* @param m is the month
	/* @pre None
	/* @post The month is set to m*/
    void setMonth(int m);

    /** sets the day of the Date
	/* @param d is the day
	/* @pre None
	/* @post The day is set to d */
    void setDay(int d);
    
	/** sets the year of the Date
	/* @param y is the year
	/* @pre None
	/* @post The year is set to y*/
    void setYear(int y);


        /**Nonmember function */
	/** reads the month, day, and year and compaires it to another Date.
	 * @param other the other Date
	 * @pre None
	 * @post The month, day, and year are read and compaired to another Date. */
    bool operator==(const Date& other) const;

    /** outputs the month, day, and year of the Date.
	 * @param os the ostream
	 * @param d is the Date that the values are coming from
	 * @post The month, day, and year are outputted */
    friend ostream& operator<<(ostream& os, const Date& d);
    
    /** reads the month, day, and year of the Date.
	 * @param is the istream
     * @param d is the Date that the values are being assigned to
	 * @pre None
	 * @post The month, day, and year are read and set for the Date. */
    friend istream& operator>>(istream& is, Date& d);
};

#include "Date.cpp"
#endif
