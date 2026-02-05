// Creates and defines the ShaoppingCart class
// Teagen Lee
// 9/22/2025

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "Bag.h"
#include "item.h"

class ShoppingCart : public Bag<item> 
{

    public:
        /** Constructors; 
    /* @pre None
    /* @post initializes the shopping cart */
    ShoppingCart();

        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the total price of the items in the shopping cart
	/* @pre None
	/* @post The value returned is the total price of the items in the shopping cart.*/
    double getTotalPrice() const;

        /**Nonmember function */
	/** Adds a new item to the shopping cart
	 * @param newEntry the item being added to the shopping cart
	 * @pre None
	 * @post It returns a bool on if it was successful or not trying to add an item.*/
    bool add(const item& newEntry) override;

    /** Removes an item to the shopping cart
	 * @param anEntry the item being removed to the shopping cart
	 * @pre None
	 * @post It returns a bool on if it was successful or not trying to removes the item.*/
    bool remove(const item& anEntry) override;

    /** Clears shopping cart and sets totalPrice to zero
	 * @pre None
	 * @post The shopping cart is empty and totalPrice is equal to zero.*/
    void clear() override;

    private:
    /** the total price of all the items in the shopping cart */
    double totalPrice;
}; // end of class

#include "ShoppingCart.cpp"

#endif
