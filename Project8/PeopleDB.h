/*
This file creates the PeopleDB class.
dj5172pl Teagen Lee
Due: 12/3/2025
Dr. Jie Hu Meichsner
*/

#ifndef PEOPLE_DB_H
#define PEOPLE_DB_H

#include "BinarySearchTree.h"
#include "People.h"
#include <string>
#include <fstream>

using namespace std;

class PeopleDB {
private:
    BinarySearchTree<People> db;
public:
        /** Default constructor
    /*  @pre None
    /*  @post Creates list of People's names and birthdays */
    PeopleDB(const string& filename);

            /** MODIFICATION MEMBER FUNCTIONS*/
	/** adds a Person to the list
	/* @param p is the Person
	/* @pre None
	/* @post A vaule returned tells if the addition of the person was succesful or not*/
    bool addPerson(const People& p);      
    
    /** removes a Person to the list
	/* @param p is the Person
	/* @pre None
	/* @post A vaule returned tells if the removal of the person was succesful or not*/
    bool removePerson(const People& p);  
        
    /** removes a Person by name to the list
	/* @param name is the Person's name
	/* @pre None
	/* @post A vaule returned tells if the removal of the person by name was succesful or not*/              
    bool removePersonByName(const string& name);  

    /** modifies a Person in the list
	/* @param oldP is the original Person
	/* @param newP is the modified Person
	/* @pre None
	/* @post A vaule returned tells if the modification of the person was succesful or not*/     
    bool modifyPerson(const People& oldP, const People& newP);

        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns t/f depending on if it found the person
    /*  @param p the person you are trying to find
    /*  @param found the if you found the person.
	/* @pre None
	/* @post The value returned is t/f depending on if it found the person.*/
    bool searchPerson(const People& p, People& found) const;  

    /** returns t/f depending on if it found the person by name
    /*  @param name the person you are trying to find by name
    /*  @param found the if you found the person by name.
	/* @pre None
	/* @post The value returned is t/f depending on if it found the person by name.*/
    bool searchPersonByName(const string& name, People& found) const; 

    /** diaplays the people in the order they were put into the list
	/* @pre None
	/* @post Diaplays the people in the order they were put into the list.*/
    void displayPreorder() const;
    
    /** diaplays the people in alphabetic order
	/* @pre None
	/* @post Diaplays the people in alphabetic order.*/
    void displayInorder() const;  

    /** creates a file that has the new list in it.
    /*  @param outFilename the people put into the file
	/* @pre None
	/* @post A file is created with all of the people in it.*/
    void saveToFile(const string& outFilename) const;
};

#include "PeopleDB.cpp"
#endif
