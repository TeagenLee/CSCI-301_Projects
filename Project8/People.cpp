/*
This file implements the People class.
Teagen Lee
13/3/2025
*/

#include "People.h"

using namespace std;

    /** Default constructor
     *  @pre None
     *  @post Creates an empty People */
People::People() : name(""), birthday() {}

     /** Creates a People
     *  @param n the name of ther person
     *  @param b the Person's birthday
     *  @pre None
     *  @post Creates a person with a name and birthday */
People::People(const string& n, const Date& b) : name(n), birthday(b) {}

	/** returns the name of the People
	/* @pre None
	/* @post The value returned is the name of People.*/
string People::getName() const { return name; }

    /** returns the Birthday of the People
	/* @pre None
	/* @post The value returned is the Birthday of People.*/
Date People::getBirthday() const { return birthday; }

	/** sets the name of the People
	/* @param n is the name
	/* @pre None
	/* @post The name is set to n*/
void People::setName(const string& n) { name = n; }

    /** sets the Birthday of the People
	/* @param b is the Birthday
	/* @pre None
	/* @post The Birthday is set to b*/
void People::setBirthday(const Date& b) { birthday = b; }


	/** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
bool People::operator==(const People& other) const {
    return name == other.name && birthday == other.birthday;
}

	/** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
bool People::operator>(const People& other) const {
    return name > other.name;
}

    /** reads the Name and Birthday and compaires it to another People.
	 * @param other the other People
	 * @pre None
	 * @post The Name and Birthday are read and compaired to another People. */
bool People::operator<(const People& other) const {
    return name < other.name;
}

    /** outputs the name and birthday of the People.
	 * @param os the ostream
	 * @param p is the People that the values are coming from
	 * @post The Name and Birthday are outputted */
ostream& operator<<(ostream& os, const People& p) {
    os << p.name << " " << p.birthday;
    return os;
}

        /** reads the month, day, and year and compaires it to another Date.
	 * @param is the istream
     * @param p is the People that the values are being assigned to
	 * @pre None
	 * @post The Name and Birthday are read and set for the People. */
istream& operator>>(istream& is, People& p) {
    string n;
    Date d;
    if (!(is >> n))
        return is;
    if (!(is >> d))
        return is;
    p.name = n;
    p.birthday = d;
    return is;
}
