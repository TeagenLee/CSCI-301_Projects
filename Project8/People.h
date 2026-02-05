/*
This file creates the People class.
Teagen Lee
Due: 12/3/2025
*/


#ifndef PEOPLE_H
#define PEOPLE_H

#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

class People {
private:
    string name; 
    Date birthday;
public:

        /** Constructor; 
    /** Default constructor
     *  @pre None
     *  @post Creates an empty People */
    People();

     /** Creates a People
     *  @param n the name of ther person
     *  @param b the Person's birthday
     *  @pre None
     *  @post Creates a person with a name and birthday */
    People(const string& n, const Date& b);

        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the name of the People
	/* @pre None
	/* @post The value returned is the name of People.*/
    string getName() const;

    /** returns the Birthday of the People
	/* @pre None
	/* @post The value returned is the Birthday of People.*/
    Date getBirthday() const;

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the name of the People
	/* @param n is the name
	/* @pre None
	/* @post The name is set to n*/
    void setName(const string& n);

    /** sets the Birthday of the People
	/* @param b is the Birthday
	/* @pre None
	/* @post The Birthday is set to b*/
    void setBirthday(const Date& b);

        /**Nonmember function */
	/** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
    bool operator==(const People& other) const;

	/** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
    bool operator>(const People& other) const;

    /** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
    bool operator<(const People& other) const;

    /** outputs the name and birthday of the People.
	 * @param os the ostream
	 * @param p is the People that the values are coming from
	 * @post The Name and Birthday are outputted */
    friend ostream& operator<<(ostream& os, const People& p);

        /** reads the month, day, and year and compaires it to another Date.
	 * @param is the istream
     * @param p is the People that the values are being assigned to
	 * @pre None
	 * @post The Name and Birthday are read and set for the People. */
    friend istream& operator>>(istream& is, People& p);
};

#include "People.cpp"
#endif
