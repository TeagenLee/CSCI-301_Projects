/*
This file implements the PeopleDB class.
dj5172pl Teagen Lee
13/3/2025
Dr. Jie Hu Meichsner
*/

#include "PeopleDB.h"
#include <fstream>
#include <iostream>
#include <functional>

using namespace std;


static ofstream fsOut;


void toScreen(People& p) {
    cout << p << endl;
}

void toFile(People& p) {
    if (fsOut.is_open())
        fsOut << p << endl;
}


    /*  @pre None
    /*  @post Creates list of People's names and birthdays */
PeopleDB::PeopleDB(const string& filename) {

    ifstream in(filename);
    if (!in) {
        cerr << "Warning: Cannot open input file '" << filename << "'. Starting with empty DB.\n";
        return;
    }

    People p;
    while (in >> p) {
        db.add(p);
    }
    in.close();
}

	/** adds a Person to the list
	/* @param p is the Person
	/* @pre None
	/* @post A vaule returned tells if the addition of the person was succesful or not*/
bool PeopleDB::addPerson(const People& p) {
    People existing;
    if (searchPersonByName(p.getName(), existing))
        return false;
    db.add(p);
    return true;
}

    /** removes a Person to the list
	/* @param p is the Person
	/* @pre None
	/* @post A vaule returned tells if the removal of the person was succesful or not*/
bool PeopleDB::removePerson(const People& p) {
    return db.remove(p);
}

    /** removes a Person by name to the list
	/* @param name is the Person's name
	/* @pre None
	/* @post A vaule returned tells if the removal of the person by name was succesful or not*/ 
bool PeopleDB::removePersonByName(const string& name) {
    bool removed = false;
    People key(name, Date(0,0,0));
    try {
        People found = db.getEntry(key);
    } catch (...) {
    }

    struct Finder {
        string name;
        People result;
        bool found;
        Finder(const string& n): name(n), found(false) {}
        static void visit(People& p, Finder* f) {
            if (!f->found && p.getName() == f->name) {
                f->result = p;
                f->found = true;
            }
        }
    } finder(name);

    static Finder* gFinder = nullptr;
    gFinder = &finder;
    auto findWrapper = [](People& p) {
        Finder* f = gFinder;
        if (f && !f->found && p.getName() == f->name) {
            f->result = p;
            f->found = true;
        }
    };
    db.inorderTraverse([](People& p){
        extern PeopleDB* __dummy;
    });  
    
    struct NameFinder {
        string name;
        People result;
        bool found;
    };
    static NameFinder* gnf = nullptr;
    NameFinder nf{ name, People(), false };
    gnf = &nf;
    auto nameFindFunc = [](People& p) {
        if (gnf && !gnf->found && p.getName() == gnf->name) {
            gnf->result = p;
            gnf->found = true;
        }
    };

    const string tmpName = "__tempscan__.txt";
    {
        ofstream tmp(tmpName, ios::trunc);
        if (!tmp) return false;
        fsOut.close();
        fsOut.clear();
        fsOut.copyfmt(tmp);
    }

    static NameFinder* globalNameFinder = nullptr;
    globalNameFinder = &nf;
    auto nameFinderFunc = [](People& p) {
        NameFinder* f = globalNameFinder;
        if (f && !f->found && p.getName() == f->name) {
            f->result = p;
            f->found = true;
        }
    };
    db.preorderTraverse(nameFinderFunc);
    if (!nf.found) return false;
    return db.remove(nf.result);
}

    /** modifies a Person in the list
	/* @param oldP is the original Person
	/* @param newP is the modified Person
	/* @pre None
	/* @post A vaule returned tells if the modification of the person was succesful or not*/ 
bool PeopleDB::modifyPerson(const People& oldP, const People& newP) {
    if (!db.remove(oldP))
        return false;
    db.add(newP);
    return true;
}

	/** returns t/f depending on if it found the person
    /*  @param p the person you are trying to find
    /*  @param found the if you found the person.
	/* @pre None
	/* @post The value returned is t/f depending on if it found the person.*/
bool PeopleDB::searchPerson(const People& p, People& found) const {
    try {
        People got = db.getEntry(p);
        found = got;
        return true;
    } catch (...) {
        return false;
    }
}

    /** returns t/f depending on if it found the person by name
    /*  @param name the person you are trying to find by name
    /*  @param found the if you found the person by name.
	/* @pre None
	/* @post The value returned is t/f depending on if it found the person by name.*/
bool PeopleDB::searchPersonByName(const string& name, People& found) const {
    struct NF { string name; People result; bool found; };
    static NF* gNF = nullptr;
    NF nf{ name, People(), false };
    gNF = &nf;
    auto f = [](People& p) {
        NF* ptr = gNF;
        if (ptr && !ptr->found && p.getName() == ptr->name) {
            ptr->result = p;
            ptr->found = true;
        }
    };
  
    db.preorderTraverse(f);
    if (nf.found) {
        found = nf.result;
        return true;
    }
    return false;
}

    /** diaplays the people in the order they were put into the list
	/* @pre None
	/* @post Diaplays the people in the order they were put into the list.*/
void PeopleDB::displayPreorder() const {
    db.preorderTraverse(toScreen);
}

    /** diaplays the people in alphabetic order
	/* @pre None
	/* @post Diaplays the people in alphabetic order.*/
void PeopleDB::displayInorder() const {
    db.inorderTraverse(toScreen);
}

    /** creates a file that has the new list in it.
    /*  @param outFilename the people put into the file
	/* @pre None
	/* @post A file is created with all of the people in it.*/
void PeopleDB::saveToFile(const string& outFilename) const {
    fsOut.close();
    fsOut.clear();
    fsOut.open(outFilename, ios::trunc);
    if (!fsOut) {
        cerr << "Error: cannot open output file '" << outFilename << "' for writing.\n";
        return;
    }
    db.preorderTraverse(toFile); 
    fsOut.close();
}
