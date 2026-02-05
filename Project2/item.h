// Creates and defines the item class
// dj5172pl Teagen Lee
// 9/22/2025
// Dr. Jie Hu Meichsner

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;


class item 
{
    public:
        /** Constructors; 
	/* @pre None
	/* @post sets the item to (Blank, 0.0, 0)*/
    item();
 
	/**
    /* @param n stores the name of the item
    /* @param p stores the price of the item
    /* @param  q stores the quantity of the item
    /* @pre None
	/* @post sets the item to (n, p, q)*/
    item(string n, double p, int q);

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the name of the item
	/* @param n the name of the item
	/* @pre None
	/* @post The name is set to (n)*/
    void setName(string n);

    /** sets the price of the item
	/* @param p the price of the item
	/* @pre None
	/* @post The price is set to (p)*/
    void setUnitPrice(double p);

    /** sets the quantity of the item
	/* @param q the quantity of the item
	/* @pre None
	/* @post The quantity is set to (q)*/
    void setQuantity(int q);

        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the name of the item
	/* @pre None
	/* @post The value returned is the name of the item.*/
    string getName() const;

	/** returns the price of the item
	/* @pre None
	/* @post The value returned is the price of the item.*/
    double getUnitPrice() const;

	/** returns the quantity of the item
	/* @pre None
	/* @post The value returned is the quantity of the item.*/
    int getQuantity() const;

        /**Nonmember function */
	/** reads the name, price, and quantity of the item
	 * @param is the istream
     * @param i is the item that the values are being assigned to
	 * @pre None
	 * @post The name, price, and quantity are read and set for the item. */
    friend istream& operator >>(istream& is, item& i);

    /** outputs the name, price, and quantity of the item
	 * @param os the ostream
     * @param i is the item that the values are coming from
	 * @pre None
	 * @post The name, price, and quantity are outputted. */
    friend ostream& operator<<(ostream& os, const item& i);

	/** chechs the name, price, and quantity of two different items and compares them
	 * @param a is the first item that the values are being compared to
     * @param b is the second item that the values are being compared to
	 * @pre None
	 * @post The name, price, and quantity are compared for both items, and depending on if they match or not a true or false is returned. */
    friend bool operator==(const item& a, const item& b);
    

    private:
    /** the name of the item */
    string name;

    /** the unit price of the item */
    double unitPrice;

    /** the quantity of the item */
    int quantity;
}; // end of class

#include "item.cpp"

#endif