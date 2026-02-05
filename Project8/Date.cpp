/*
This file implements the Date class.
dj5172pl Teagen Lee
13/3/2025
Dr. Jie Hu Meichsner
*/

#include "Date.h"
#include <iomanip>

using namespace std;

    /** Default constructor
     *  @pre None
     *  @post Creates an empty Date */
Date::Date() : month(0), day(0), year(0) {}

     /** Creates a date
     *  @param m the month
     *  @param d the day
     *  @param y the year
     *  @pre None
     *  @post Creates a date a month m day d and year y */
Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

	/** returns the month of the Date
	/* @pre None
	/* @post The value returned is the month of the Date.*/
int Date::getMonth() const { return month; }

    /** returns the day of the Date
	/* @pre None
	/* @post The value returned is the day of the Date.*/
int Date::getDay() const { return day; }

    /** returns the year of the Date
	/* @pre None
	/* @post The value returned is the year of the Date.*/
int Date::getYear() const { return year; }

	/** sets the month of the Date
	/* @param m is the month
	/* @pre None
	/* @post The month is set to m*/
void Date::setMonth(int m) { month = m; }

    /** sets the day of the Date
	/* @param d is the day
	/* @pre None
	/* @post The day is set to d */
void Date::setDay(int d) { day = d; }

	/** sets the year of the Date
	/* @param y is the year
	/* @pre None
	/* @post The year is set to y*/
void Date::setYear(int y) { year = y; }

	/** reads the month, day, and year and compaires it to another Date.
	 * @param other the other Date
	 * @pre None
	 * @post The month, day, and year are read and compaired to another Date. */
bool Date::operator==(const Date& other) const {
    return month == other.month && day == other.day && year == other.year;
}

    /** outputs the month, day, and year of the Date.
	 * @param os the ostream
	 * @param d is the Date that the values are coming from
	 * @post The month, day, and year are outputted */
ostream& operator<<(ostream& os, const Date& d) {
    os << d.month << " " << d.day << " " << d.year;
    return os;
}

    /** reads the month, day, and year of the Date.
	 * @param is the istream
     * @param d is the Date that the values are being assigned to
	 * @pre None
	 * @post The month, day, and year are read and set for the Date. */
istream& operator>>(istream& is, Date& d) {
    is >> d.month >> d.day >> d.year;
    return is;
}
